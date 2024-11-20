import rclpy # type: ignore
from std_msgs.msg import String # type: ignore
from rclpy.node import Node # type: ignore
from pvariables.msg import Auditor
from nodefather import NodeFather, main_base

class SubscriberMessage(Node, NodeFather):
    
    def __init__ (self):
        Node.__init__(self,'subscriber_message')
        NodeFather.__init__(self,'information_input')
        
        self.subscription_ = self.create_subscription(String, self.topic_code, self.callback, 10)
        self.subscription_
        self.initialization_notice()

        # * Prueba para saber el type de message
        #self.msg = Auditor()
        #self.get_logger().info(f"Tipo: {type(self.msg)}")

        # * Prueba para la función de clase padre "auditor_msg"
        self.auditor_test()
    
    def callback(self,msg):
        NodeFather.publisher_consoler(self,f'{msg.data}','Counter')
        
    def auditor_test(self):
        topic = self.get_code_tema('top_auditor_transactions')
        self.create_publisher(Auditor, topic, 10).publish(self.auditor_msg("Logprocess"))
    
def main(args=None):
    rclpy.init(args=args)
    subscriber = SubscriberMessage()
    main_base(subscriber)
    
if __name__ == "__main__":
    main() 