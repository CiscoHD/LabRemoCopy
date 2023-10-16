from launch import LaunchDescription
import launch_ros.actions

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            namespace= "inicio", package='py_pubsub', executable='action', output='screen'),
        launch_ros.actions.Node(
            namespace= "inicio", package='py_pubsub', executable='con_arduino', output='screen'),
    ])