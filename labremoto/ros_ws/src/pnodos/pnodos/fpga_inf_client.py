import rclpy
from pvariables.msg import FileBitLoad
from pvariables.action import BitCharge
from rclpy.node import Node
from parent_class import NodeFather, ActionParentClient

class FPGA_ActionClient(Node,NodeFather,ActionParentClient):
#!! HACER PRUEBAS CON TARJETA FÍSICA REAL
#* Action para cuando la fpga NO es matriz y solo se usa como tarjeta
    def __init__(self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'fpga_inf_client')
        NodeFather.__init__(self,'top_files_bit')
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentClient.__init__(self, BitCharge, 'fpga_inf')
    
        #Se suscribe a transactioner.py para recibir la orden de acción
        self.subscription_ = self.create_subscription(FileBitLoad, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()

    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self,'FPGA Upload BitStream Action initialized.')
        #Mandar el mensaje a la function_callback del ActionParentClient Class
        self.send_goal(path_bit=msg.path_bit) #Envia la goal con los paramétros según el tipo de acción
    
def main(args=None):
    rclpy.init(args=args)
    fpga_inf_client = FPGA_ActionClient()
    rclpy.spin(fpga_inf_client)
    
if __name__ == "__main__":
    main() 