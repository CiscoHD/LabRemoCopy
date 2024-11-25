import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from parent_class import NodeFather
from pvariables.action import CargaHex

class FibonacciActionServer(Node,NodeFather):

    def __init__(self):
        Node.__init__(self,'fibonacci_action_server')
        NodeFather.__init__(self)
        self._action_server = ActionServer(
            self,
            CargaHex,
            'fibonacci',
            self.execute_callback)

    def execute_callback(self, goal_handle):
        NodeFather.publisher_consoler(self,'Executing goal...')

        feedback_msg = CargaHex.Feedback()
        feedback_msg.status = str([0, 1])

        for i in range(1, int(goal_handle.request.path_hex)):
            feedback_msg.status += feedback_msg.status[i] + feedback_msg.status[i-1]
            NodeFather.publisher_consoler(self,'Feedback: {0}'.format(feedback_msg.status))
            goal_handle.publish_feedback(feedback_msg)

        goal_handle.succeed()

        result = CargaHex.Result()
        result.status_final = feedback_msg.status
        return result


def main(args=None):
    rclpy.init(args=args)

    fibonacci_action_server = FibonacciActionServer()

    rclpy.spin(fibonacci_action_server)


if __name__ == '__main__':
    main()