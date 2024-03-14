import json
import sqlite3
from datetime import datetime

import rclpy
from rclpy.node import Node

from my_mas.msg import Operacion

class SupervisorOperaciones(Node):
    """
    Supervisor de Operaciones, encargado revisar el funcionamiento
    de los nodos que conforma el Orquestador.

    Attributes:
        subscription (subscriptor): listener node de operaciones
    """

    def __init__(self):

        super().__init__('supervisor_operaciones')
        self.subscription = self.create_subscription(
            Operacion,'top_supervisor_operaciones', self.listener_callback, 10)
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

        def save_operacion(msg):
            """
            Guarda la información de la operación en la base de datos

            Args:
                msg: mensaje recibido del topico al que se encuentra suscrito

            Returns:
                int: mensaje resultante de la operacion
            """

            path_database= json.load(open('/home/trabajo/LabRemo/VARIABLES_ORQUESTADOR.json'))['path_database']
            query =  f""" INSERT INTO SUPERVISOROPERACIONES (
                nameoperacion,DescOperacion,EstatusOperacion,EstatusOperacion,FechaOperacion) VALUES 
                {(msg.nameoperacion,msg.descoperacion,msg.estatusoperacion, msg.estatusoperacion,msg.fechaoperacion)};"""
        
            conexion = sqlite3.connect(path_database)
            cursor = conexion.cursor()        
            cursor.execute(query)
            conexion.commit()
            conexion.close()
            
            return "Informacion guardada"
        
        self.get_logger().info(f"Proceso recibido: {msg.nameoperacion} {msg.descoperacion}")
        self.get_logger().info(save_operacion(msg))

def main(args=None):
    rclpy.init(args=args)
    supervisor_operaciones = SupervisorOperaciones()
    rclpy.spin(supervisor_operaciones)
    supervisor_operaciones.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
