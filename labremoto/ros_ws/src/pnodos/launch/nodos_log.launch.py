from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package = 'pnodos',
                executable = 'supervisor',
                output = 'screen'
            ),
            Node(
                package = 'pnodos',
                executable = 'exit_logger',
                output = 'screen'
            ),
            TimerAction(
                period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'auditor',
                        output = 'screen'
                    )
                ]
            ),
            TimerAction(
                period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'databaser',
                        output = 'screen'
                    )
                ]
            ),
            TimerAction(
                period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'input_transactioner', #1ro en recibir
                        output = 'screen'
                    )
                ]
            ),
            TimerAction(
                period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'administrator', #2do en recibir
                        output = 'screen'
                    )
                ]
            ),
            TimerAction(
                period = 3.0,  # Espera 3 segundos antes de iniciar el siguiente nodo
                actions = [
                    Node(
                        package = 'pnodos',
                        executable = 'transactioner', #3ro en recibir y que envia actions
                        output = 'screen'
                    )
                ]
            )
        ]
    )
