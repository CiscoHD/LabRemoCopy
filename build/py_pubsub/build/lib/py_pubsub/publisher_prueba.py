import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion
from datetime import datetime

class MinimalPublisher(Node):
 
    def __init__(self):
        super().__init__('publicador_info')
        self.publisher_ = self.create_publisher(Operacion, 'top_supervisor_operaciones', 10)
        self.timer_callback()

    def timer_callback(self):
        msg = Operacion()
        msg.nameoperacion =  "prueba envio mensaje"
        msg.descoperacion = "pruebqa para ver el funcionamiento de la base de datos y el envio de datos"
        msg.estatusoperacion = "funcionamiendo"
        msg.fechaoperacion = f"{datetime.now()}"

        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.nameoperacion}')




def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
