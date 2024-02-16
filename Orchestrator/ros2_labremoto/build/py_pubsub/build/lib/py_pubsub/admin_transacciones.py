import rclpy
from rclpy.node import Node
import sqlite3
from my_mas.msg import TransGlobal


class AdminTransacciones(Node):

    def __init__(self):
        super().__init__('Administrador_transacciones')
        self.subscription = self.create_subscription(
            TransGlobal,
            'top_transacciones_aceptadas',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)



    def listener_callback(self, msg):
        self.get_logger().info(f'{msg.name_node}')
        self.publisher_.publish(msg)
        

def main(args=None):
    rclpy.init(args=args)

    Admin_contrato = AdminTransacciones()

    rclpy.spin(Admin_contrato)
    Admin_contrato.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
