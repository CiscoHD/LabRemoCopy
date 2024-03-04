from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='py_pubsub',
            executable='supervisor_operaciones',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='auditor_transacciones',
            output='screen'),
            
        Node(
            package='py_pubsub',
            executable='admin_contratos',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='admin_transacciones',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='arduino_infrastructure',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='arduino_inf_cliente',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='transform_vhdl_bit',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='action_cliente_server',
            output='screen'),
        Node(
            package='py_pubsub',
            executable='admin_log_salida',
            output='screen'),
       Node(
            package='py_pubsub',
            executable='admin_transacciones_entrada',
            output='screen'),
    ])
 