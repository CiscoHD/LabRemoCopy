import rclpy
from rclpy.node import Node
from my_mas.msg import Operacion
import sqlite3
from datetime import datetime
import json



class SupervidorOPeraciones(Node):

    def __init__(self):
        super().__init__('Supervisor_operaciones')
        self.subscription = self.create_subscription(
            Operacion,
            'top_supervisor_operaciones',
            self.listener_callback, 10)
        self.subscription  # prevent unused variable warning
        print(f"{self.get_name()} node created: {datetime.now()}")

    def listener_callback(self, msg):

        path_database= json.load(open('/home/ffelix07/Documents/LabRemo/Orchestrator/VARIABLES_ORQUESTADOR.json'))['path_database']

        self.get_logger().info(f"Leido {msg.nameoperacion}")
        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()
        query =  f""" INSERT INTO SUPERVISOROPERACIONES (nameoperacion,DescOperacion,EstatusOperacion,
          EstatusOperacion,FechaOperacion) VALUES 
        {(msg.nameoperacion,msg.descoperacion,msg.estatusoperacion,
          msg.estatusoperacion,msg.fechaoperacion)};"""
        cursor.execute(query)
        conexion.commit()
        conexion.close()
        self.get_logger().info(f"informacion guardada")

def main(args=None):
    rclpy.init(args=args)
    supervidor_operaciones = SupervidorOPeraciones()
    
    rclpy.spin(supervidor_operaciones)
    supervidor_operaciones.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
