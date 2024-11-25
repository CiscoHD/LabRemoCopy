import rclpy
from pvariables.msg import Auditor
from rclpy.node import Node
from parent_class import NodeFather, main_base

class AuditorTransactions(Node, NodeFather):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'auditor_transactions')
        NodeFather.__init__(self,'top_auditor_transactions')
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(Auditor, self.topic_code, self.listener_callback, 10)
        self.subscription_
        
        #Publicador para enviar al nodo de la base de datos
        self.publisher_ = self.create_publisher(Auditor, self.get_code_tema('db_auditor'), 10)

        self.initialization_notice()
        
    def listener_callback(self, msg, info_msg='Transaction read'):
        #Imprimir mensaje de recepción en consola
        msg_op = f"{msg.name_node} {msg.type_transaction}"
        NodeFather.publisher_consoler(self, msg_op, info_msg)
        #Envia mensaje a base de datos para guardar info
        self.publisher_.publish(msg)
    
def main(args=None):
    rclpy.init(args=args)
    auditor = AuditorTransactions()
    main_base(auditor)
    
if __name__ == "__main__":
    main() 