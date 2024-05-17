import sys
from my_mas.srv import LoadFiledb
import rclpy
from rclpy.node import Node


class SendTranClient(Node):

    def __init__(self):
        super().__init__('SendTranClient')
        self.cli = self.create_client(LoadFiledb, 'TranConsola')
        
        while not self.cli.wait_for_service(timeout_sec = 3.0):
            self.get_logger().info('service not available, waiting again...')
        self.req = LoadFiledb.Request()


    def send_request(self, id_node,name_node,type_transaction,
                     date_process,id_user,log_process):

        self.req.id_node = id_node
        self.req.name_node = name_node
        self.req.type_transaction = type_transaction
        self.req.date_process = date_process
        self.req.id_user = id_user 
        self.req.log_process = log_process

        self.future = self.cli.call_async(self.req)
        rclpy.spin_until_future_complete(self, self.future)
        
        return self.future.result()


def main():
    rclpy.init()

    minimal_client = SendTranClient()
    response = minimal_client.send_request(int(sys.argv[1]), 
                                           sys.argv[2],
                                           sys.argv[3],
                                           sys.argv[4], 
                                           int(sys.argv[5]), 
                                           sys.argv[6])
    
    minimal_client.get_logger().info(f'{sys.argv}')

    minimal_client.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()