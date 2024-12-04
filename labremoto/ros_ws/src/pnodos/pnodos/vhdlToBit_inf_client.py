import rclpy
from pvariables.msg import CreateBitStream
from pvariables.action import VhdlToBit
from rclpy.node import Node
from parent_class import NodeFather, ActionParentClient

class VhdlToBitActionClient(Node,NodeFather,ActionParentClient):

    def __init__(self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'vhdlToBit_inf_client')
        NodeFather.__init__(self,'top_vhdl_to_bit')
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentClient.__init__(self, VhdlToBit, 'vhdlToBit_inf')
    
        #Se suscribe a transactioner.py para recibir la orden de acción
        self.subscription_ = self.create_subscription(CreateBitStream, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()

    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self,'VHDL To Bit Stream Action initialized.')#Mandar el mensaje a la function_callback del ActionParentClient Class
        self.send_goal(path_vhdl=msg.path_vhdl,path_constrains=msg.path_constrains) #Envia la goal con los paramétros según el tipo de acción
    
def main(args=None):
    rclpy.init(args=args)
    vhdlToBit_inf_client = VhdlToBitActionClient()
    rclpy.spin(vhdlToBit_inf_client)
    
if __name__ == "__main__":
    main() 