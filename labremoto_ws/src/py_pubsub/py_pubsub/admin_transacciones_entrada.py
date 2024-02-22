import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,Auditor,TransGlobal,TransEntrada,Contrato,LogSalida

import sqlite3
from datetime import datetime
import json


class AdminTransacciones(Node):

    def __init__(self):
        super().__init__('administrador_transacciones_entrada')
        self.subscription = self.create_subscription(
            TransEntrada,
            'top_transacciones_entrada',
            self.listener_callback,
            10)

        self.subscription  # prevent unused variable warning
        self.publisherconsola_ = self.create_publisher(LogSalida,'top_consola',10)

        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(self.create_operacion_msg())
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")


        self.publishercontrato_ = self.create_publisher(Contrato, 'top_transacciones', 10)



    def create_operacion_msg(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg

    def listener_callback(self, msg):

        self.get_logger().info(f'Transaccion entrada recibida: {msg}')

        path_database= json.load(open('/home/ffelix07/Documents/LabRemo/Orchestrator/VARIABLES_ORQUESTADOR.json'))['path_database']
        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()
        query =  f""" SELECT * FROM USUARIOS WHERE Id = {msg.idestudiante}"""
        cursor.execute(query)
        info = cursor.fetchall()
        conexion.close()

        if len(info) != 0:
            self.get_logger().info(f'Transaccion correcta, procede a revisar las restricciones')
            msg_contrato = Contrato()
            if msg.tipotransaccion == 'CargaHex':
                 msg_contrato.idcontrato = '4'
                 msg_contrato.nombrecontrato = 'carga'
                 msg_contrato.tipocontrato = 'hex'
                 msg_contrato.desccontrato = msg.descripcion
                 msg_contrato.especificacioncontrato
            
            self.publishercontrato_.publish(msg_contrato)
        else:
             self.get_logger().info(f'Transaccion no se puede procesar')           
             msg_log =  LogSalida()
             msg_log.logsalida = "Transaccion no se puede procesar"
             self.publisherconsola_.publish(msg_log)

def main(args=None):
    rclpy.init(args=args)

    admin_transacciones = AdminTransacciones()

    rclpy.spin(admin_transacciones)
    admin_transacciones.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
