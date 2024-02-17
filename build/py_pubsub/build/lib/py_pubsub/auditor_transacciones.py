import rclpy
from rclpy.node import Node
from my_mas.msg import Auditor,Operacion

import sqlite3
from datetime import datetime
import json

class AuditorNode(Node):

    def __init__(self):
        super().__init__('AuditorTransacciones')
        self.subscription = self.create_subscription(
            Auditor,
            'top_auditor_transacciones',
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

        self.get_logger().info(f"Mensaje leido: {msg.tipotransaccion} by {msg.namenode} ")

        path_database= json.load(open('/home/ffelix07/Documents/LabRemo/Orchestrator/VARIABLES_ORQUESTADOR.json'))['path_database']
        conexion = sqlite3.connect(path_database)
        cursor = conexion.cursor()
        query =  f""" INSERT INTO TRAN (IdNode,NameNode,TipoTransaccion,
        FechaTransaccion,IdUser,LogProceso) VALUES 
        {(msg.idnode,msg.namenode,msg.tipotransaccion,msg.fecharansaccion,
          msg.iduser,msg.logproceso)};"""

        cursor.execute(query)
        conexion.commit()
        conexion.close()
        self.get_logger().info(f"Mensaje Guardado")



def main(args=None):
    rclpy.init(args=args)

    auditor = AuditorNode()
    rclpy.spin(auditor)
    auditor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
