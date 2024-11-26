import rclpy 
from .node_father import NodeFather
from .node_conn import NodeConn
from .action_parent_server import ActionParentServer
from .action_parent_client import ActionParentClient

def main_base(node_object):
    rclpy.spin(node_object)
    node_object.destroy_node()
    rclpy.shutdown()

__all__ = [
    'NodeFather',
    'NodeConn',
    'ActionParentServer',
    'ActionParentClient',
    'main_base'
]