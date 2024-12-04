import rclpy
from pvariables.msg import FilePyLoad #!Depende del tipo de archivo
from pvariables.action import PyCharge #! Depende del tipo de archivo
from rclpy.node import Node
from parent_class import NodeFather, ActionParentClient

class RaspActionClient(Node,NodeFather,ActionParentClient):

    def __init__(self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'rasp_inf_client')
        NodeFather.__init__(self,'top_files_py') #!Depende del tipo de archivo
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentClient.__init__(self, PyCharge, 'rasp_inf')
    
        #Se suscribe a transactioner.py para recibir la orden de acción
        self.subscription_ = self.create_subscription(FilePyLoad, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()

    def listener_callback(self, msg):
        NodeFather.publisher_consoler(self,'Raspberry Action initialized.')
        #Mandar el mensaje a la function_callback del ActionParentClient Class
        self.send_goal(path_py=msg.path_py) #Envia la goal con los paramétros según el tipo de acción
    
def main(args=None):
    rclpy.init(args=args)
    rasp_inf_client = RaspActionClient()
    rclpy.spin(rasp_inf_client)
    
if __name__ == "__main__":
    main() 