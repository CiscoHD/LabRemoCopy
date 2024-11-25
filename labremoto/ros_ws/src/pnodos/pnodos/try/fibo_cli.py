import rclpy
from pvariables.msg import FileHexLoad
from rclpy.action import ActionClient
from rclpy.node import Node
from parent_class import NodeFather
from pvariables.action import CargaHex

class FibonacciActionClient(Node,NodeFather):

    def __init__(self):
        Node.__init__(self,'fibonacci_action_client')
        NodeFather.__init__(self,'top_files_hex')
        self._action_client = ActionClient(self, CargaHex, 'fibonacci')

        self.subscription_ = self.create_subscription(FileHexLoad, self.topic_code, self.listener_callback, 10)
        self.subscription_

    def send_goal(self, order):
        goal_msg = CargaHex.Goal()
        goal_msg.path_hex = order

        self._action_client.wait_for_server()

        self._send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)

        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            NodeFather.publisher_consoler(self,'Goal rejected :(')
            return

        NodeFather.publisher_consoler(self,'Goal accepted :)')

        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        NodeFather.publisher_consoler(self,'Result: {0}'.format(result.status_final))
        rclpy.shutdown()

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        NodeFather.publisher_consoler(self,'Received feedback: {0}'.format(feedback.status))

    def listener_callback(self,msg):
        self.send_goal('10')

def main(args=None):
    rclpy.init(args=args)

    action_client = FibonacciActionClient()
    rclpy.spin(action_client)


if __name__ == '__main__':
    main()