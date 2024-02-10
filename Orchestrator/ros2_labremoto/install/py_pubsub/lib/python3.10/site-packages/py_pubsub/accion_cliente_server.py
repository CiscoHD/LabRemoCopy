import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from my_mas.msg import FileHexLoad
from my_mas.action import Tranformvhdlbit


class ArduinoClient(Node):

    def __init__(self):
        super().__init__('Arduino_action_client')
        self._action_client = ActionClient(self, Tranformvhdlbit, 'Admin_transacciones')

    def send_goal(self, path_vhdl,path_constrains):
        goal_msg = Tranformvhdlbit.Goal()
        goal_msg.path_vhdl = path_hex
        goal_msg.path_constrains = path_constrains

        self._action_client.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)


class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            FileHexLoad,
            'Admin_transacciones',
            self.listener_callback,
            10)
        self.subscription  

    def listener_callback(self, msg):
        self.get_logger().info(f'{msg.path_constrains}, {msg.path_vhdl}')
        action_client = ArduinoClient()
        future = action_client.send_goal(msg.path_constrains,msg.path_vhdl)
        rclpy.spin_until_future_complete(action_client, future)

def main(args=None):
    rclpy.init(args=args)


    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
