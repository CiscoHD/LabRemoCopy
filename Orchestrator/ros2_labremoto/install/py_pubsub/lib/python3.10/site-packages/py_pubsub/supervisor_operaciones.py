import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion

import sqlite3
from datetime import datetime
import json



class SupervidorOPeraciones(Node):

    def __init__(self):
        super().__init__('supervisor_operaciones')
        self.subscription = self.create_subscription(
            Operacion,
            'top_supervisor_operaciones',
            self.listener_callback, 10)
        self.subscription  # prevent unused variable warning

        inicio = False
        if not inicio:
             self.publish_inicio_nodo()
             inicio = True

    
    def publish_inicio_nodo(self):
            self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(self.create_operacion_msg())
            self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")


    def create_operacion_msg(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg

    def listener_callback(self, msg):
        self.get_logger().info(f"Proceso recibido: {msg.nameoperacion} {msg.descoperacion}")

        path_database= json.load(open('/home/ffelix07/Documents/LabRemo/Orchestrator/VARIABLES_ORQUESTADOR.json'))['path_database']
        query =  f""" INSERT INTO SUPERVISOROPERACIONES (nameoperacion,DescOperacion,EstatusOperacion,
          EstatusOperacion,FechaOperacion) VALUES 
        {(msg.nameoperacion,msg.descoperacion,msg.estatusoperacion,
          msg.estatusoperacion,msg.fechaoperacion)};"""
        
        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()        
        cursor.execute(query)
        conexion.commit()
        conexion.close()

        self.get_logger().info(f"Informacion guardada")

def main(args=None):
    rclpy.init(args=args)
    supervidor_operaciones = SupervidorOPeraciones()
    rclpy.spin(supervidor_operaciones)

    supervidor_operaciones.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
