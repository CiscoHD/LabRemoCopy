import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from my_mas.msg import SensorMeasurment
from my_mas.msg import CreateBitStream
import random

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('publicador_info')
        self.publisher_ = self.create_publisher(CreateBitStream, 'Admin_tran', 10)
        self.timer_callback()

    def timer_callback(self):
        msg = CreateBitStream()
        msg.path_vhdl =  "/home/ffelix07"
        msg.path_constrains = 'w'

        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.path_vhdl} {msg.path_constrains} ')


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
