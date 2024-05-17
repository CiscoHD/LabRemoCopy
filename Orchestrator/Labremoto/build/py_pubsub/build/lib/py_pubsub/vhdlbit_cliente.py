import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from my_mas.msg import CreateBitStream,Operacion,Auditor
from my_mas.action import Tranformvhdlbit
from datetime import datetime 

class ClienteTransformVhdlBIT(Node):

    def __init__(self):
        super().__init__('vhdlbit_transform_client')
        self._action_client = ActionClient(self, Tranformvhdlbit, 'transformar_bit')
        self.subscription = self.create_subscription(CreateBitStream,'top_create_bit',self.listener_callback,10)
        self.subscription  
        self.msg_inicio_node()

        self.publisherauditor_ = self.create_publisher(Auditor, 'top_auditot_transacciones', 10)



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

    def send_goal(self, path_vhdl,path_constrains):
        goal_msg = Tranformvhdlbit.Goal()
        goal_msg.path_vhdl = path_vhdl
        goal_msg.path_constrains = path_constrains

        self.ClienteTransformVhdlBIT.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)


    def listener_callback(self, msg):
        self.get_logger().info(f'{msg.path_constrains}, {msg.path_vhdl}')
        action_client = ClienteTransformVhdlBIT()
        future = action_client.send_goal(msg.path_constrains,msg.path_vhdl)
        rclpy.spin_until_future_complete(action_client, future)

        self.get_logger().info(f'Goal enviado from {self.get_name()} to {action_client.get_name()}')
        msg_auditor = self.create_auditor_msg()
        msg_auditor.tipotransaccion = "Send Goal"
        msg_auditor.logproceso = f"Goal enviado from {self.get_name()} to {action_client.get_name()}"
        self.publisherauditor_.publish(self.create_auditor_msg())


def main(args=None):
    
    rclpy.init(args=args)
    tranform_vhdlbit = ClienteTransformVhdlBIT()
    rclpy.spin(tranform_vhdlbit)
    tranform_vhdlbit.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
