import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Contrato
from datetime import datetime

class MinimalPublisher(Node):
 
    def __init__(self):
        super().__init__('publicador_info')
        self.publisher_ = self.create_publisher(Contrato, 'top_transacciones_entrada', 10)
        self.timer_callback()

    def timer_callback(self):
        msg = Contrato()
        msg.idcontrato =  4

        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.idcontrato}')




def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
