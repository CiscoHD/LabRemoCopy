import rclpy
from rclpy.node import Node
from my_mas.msg import Auditor,Operacion

import sqlite3
from datetime import datetime
import json

class AuditorTransacciones(Node):

    def __init__(self):
        super().__init__('auditor_transacciones')
        self.subscription = self.create_subscription(
            Auditor,'top_auditor_transacciones',self.listener_callback, 10)
        self.subscription  
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

        self.get_logger().info(f"Mensaje leido: {msg.namenode} {msg.tipotransaccion} ")

        path_database= json.load(open('/home/trabajo/LabRemo/VARIABLES_ORQUESTADOR.json'))['path_database']
       
        query =  f""" INSERT INTO TRANSACCIONESAUDITOR (IdNode,NameNode,TipoTransaccion,
        FechaTransaccion,IdUser,LogProceso) VALUES 
        {(msg.idnode,msg.namenode,msg.tipotransaccion,msg.fechatransaccion,
        msg.iduser,msg.logproceso)};"""
        
        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()
        cursor.execute(query)
        conexion.commit()
        conexion.close()
        self.get_logger().info(f"Mensaje Guardado")



def main(args=None):

    rclpy.init(args=args)
    auditor_transacciones = AuditorTransacciones()
    rclpy.spin(auditor_transacciones)
    auditor_transacciones.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
