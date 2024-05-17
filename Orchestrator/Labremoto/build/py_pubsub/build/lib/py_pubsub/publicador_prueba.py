import rclpy
from rclpy.node import Node
from my_mas.msg import TransGlobal
import datetime as dt


class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('Publicador_test')
        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)
        timer_period = 10  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        msg = TransGlobal()
        msg.fecha = str(dt.datetime.now())
        msg.resultado = f'error '
        msg.folio = str(self.i)
        msg._name_node = str(self.get_name())

        self.publisher_.publish(msg)
        self.get_logger().info(f"Publicado")
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()