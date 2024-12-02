import subprocess
from .node_father import NodeFather
from rclpy.action import ActionServer

class ActionParentServer:
    def __init__(self, action_type, action_name):
        #Crea el servidor de la acción y nombre de acción dados en los parámetros
        self._action_server = ActionServer(self, action_type,action_name,self.execute_callback)
        self.action_type = action_type#Guarda el tipo de acción
        self.action_name = action_name#Guarda el nombre de la acción
        self.result = self.action_type.Result()#Inicializa el Result del tipo de acción
        self.dict_action_server = { #Diccionario de comandos a ejecutar
            # * Aquí se pueden agregar más placas/microcircuito en el futuro
            #Comando para programar placas arduino
            'arduino': "avrdude -c arduino -P {port} -b 115200 -p atmega328p -D -U flash:w:{file_path}",
            #! Aún no tienen la VHDL
            #Esta acción se encarga de transformar archivos de vhdl a .bit --- FPGA
            'vhdl_to_bit' : 'vivado -mode batch -source s-compile.tcl -tclargs {vhdl_path} {constrain_path}',
            #Esta acción carga el .bit (Va encadenada con la otra acción)
            # TODO: Tal vez se pueda combinar en un solo comando
            'charge_bit' : 'openFPGALoader -b xc7z010 {path_bitstream}',
            #Carga el archivo .bin en la esp-32
            #TODO: Instalar esptool
            'esp32': 'esptool.py --port {port} write_flash 0x1000 {file_path}',
            #Prueba para rasperry. Ejemplo: rshell -p /dev/ttyACM0 cp main.py /pyboard/
            'rasperry' : 'rshell -p {port} cp {file_path} /pyboard/'
        }

    def available_port(self,port_name): #Recibe el nombre personalizado del puerto (Modificación de reglas de los nombres de los puertos
        #* El archivo debe de estar bien configurado con los nombres personalizados
        try:
            #Utiliza el subprocess para que cuando lance exception retorne false
            port = subprocess.check_output(f"ls -l {port_name}",shell=True,text=True) #Guarda el resultado
            port = port[(port).find('/'):] #Busca el indice donde inicia '/' y lo corta de ahí en adelante
            
            NodeFather.publisher_consoler(self,port,'USB Custom name')#Publica el puerto real
            return True #Si no hay error, retorna True (Sí encontró el puerto)
        
        except subprocess.CalledProcessError as e: #Error en la ejecución del comando
            NodeFather.publisher_consoler(self,f'Failed Execution. {e}','Error')
            return False #Este return lanzará la otra exception (personalizada)
        
        except Exception as e: #Cualquier error en la ejecución
            NodeFather.publisher_consoler(self,f'Unexpected error. {e}','Error')
            return False

    def send_feedback(self,feedback_msg):
        self.feedback_msg.status = feedback_msg#Establece el attribute del feedback
        self.goal_handle.publish_feedback(self.feedback_msg)#Envia el feedback

    def execute_goal(self, goal_handle): #Método llamado desde la instancia para comenzar la goal
        self.feedback_msg = self.action_type.Feedback() #Guarda el feedback de la action
        self.goal_handle = goal_handle #Guarda goal_handle

    def execute_command(self, command_name, port=None, file_path=None, constrain_path=None):
        try:#*Función para ejecutar los comando del diccionario según el nombre
            #Ejecuta el comando en base al command_name que haya sido pasado en los parámetros
            command_template = self.dict_action_server[command_name]
            #Formatea los parametros en el comando
            command = command_template.format(port=port, file_path=file_path, constrain_path=constrain_path)
            self.send_feedback('Executing command')#Feedback para mostrar el progreso         

            subprocess.check_output(command,shell=True,text=True)#Ejecución del comando, usar este módulo para manejo de excepciones
            self.send_feedback('Command executed successfully') #Feedback de que la acción se completo con éxito
           
            self.goal_handle.succeed()#Marca la tarea como completada
            self.result.status_final = 'Command executed successfully' #Publica el status de la tarea        
        
        except subprocess.CalledProcessError as e: #Error en la ejecución del comando
            self.callback_error(e)
        except Exception as e:
            self.callback_error(e)#El feedback será reasignado en la funcion callback_error
        #Ya no se envia al auditor desde aquí, sino desde el client

    def callback_error(self,e='Unexpected error'):#Al llamar se pasa como argumento el tipo de error
        #Para cuando no se encuentran los archivos (.hex, .bit, .vhdl) o hay algún error
        self.goal_handle.abort()#Aborta la tarea
        self.result.status_final = str(e)#Busca el tipo de error segun el nombre de la acción