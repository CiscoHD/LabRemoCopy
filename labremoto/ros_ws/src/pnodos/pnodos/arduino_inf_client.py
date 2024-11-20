import rclpy
from pvariables.msg import FileHexLoad
from pvariables.action import CargaHex
from rclpy.node import Node
from nodefather import NodeFather, ActionParentClient, main_base

class ArduinoActionClient(Node, NodeFather, ActionParentClient):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'arduino_inf_client')
        NodeFather.__init__(self,'top_files_hex')
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentClient.__init__(self, CargaHex, 'arduino_inf')
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(FileHexLoad, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()
        
    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self,'Arduino action initializated.', 'File finded');
        #Mandar el mensaje a la funcion listener_callback del ActionParentClient Class
        ActionParentClient.function_callback(self,msg)
    
def main(args=None):
    rclpy.init(args=args)
    arduino_inf_client = ArduinoActionClient()
    main_base(arduino_inf_client)
    
if __name__ == "__main__":
    main() 