import os
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
            #Esta acción se encarga de transformar archivos de vhdl a .bit
            'vhdl_to_bit' : '',
            'charge_bit' : ''
        }
        self.dict_action_server_errors = [ #Lista para posibles errores
            'Unexpected error.',
            'Infrastructure error, microcontroller not found.',
            'Device port not found.',
            'File not found.'
        ]

    def send_feedback(self,feedback_msg):
        self.feedback_msg.status = feedback_msg#Establece el attribute del feedback
        self.goal_handle.publish_feedback(self.feedback_msg)#Envia el feedback

    def execute_goal(self, goal_handle): #Método llamado desde la instancia para comenzar la goal
        self.feedback_msg = self.action_type.Feedback()#Guarda el feedback de la action
        self.goal_handle = goal_handle#Guarda goal_handle
        self.send_feedback('Goal received')#El servidor acepta la tarea

    def execute_command(self, command_name, port = None, file_path = None, constrain_path = None):
        try:#*Función para ejecutar los comando del diccionario según el nombre
            #Ejecuta el comando en base al command_name que haya sido pasado en los parámetros
            command_template = self.dict_action_server[command_name]
            #Formatea los parametros en el comando
            command = command_template.format(port=port, file_path=file_path, constrain_path=constrain_path)
            self.send_feedback('Executing command')#Feedback para mostrar el progreso         

            command_r = os.popen(command).read()#Ejecución del comando y lectura de resultados
            self.send_feedback('Command executed successfully') #Feedback de que la acción se completo con éxito
           
            self.goal_handle.succeed()#Marca la tarea como completada
            self.result.status_final = 'Command executed successfully' #Publica el status de la tarea        
        except:
            
            self.send_feedback('Execution failed.')
            self.callback_error(err=1)#El feedback será reasignado en la funcion callback_error
        finally:
            #En ambos casos crea y publica el mensaje del auditor
            NodeFather.auditor_msg(self, logprocess=self.result.status_final)

    def callback_error(self,err=0):#Al llamar se pasa como argumento el tipo de error
        #*Para cuando no se encuentran los archivos (.hex, .bit, .vhdl) o hay algún error
        
        self.goal_handle.abort()#Aborta la tarea
        #Busca el tipo de error segun el nombre de la acción
        self.result.status_final = self.dict_action_server_errors[err]

        #Publica en exit_logger el status final
        NodeFather.publisher_consoler(self,self.result.status_final, 'Status')

        #Publica el status de la operacion en el nodo auditor
        NodeFather.auditor_msg(self,self.result.status_final)