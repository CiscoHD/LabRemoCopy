import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,LogSalida,TransGlobal,TransEntrada,Contrato

import sqlite3
from datetime import datetime
import json


class AdminTransacciones(Node):

    def __init__(self):
        super().__init__('administrador_log_salida')
        self.subscription = self.create_subscription(
            LogSalida,
            'top_log_salida',
            self.listener_callback,
            10)

        self.subscription  # prevent unused variable warning

        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(self.create_operacion_msg())
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")


        self.publisherconsola_ = self.create_publisher(LogSalida, 'top_consola', 10)



    def create_operacion_msg(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg

    def listener_callback(self, msg):

        self.get_logger().info(f'salida a consola')
        self.publisherconsola_.publish(f'{msg.logsalida}')
            
def main(args=None):
    rclpy.init(args=args)

    admin_transacciones = AdminTransacciones()

    rclpy.spin(admin_transacciones)
    admin_transacciones.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
