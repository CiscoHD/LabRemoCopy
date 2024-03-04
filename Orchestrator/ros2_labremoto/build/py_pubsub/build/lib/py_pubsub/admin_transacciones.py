import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Auditor,TransGlobal,FileHexLoad,CreateBitStream

import sqlite3
from datetime import datetime
import json


class AdminTransacciones(Node):

    def __init__(self):
        super().__init__('administrador_transacciones')
        self.subscription = self.create_subscription(
            TransGlobal,'top_transacciones_aceptadas',self.listener_callback,10)
        self.subscription  # prevent unused variable warning
        self.msg_inicio_node()

        self.publisherarduino_ = self.create_publisher(FileHexLoad, 'archivos_hex', 10)
        self.publisherbit_ = self.create_publisher(CreateBitStream, 'create_bit', 10)


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
        self.get_logger().info(f'Transaccion recibida: {msg.name_node}')
        if msg.name_node == '':
             msgtransaccion = FileHexLoad()
             msgtransaccion.path_hex = ''
             self.publisherarduino_.publish(msgtransaccion)
        else:
             msgtransaccion = CreateBitStream()
             msgtransaccion.path_bit = ''
             self.publisherbit_ .publish(msgtransaccion)     
        

def main(args=None):
    
    rclpy.init(args=args)
    admin_transacciones = AdminTransacciones()
    rclpy.spin(admin_transacciones)
    admin_transacciones.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
