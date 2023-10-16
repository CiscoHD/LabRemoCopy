from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='py_pubsub',
            namespace='A',
            executable='arduino_infrastructure',
            name='sim'
        ),
        Node(
            package='py_pubsub',
            namespace='B',
            executable='fibonacci_action_server',
            name='sim'
        )
    ])