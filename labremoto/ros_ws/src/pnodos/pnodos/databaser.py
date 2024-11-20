import rclpy
from pvariables.msg import Auditor, Operation
from rclpy.node import Node
from nodefather import NodeFather, NodeConn, main_base
import sqlite3

class DatabaserLogger(Node, NodeFather, NodeConn):
    
    def __init__ (self):
        Node.__init__(self,'databaser_logger')
        NodeFather.__init__(self, "db_supervisor")
        #Cambiar por URL de api y quitar True
        NodeConn.__init__(self,'/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db',True) 
        
        #Recibe los datos del nodo supervisor
        self.subscription_ = self.create_subscription(Operation,self.topic_code,self.listener_callback,10)
        self.subscription_

        #Recibe los datos del nodo auditor
        self.subscription_auditor_ = self.create_subscription(Auditor,self.get_code_tema("db_auditor"),self.listener_callback,10) 
        self.subscription_auditor_

        #Diccionario para ver el tipo de mensaje que recibe según el topic
        # ? Tal vez se pueda optimizar más esta parte
        self.diction_msg_type = {
            "<class 'pvariables.msg._auditor.Auditor'>" : ["auditor", ["id_node", "name_node", "type_transaction", "date_transaction", "id_user", "log_process"]],
            "<class 'pvariables.msg._operation.Operation'>" : ["supervisor", ["name_operation", "desc_operation", "status_operation", "date_operation", "topic_operation"]]
        }
        
        self.initialization_notice()
        
    def listener_callback(self, msg):
        #Recibe la info en tupla y el tipo de mensaje para buscar la sentencia SQL
        tuple_db, sentence = self.convert_msg(msg)
        #Envia la info en tupla y el tipo de mensaje para buscar la sentencia
        result = self.insert_log_db(tuple_db, sentence)
        if result == 'Success':
            NodeFather.publisher_consoler(self,tuple_db,'Information upload to database')
        else:
            
            msg = result[0]
            NodeFather.publisher_consoler(self, msg, result[1])
    
    def convert_msg(self,msg):
        #Busca el tipo de mensaje en el diccionario
        msg_type = self.diction_msg_type.get(f"{type(msg)}")
        # Convierte los datos del array en una tupla
        # * Se crea un iterable para cada atributo del array correspondiente al mensaje
        tuple_db = tuple(getattr(msg,attr) for attr in msg_type[1])
        # * Se usa la función getattr para según el atributo del array pasarlo como iterable
        # * La tupla se crea con el iterable generado a partir de los atributos
        msg_type = str(msg_type[0])
        #Retorna la tupla y el tipo de mensaje para usar la sentencia asignada al tipo
        return tuple_db, msg_type
    
def main(args=None):
    rclpy.init(args=args)
    databaser_logger = DatabaserLogger()
    main_base(databaser_logger)
    
if __name__ == "__main__":
    main() 