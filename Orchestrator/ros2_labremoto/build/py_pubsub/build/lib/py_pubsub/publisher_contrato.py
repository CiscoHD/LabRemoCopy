import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Contrato,FileHexLoad
from datetime import datetime
import json 

class MinimalPublisher(Node):
 
    def __init__(self):
        super().__init__('publicador_info')
        #self.publisher_ = self.create_publisher(Contrato, 'top_transacciones_entrada', 10)
        self.publisher_ = self.create_publisher(FileHexLoad, 'top_archivos_hex', 10)
        self.timer_callback()

    def timer_callback(self):
        msg = FileHexLoad()
        msg.path_hex =  json.load(open('/home/ffelix07/Documents/LabRemo/Orchestrator/VARIABLES_ORQUESTADOR.json'))['archivo_hex']

        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.path_hex}')





def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
