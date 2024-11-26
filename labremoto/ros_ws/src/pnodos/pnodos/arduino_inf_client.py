import rclpy
from pvariables.msg import FileHexLoad
from pvariables.action import CargaHex
from rclpy.node import Node
from parent_class import NodeFather, ActionParentClient

class ArduinoActionClient(Node, NodeFather, ActionParentClient):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'arduino_inf_client')
        NodeFather.__init__(self,'top_files_hex')
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentClient.__init__(self, CargaHex, 'arduino_inf')
    
        #Se suscribe a transactioner.py para recibir la orden de acción
        self.subscription_ = self.create_subscription(FileHexLoad, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()
        
    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self,'Arduino action initialized.', 'File found');
        #Mandar el mensaje a la function_callback del ActionParentClient Class
        ActionParentClient.function_callback(self,msg)
    
def main(args=None):
    rclpy.init(args=args)
    arduino_inf_client = ArduinoActionClient()
    rclpy.spin(arduino_inf_client)
    
if __name__ == "__main__":
    main() 