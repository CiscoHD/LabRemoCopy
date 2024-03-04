import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,LogSalida,TransGlobal,TransEntrada,Contrato

import sqlite3
from datetime import datetime
import json


class AdminLogSalida(Node):
    """
    Adminitrador de logs de salida, encargado revisar el log de salida que 
    sera publicado en la consola.

    Attributes:
        subscription (subscriptor): escucha los mensaje e salida a consola
    """

    def __init__(self):
        super().__init__('administrador_log_salida')
        self.subscription = self.create_subscription(
            LogSalida, 'top_log_salida', self.listener_callback,10)
        self.subscription  # prevent unused variable warning
        self.msg_inicio_node()

    def msg_inicio_node(self):
        """
        Funcion para publicar el inicio del nodo.
        
        Args:
            none

        Returns:
            none
        """
        msg_operacion = Operacion()
        msg_operacion.nameoperacion =  "Inicio Nodo"
        msg_operacion.descoperacion = f"{self.get_name()}"
        msg_operacion.estatusoperacion = "Iniciado"
        msg_operacion.fechaoperacion = f"{datetime.now()}"
    
        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(msg_operacion)
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")

    def listener_callback(self, msg):

        self.get_logger().info(f'salida a consola')
        self.publisherconsola_.publish(f'{msg.logsalida}')
        
            
def main(args=None):

    rclpy.init(args=args)
    admin_log_salida = AdminLogSalida()
    rclpy.spin(admin_log_salida)
    admin_log_salida.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
