import rclpy
from rclpy.node import Node
from my_mas.msg import Auditor
import sqlite3


class AuditorNode(Node):

    def __init__(self):
        super().__init__('AuditorTransacciones')
        self.subscription = self.create_subscription(
            Auditor,
            'top_transacciones',
            self.listener_callback, 10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):

        self.get_logger().info(f"Mensaje leido: {msg.TipoTransaccion} by {msg.NameNode} ")

        conexion = sqlite3.connect('/home/ffelix07/Documents/LabRemo/Orchestrator/LABREMODB.cdb3')
        cursor = conexion.cursor()
        query =  f""" INSERT INTO TRAN (IdNode,NameNode,TipoTransaccion,
        FechaTransaccion,IdUser,LogProceso) VALUES 
        {(msg.IdNode,msg.NameNode,msg.TipoTransaccion,msg.FechaTransaccion,
          msg.IdUser,msg.LogProceso)};"""

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
