import rclpy
from rclpy.node import Node
from my_mas.msg import TransGlobal,Operacion

import sqlite3
from datetime import datetime
import json


class AdminTransacciones(Node):

    def __init__(self):
        super().__init__('Administrador_transacciones')
        self.subscription = self.create_subscription(
            TransGlobal,
            'top_transacciones_aceptadas',
            self.listener_callback,
            10)
        
        self.subscription  # prevent unused variable warning
        self.publisher_ = self.create_publisher(Operacion, 'supervisor', 10)       

        self.publisheroperacion_ = self.create_publisher(TransGlobal, 'top_supervisor_operaciones', 10)
        self.publisheroperacion_.publish(self.create_operacion())
        
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")


    def create_operacion(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg


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
