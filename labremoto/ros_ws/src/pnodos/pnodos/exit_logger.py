import rclpy
from pvariables.msg import LogExit
from rclpy.node import Node
from nodefather import NodeFather, main_base

#Nodo para manejar publiaciones en consola
class LoggerConsole(Node, NodeFather):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'exit_logger_console')
        NodeFather.__init__(self,'top_console')
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(LogExit, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.initialization_notice()
        
    def listener_callback(self, msg):
        #Recibe mensajes para consola y los imprime
        self.get_logger().info(f"{msg.log_exit}: {msg.status}")
    
def main(args=None):
    rclpy.init(args=args)
    logger_console = LoggerConsole()
    main_base(logger_console)
    
if __name__ == "__main__":
    main() 