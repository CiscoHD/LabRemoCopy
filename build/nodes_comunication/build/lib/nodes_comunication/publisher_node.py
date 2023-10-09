#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nodes_comunication.msg import measure_sensor
import random

class MyNode(Node):

    def __init__(self):
        super().__init__("first_node")
        self.publisher_ = self.create_publisher(measure_sensor, 'arduino_infrestructura', 10)
        self.counter_ = 0
        self.create_timer(1.0,self.timer_callback)

    def timer_callback(self):
        #self.get_logger().info(f"Helo {self.counter_}")
        self.counter_ += 1
        msg = measure_sensor()
        msg.temperature = random.random()*10+30
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.temperature}')
        self.i += 1

def main(args=None):
    rclpy.init(args=args)
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()