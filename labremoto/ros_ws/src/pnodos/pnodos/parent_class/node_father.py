from pvariables.msg import Operation, Auditor, LogExit
from datetime import datetime
import pandas as pd

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
        # Genera el topic para publicar
        topic = self.get_code_tema('top_supervisor_operations')
        self.create_publisher(Operation, topic, 10).publish(msg) #Publica

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
        msg_consoler_ = LogExit()#Creando mensaje de consola con los datos pasados en la función
        msg_consoler_.log_exit = str(info_msg)# Informe general del tipo de mensaje
        msg_consoler_.status = str(msg)# Status (Más detalles del mensaje)
        self.create_publisher(LogExit, self.get_code_tema('top_console'), 10).publish(msg_consoler_) #Publicando
