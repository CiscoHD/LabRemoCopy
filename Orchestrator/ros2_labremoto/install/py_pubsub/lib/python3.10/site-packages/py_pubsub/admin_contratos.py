import rclpy
from rclpy.node import Node
import sqlite3
from my_mas.msg import Contrato,TransGlobal

class AdminContratos(Node):

    def __init__(self):
        super().__init__('Administrado_contratos')
        self.subscription = self.create_subscription(
            Contrato,
            'top_transacciones_entrada',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'{msg.idcontrato}')
        conexion = sqlite3.connect('/home/ffelix07/Documents/LabRemo/Orchestrator/LABREMODB.cdb3')
        cursor = conexion.cursor()
        query =  f""" SELECT CONTRATOS WHERE IdContrato = {msg.idcontrato}"""

        cursor.execute(query)
        info_contrato = cursor.fetchall()
        self.get_logger().info(f'{msg.contrato} {msg.especificacioncontrato}')


def main(args=None):
    rclpy.init(args=args)

    Admin_contrato = AdminContratos()

    rclpy.spin(Admin_contrato)
    Admin_contrato.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
