import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Contrato,FileHexLoad,LogSalida
from datetime import datetime
import json 

class MinimalPublisher(Node):
 
    def __init__(self):
        super().__init__('publicador_info')
        #self.publisher_ = self.create_publisher(Contrato, 'top_transacciones_entrada', 10)
        self.publisher_ = self.create_publisher(LogSalida, 'top_consola', 10)
        self.timer_callback()

    def timer_callback(self):
        msg =  LogSalida()
        msg.logsalida = "prueba funcionando"
        self.publisher_.publish(msg)
        self.get_logger().info(f'publuicacion lista')





def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
