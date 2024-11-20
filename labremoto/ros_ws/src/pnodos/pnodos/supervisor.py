import rclpy
from pvariables.msg import Operation
from rclpy.node import Node
from nodefather import NodeFather, main_base

class SupervisorMessage(Node, NodeFather):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'supervisor_nodes')
        NodeFather.__init__(self,'top_supervisor_operations')
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(Operation, self.topic_code, self.listener_callback, 10)
        self.subscription_
        
        #Publicador para enviar al nodo de la base de datos
        self.publisher_ = self.create_publisher(Operation, self.get_code_tema('db_supervisor'), 10)
        
    def listener_callback(self, msg, info_msg='Process received'):
        msg_op = f"{msg.name_operation} {msg.desc_operation}"
        NodeFather.publisher_consoler(self, msg_op, info_msg)
        #Envia mensaje a base de datos para guardar info
        self.publisher_.publish(msg)
    
def main(args=None):
    rclpy.init(args=args)
    supervisor = SupervisorMessage()
    main_base(supervisor)
    
if __name__ == "__main__":
    main() 