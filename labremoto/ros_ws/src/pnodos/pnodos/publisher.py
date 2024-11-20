import rclpy
from std_msgs.msg import String
from rclpy.node import Node
from nodefather import NodeFather, main_base

class PublisherMessage(Node, NodeFather):
    
    def __init__ (self):
        Node.__init__(self,'publisher_message')
        NodeFather.__init__(self,'information_input')
        
        self.publisher = self.create_publisher(String, self.topic_code, 10)
        timer_period = 0.5
        
        self.time = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
        self.initialization_notice()
        
    def timer_callback(self):
        msg = String()
        msg.data = f"Counter number: {self.i}"
        self.publisher.publish(msg)
        NodeFather.publisher_consoler(self,msg,'Published')
        self.i += 1
        
def main(args=None):
    rclpy.init(args=args)
    publisher = PublisherMessage()
    main_base(publisher)
    
if __name__ == "__main__":
    main() 