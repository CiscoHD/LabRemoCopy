import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from my_mas.msg import SensorMeasurment
from my_mas.msg import FileHexLoad
import random

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        self.publisher_ = self.create_publisher(FileHexLoad, 'archivos_hex', 10)
        self.timer_callback()
        #timer_period = 0.5  # seconds
        #self.timer = self.create_timer(timer_period, self.timer_callback)
        #self.i = 0

    def timer_callback(self):
        msg = FileHexLoad()
        msg.path_hex = "/home/trabajo/test_hex_files/blink_test.ino.with_bootloader.bin" #"/home/ffelix07/Documents/Arduino/DCmotorx2/build/arduino.avr.uno/DCmotorx2.ino.hex"
       
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.path_hex} ')


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()