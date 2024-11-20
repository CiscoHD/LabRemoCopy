import rclpy 
#Mensaje personalizado con la información de los nodos
from rclpy.action import ActionClient, ActionServer
from pvariables.msg import Operation, Auditor, LogExit
from datetime import datetime 
import pandas as pd, sqlite3, os

class NodeConn:
    #Definir como false o True según si está en produccion (api) o en desarrollo (sqlite)
    def __init__(self, url='/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db', dev = False): #Por defecto en producción
        self.mode_dev = dev #Hay que enviar argumento como True para entrar en modo dev
        self.url = url
        #Diccionario para cada sentencia usada para comunicarse a base de datos
        self.diction_db = {
            # * ----------------- Agregué el topic code a la sentencia de supervisor
            
            "supervisor" : """INSERT INTO SUPERVISOROPERACIONES( nameoperacion, DescOperacion, EstatusOperacion, FechaOperacion, TopicOperacion) VALUES (?, ?, ?, ?, ?);""",
            "auditor" : """INSERT INTO TRANSACCIONESAUDITOR (IdNode, NameNode, TipoTransaccion, FechaTransaccion, IdUser, LogProceso) VALUES (?, ?, ?, ?, ?, ?);""",
            "admin" : """ SELECT * FROM CONTRATOS WHERE IdContrato = ?;""",
            "input_transactioner" : """ SELECT * FROM USUARIOS WHERE Id = ?;"""
        }
        self.diction_db_errors = {
            # * Poner los errores
            # Type error | Descr error
            "default": ('Database Error', 'Database error, try again.'),
            "admin" : ('Transaction Error', 'Transaction not found.'),
            "admin_condition": ('Transaction Error', 'Transaction Rejected.'),
            "input_transactioner" : ('Transaction Error',"Transaction cannot be processed")
        }
        
    def connection(self):
        if self.mode_dev:
            try:
                conn = sqlite3.connect(self.url)
                cur = conn.cursor()
            except sqlite3.Error as e:
                return None, 'Error in database connection.'
            return conn,cur
        # ------------------------ API ------------------------------

    def insert_log_db(self, tuple_db, sentence): #Tuple_db se pasa como tupla con toda la info del mensaje
        if self.mode_dev:
            conn,cur = self.connection()
            if conn is not None:
                msg = ('Success')
                try:
                    #Busca la sentencia correspondiente en el diccionario
                    sentence_db = self.diction_db.get(f"{sentence}")
                    #Ejecuta la sentencia con los datos de la tupla
                    cur.execute(sentence_db, tuple_db)
                except(sqlite3.Error):
                    #Regresa el mensaje en caso de error
                    msg = self.diction_db_errors.get("default")
                finally:
                    #Al final, cierra el cursor y la conexión
                    conn.commit()
                    cur.close()
                    conn.close()
                    return msg
                
    def request_info_db(self, sentence, conditional_id):
        if self.mode_dev:
            conn,cur = self.connection()
            data = None
            if conn is not None:
                msg = ('Transaction Accepted')
                try:
                    #Busca la sentencia correspondiente en el diccionario
                    sentence_db = self.diction_db.get(f"{sentence}")
                    #Ejecuta la sentencia con los datos de la tupla
                    
                    sentence_2 = "SELECT * FROM CONTRATOS WHERE IdContrato = ?;"
                    n_contracts = 0
                    for contract in cur.execute(sentence_db, (conditional_id,)):
                        print(contract)
                        n_contracts = n_contracts +1
                    #Si viene desde el nodo administrator y no hay resultados
                    if n_contracts  < 1:
                        #Asigna error por defecto buscando en el diccionario
                        msg = self.diction_db_errors.get(f"{sentence_db}") 
                        #Asigna otro tipo de error según una condición
                        # ! Falta desarrollar las condiciones para que sea una transacción aceptada
                        #Comunicación con el backend, a través de ROS BRIDGE se recibe las operaciones y el certificado
                        #Enviar al back y esperar TRUE or FALSE
                        # TODO Hacer la función de verificación de contratos
                    #Condicion en caso de que solo la sentencia caso admin encuentre contratos
                    #if (sentence_db == "admin" and n_contracts>0) or True == True:                        #Busca los errores del admin en la condition por desarrollar
                    else:
                        #!regresa el mensaje  #! Hay que revisar lo que devuelve la BBDD
                        #! Mensaje provicional para pruebas
                        data = {'result' : 'Pruebas', 'status' : 'accepted', 'name_node' : '', 'date' : 'TimeActual', 'folio' : 'Assigned by BBDD' }
                        #msg = self.diction_db_errors.get(f"{sentence_db}_condition")
                except(sqlite3.Error):
                    #Regresa el mensaje en caso de error
                    msg = self.diction_db_errors.get("default")
                finally:
                    #Al final, cierra el cursor y la conexión
                    conn.commit()
                    cur.close()
                    conn.close()
                    return msg, data

class NodeFather:
    def __init__(self, topic=None):
        self.topic_code = self.get_code_tema(topic)
        
    def get_code_tema(self,topic, path='/home/laboratorio_remo_remasterizado/labremoto/files/topics.csv'):
        try:
            df = pd.read_csv(path)
            filtered_df = df[df['topic'] == topic]

            # Verificar si el DataFrame filtrado está vacío
            if filtered_df.empty:
                raise ValueError(f"Topic '{topic}' not found.")

            # Si no está vacío, obtener el código del tema
            topic_code = 'topic_' + str(filtered_df.iloc[0]['code_topic'])
            return topic_code
        except ValueError as err:
            print(err)
    
    def initialization_notice(self):
        msg = Operation()
        msg.name_operation =  "Start Node"
        msg.desc_operation = f"{self.get_name()}"
        msg.status_operation = "Started"
        msg.date_operation = f"{datetime.now()}"
        msg.topic_operation = f"{self.topic_code}"

        topic = self.get_code_tema('top_supervisor_operations')
        self.create_publisher(Operation, topic, 10).publish(msg)

    def auditor_msg(self, logprocess="", idnote=0, iduser="", typetransaction=""):
        #Crea un publisher para el topic y message de Auditor
        self.publisher_auditor_ = self.create_publisher(Auditor, self.get_code_tema('top_auditor_transactions'),10)
        #Crea el mensaje del auditor
        msg_auditor = Auditor()
        msg_auditor.name_node = self.get_name()
        msg_auditor.date_transaction = f"{datetime.now()}"
        #Asigna los valores según lo pasen, sino dan valores, por defecto es una cadena vacía
        msg_auditor.log_process = logprocess
        msg_auditor.id_node = idnote
        msg_auditor.type_transaction = typetransaction
        msg_auditor.id_user = iduser
        #publica el mensaje del auditor
        self.publisher_auditor_.publish(msg_auditor)
 
    #Ahora esta función se va a encargar de publicar en el nodo de consola
    #def listener_callback(self,msg,info_msg='Message received'):
    def publisher_consoler(self,msg,info_msg='Message received'):
        msg_consoler_ = LogExit()
        #Creando mensaje de consola con los datos pasados en la función
        # * Informe general del tipo de mensaje
        msg_consoler_.log_exit = str(info_msg)
        # * Status (Más detalles del mensaje)
        msg_consoler_.status = str(msg)
        self.create_publisher(LogExit, self.get_code_tema('top_console'), 10).publish(msg_consoler_)


class ActionParentServer:
    def __init__(self, action_type, action_name):
        #Crea el servidor de la acción y nombre de acción dados en los parámetros
        self._action_server = ActionServer(self, action_type,action_name,self.execute_callback)
        #Guarda el tipo de acción
        self.action_type = action_type
        self.action_name = action_name
        #Inicializa el Result del tipo de acción
        self.result = self.action_type.Result()
        self.dict_action_server = {
            # * Aquí se pueden agregar más placas/microcircuito en el futuro
            'arduino': "avrdude -c arduino -P {port} -b 115200 -p atmega328p -D -U flash:w:{file_path}",
            # *  Esta acción se encarga de transformar archivos de vhdl a .bit
            'vhdl_to_bit' : '',
            'charge_bit' : ''
        }
        self.dict_action_server_errors = [
            'Unexpected error.',
            'Infrastructure error, microcontroller not found.',
            'Device port not found.',
            'File not found.'
        ]

    def send_feedback(self,feedback_msg):
        #Enviando feedback al cliente
        self.feedback_msg.status = feedback_msg
        #*self.goal_handle.publish_feedback(self.feedback_msg)

    def execute_goal(self, goal_handle):
        #Guarda el feedback de la action
        self.feedback_msg = self.action_type.Feedback()
        #Guarda goal_handle
        self.goal_handle = goal_handle
        #El servidor acepta la tarea
        self.send_feedback('Goal received')

    def execute_command(self, command_name, port = None, file_path = None, constrain_path = None):
        #*Función para ejecutar los comando del diccionario según el nombre
        try:
            #Ejecuta el comando en base al command_name que haya sido pasado en los parámetros
            command_template = self.dict_action_server[command_name]
            #Formatea los parametros en el comando
            command = command_template.format(port=port, file_path=file_path, constrain_path=constrain_path)
            #Mensaje para mostrar el progreso
            self.send_feedback('Executing command')
            #NodeFather.publisher_consoler(self, command, self.feedback_msg.status)
            
            #Ejecución del comando y lectura de resultados
            command_r = os.popen(command).read()
            self.send_feedback(command_r)
            #Mensaje de que la acción se completo con éxito
            self.send_feedback('Command executed successfully')
            #Publica el status de la tarea
            #NodeFather.publisher_consoler(self, self.feedback_msg.status)
            #Asigna al resultado lo devuelto por la ejecución del comando
            self.result.status_final = command_r         
            self.goal_handle.succeed()
        except:
            #El feedback será el return de la funcion callback_error
            self.send_feedback('Execution failed.')
            self.callback_error(err=1)
        finally:
            #En ambos casos crea y publica el mensaje del auditor
            NodeFather.auditor_msg(self, logprocess=self.result.status_final)

    def callback_error(self,err=0):
        #Al llamar se pasa como argumento el tipo de error
        #*Para cuando no se encuentran los archivos (.hex, .bit, .vhdl)
        #Busca el tipo de error segun el nombre de la acción
        self.result.status_final = self.dict_action_server_errors[err]
        #Aborta la tarea
        self.goal_handle.abort()

        #Publica en exit_logger el status final
        NodeFather.publisher_consoler(self,self.result.status_final, 'Status')

        #Publica el status de la operacion en el nodo auditor
        NodeFather.auditor_msg(self,self.result.status_final)

class ActionParentClient:
    # Se usa como parámetro action_type, que es la acción personalizada .action
    def __init__(self,action_type, action_name):
        #Crea una instancia de cliente de acción con el action_type
        #Usa el action_name para nombrar la acción según el parámetro
        self._action_client = ActionClient(self,action_type, action_name)
        self.action_type = action_type
    
    #Falta implementar la recepción de feedback
    #def feedback_callback(self,feedback_msg):
        #Recibiendo feedback del action_server y publicando en consola
        #NodeFather.publisher_consoler(self,feedback_msg.status,'Feedback')


    def send_goal(self, path, path_constrains=None):
        #Crea una goal con el tipo de Action usado
        goal_msg = self.action_type.Goal()
        #Asigna las rutas a los atributos del goal
        if path_constrains is None:
            #Depende de los argumentos el atributo creado
            goal_msg.path_hex = path
        else:
            # Solo un condicional porque solo son 2 tipos de atributos para las Actions
            goal_msg.path_vhdl = path
            goal_msg.path_constrains = path_constrains

        #Utiliza el método de action_client que es una instancia del mismo objeto (Hijos de esta clase en cada caso)
        self._action_client.wait_for_server()
        #Retorna el resultado del envío de la goal de forma asíncrona
        #self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        self._send_goal_future = self._action_client.send_goal_async(goal_msg)
        return self._send_goal_future
    
    #*Esta función es predeterminada para cada action client, se debe soobreescribir en
    # * ...cada nodo. El parámetro de mensaje se envía en cada nodo desde su propia listener_callback a esta
    #  *    ...callback de la clase parent.
    def function_callback(self, msg, msg_console_type="Message path"):      
        #Se ahorra la variable que era la instancia de esta misma clase para solo usar self
        if msg.path_hex != None:
            #Si sí existe, se usa el path_hex
            future = self.send_goal(msg.path_hex)
        else:
            #Si no existe el path_hex se trabaja con vhdl
            future = self.send_goal(msg.path_vhdl, msg.path_constrains)
        #* si path_constrains (Confi para la tarjeta de interconexión) es None la función de send_goal lo toma para solo
        #*  ...usar al path_hex
        #Imprime en consola el mensaje que es enviado
        NodeFather.publisher_consoler(self, msg.path_hex, msg_console_type)
        rclpy.spin_until_future_complete(self, future)

        #Publica en el nodo de exit_logger la action que fue enviada 
        NodeFather.publisher_consoler(self, f'{future.success}', "Goal sent from")
        #Crea un mensaje del auditor utilizando la función en la clase padre
        NodeFather.auditor_msg(self, logprocess=f"Goal sent from {self.get_name()}", typetransaction="Sent Goal")
        #Publica el mensaje del envio de la goal al server action


def main_base(node_object):
    rclpy.spin(node_object)
    node_object.destroy_node()
    rclpy.shutdown()