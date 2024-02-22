import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Contrato,FileHexLoad,TransEntrada
from datetime import datetime
import json 

class MinimalPublisher(Node):
 
    def __init__(self):
        super().__init__('publicador_transaccion_entrada')
        self.publisher_ = self.create_publisher(TransEntrada, 'top_transacciones_entrada', 10)
        self.timer_callback()

    def timer_callback(self):
        msg = TransEntrada()

        msg.tipotransaccion = 'CargaHex'
        msg.status = 'Peticion'
        msg.idestudiante = '1'
        msg.idsesion = '1'
        msg.descripcion = ''
    
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg}')





def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
