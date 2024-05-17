import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion,TransEntrada,Contrato,LogSalida

import sqlite3
from datetime import datetime
import json


class AdminTransaccionesEntrada(Node):
    """
    Administrador de transacciones de entrada, encargado enviar el mensaje al nodo de contratos
    una vez que se hayan revisado los parametros de entrada de la transaccion.

    Attributes:
        publisherconsola_ (publisher): Publica información en el topic de la consola
        publishercontrato_ (publisher): Publica información en el topic transacciones
    """

    def __init__(self):

        super().__init__('administrador_transacciones_entrada')
        self.subscription = self.create_subscription(
            TransEntrada,'top_transacciones_entrada',self.listener_callback,10)
        self.subscription  
        self.msg_inicio_node()

        self.publisherconsola_ = self.create_publisher(LogSalida,'top_log_salida',10)
        self.publishercontrato_ = self.create_publisher(Contrato, 'top_transacciones', 10)


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
    admin_transacciones_entrada = AdminTransaccionesEntrada()
    rclpy.spin(admin_transacciones_entrada)
    admin_transacciones_entrada.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
