from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package = 'pnodos',
                executable = 'arduino_inf_server',
                output = 'screen'
            ),
            TimerAction(
                period = 2.5,  # Espera 2.5 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'arduino_inf_client',
                        output = 'screen'
                    )
                ]
            )
        ]
    )