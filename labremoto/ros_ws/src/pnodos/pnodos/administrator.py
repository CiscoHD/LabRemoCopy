import rclpy
from pvariables.msg import Contract, TransGlobal, LogExit
from rclpy.node import Node
from parent_class import NodeFather, NodeConn, main_base

class AdministratorContracts(Node, NodeFather, NodeConn):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'administrator_contracts')
        NodeFather.__init__(self,'top_transactions')
        NodeConn.__init__(self,'/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db',True) 
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(Contract, self.topic_code, self.listener_callback, 10)
        self.subscription_

        #Se fue la linea de publisher_auditor pq ahora el publisher está implementado en la clase parent
        self.publisher_admintrans_ = self.create_publisher(TransGlobal,self.get_code_tema('top_transactions_accepted'),10)
        #Se fue la linea de publisher console por lo mismo de arriba

        self.initialization_notice()
        
    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self, msg.id_contract, "Request received for contract")
        #Envia mensaje a base de datos para consultar validez
        result,data = NodeConn.request_info_db(self,'admin',msg.id_contract)
        NodeFather.publisher_consoler(self, data, result)
        if not data == None: #Si no hay data, es un error
            msg_tran_accepted = TransGlobal()
            msg_tran_accepted.result = data.get('result')
            msg_tran_accepted.status = data.get('status')
            msg_tran_accepted.name_node = data.get('name_node')
            msg_tran_accepted.date = data.get('date')
            msg_tran_accepted.folio = data.get('folio')
            NodeFather.publisher_consoler(self,msg_tran_accepted,'Transaction published')
            self.publisher_admintrans_.publish(msg_tran_accepted)
    
def main(args=None):
    rclpy.init(args=args)
    administrator = AdministratorContracts()
    main_base(administrator)
    
if __name__ == "__main__":
    main() 