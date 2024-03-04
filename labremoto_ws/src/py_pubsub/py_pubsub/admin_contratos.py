import rclpy
from rclpy.node import Node
import sqlite3
from my_mas.msg import Contrato,LogSalida,Operacion,Auditor,TransGlobal

import sqlite3
from datetime import datetime
import json

class AdminContratos(Node):
    """
    Administrador de contratos, encargado revisar la transaccion entrante
    y verificar que cumple las restricciones de acuerdo al tipo de transaccion.

    Attributes:
        subscription (subscriptor): Esucha las transacciones de entrada
        publisherauditor_ (publisher): Publica el resultado del nodo
        publisheradmintransaccion_ (publisher): publica la transaccion aceptada
        publisherconsola_ (publisher): Publica los log en la consola
    """

    def __init__(self):
        super().__init__('administrador_contratos')
        self.subscription = self.create_subscription(
            Contrato,'top_transacciones',self.listener_callback,10)
        self.subscription  
        self.msg_inicio_node()
        
        self.publisherauditor_  = self.create_publisher(Auditor, 'top_auditor_transacciones', 10)
        self.publisheradmintransaccion_  = self.create_publisher(TransGlobal, 'top_transacciones_aceptadas', 10)
        self.publisherconsola_ = self.create_publisher(LogSalida,'top_consola',10)
 

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

    def create_auditor_msg(self):
        msg = Auditor()
        msg.namenode = self.get_name()
        msg.fechatransaccion = f"{datetime.now()}"
        
        return msg


    def listener_callback(self, msg):


        self.get_logger().info(f'Solicitud recibida para contrato {msg.idcontrato}')

        path_database= json.load(open('/home/trabajo/LabRemo/VARIABLES_ORQUESTADOR.json'))['path_database']

        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()
        query =  f""" SELECT * FROM CONTRATOS WHERE IdContrato = {msg.idcontrato}"""

        cursor.execute(query)
        info_contrato = cursor.fetchall()
        conexion.close()
        
        if len(info_contrato) != 0:
            self.get_logger().info(f'Contrato {msg.idcontrato}  encontrado, procede a verificar ')
            
            if True==True:
                 
                 self.get_logger().info(f'Transaccion aceptada')
                 msg_auditor = self.create_auditor_msg()
                 msg_auditor.logproceso = "Transaccion aceptada"
                 self.publisherauditor_.publish(msg_auditor)                 
                 self.publisheradmintransaccion_ .publish()
            else:
                 self.get_logger().info(f'Transaccion no aceptada: {msg.especificacioncontrato}')
                 msg_auditor = self.create_auditor_msg()
                 msg_auditor.logproceso = "Transaccion no  aceptada"
                 self.publisherauditor_.publish(self.create_transaccion_msg())
                                 
                 msg_log =  LogSalida()
                 msg_log.logsalida = "Transaccion no  aceptada"
                 self.publisherconsola_.publish(msg_log)
        
        else:
             self.get_logger().info(f'Contrato {msg.idcontrato} no encontrado ')
        


def main(args=None):

    rclpy.init(args=args)
    Admin_contrato = AdminContratos()
    rclpy.spin(Admin_contrato)
    Admin_contrato.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
