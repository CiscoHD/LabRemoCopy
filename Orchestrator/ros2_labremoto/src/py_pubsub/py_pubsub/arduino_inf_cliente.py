import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from my_mas.action import Cargahex
from my_mas.msg import FileHexLoad,Operacion,Auditor

from datetime import datetime



class ArduinoClient(Node):

    def __init__(self):
        super().__init__('Arduino_action_client')
        self._action_client = ActionClient(self, Cargahex, 'arduino_inf')
        self.subscription = self.create_subscription(FileHexLoad,'top_archivos_hex',self.listener_callback,10)
        self.subscription 

        self.publisherauditor_ = self.create_publisher(Auditor, 'top_auditot_transacciones', 10)

        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")
        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(self.create_operacion_msg())


    def create_operacion_msg(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg

    def create_auditor_msg(self):
        msg = Auditor()
        msg.namenode = self.get_name()
        msg.fechatransaccion = f"{datetime.now()}"
        
        return msg

    def send_goal(self, path_hex):
        goal_msg = Cargahex.Goal()
        goal_msg.path_hex = path_hex

        self._action_client.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)
    
    def listener_callback(self, msg):

    
        self.get_logger().info(f'{msg.path_hex}')
        action_client = ArduinoClient()
        future = action_client.send_goal(msg.path_hex)
        rclpy.spin_until_future_complete(action_client, future)

        self.get_logger().info(f'Goal enviado from {self.get_name()} to {action_client.get_name()}')
        msg_auditor = self.create_auditor_msg()
        msg_auditor.tipotransaccion = "Send Goal"
        msg_auditor.logproceso = f"Goal enviado from {self.get_name()} to {action_client.get_name()}"
        self.publisherauditor_.publish(msg_auditor)

def main(args=None):
    rclpy.init(args=args)


    arduino_client = ArduinoClient()

    rclpy.spin(arduino_client)

    arduino_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
