import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from my_mas.action import Cargahex


class ArduinoClient(Node):

    def __init__(self):
        super().__init__('Arduino_action_client')
        self._action_client = ActionClient(self, Cargahex, 'arduino_inf')

    def send_goal(self, path_hex):
        goal_msg = Cargahex.Goal()
        goal_msg.path_hex = path_hex

        self._action_client.wait_for_server()

        return self._action_client.send_goal_async(goal_msg)


def main(args=None):
    rclpy.init(args=args)

    action_client = ArduinoClient()

    future = action_client.send_goal("/home/ffelix07/Documents/Arduino/Prueba")

    rclpy.spin_until_future_complete(action_client, future)


if __name__ == '__main__':
    main()
