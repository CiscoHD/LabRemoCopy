from my_mas.msg import LoadFiledb
import rclpy
from rclpy.node import Node
import requests

class SendTranDataBase(Node):

    def __init__(self):
        super().__init__('SendTranDataBase')
        self.srv = self.create_service(LoadFiledb, 'TranConsola', self.SendInfodb)

    def SendInfodb(self, request, status):

        InfoTran = {"id_node": request.id_node, 
                    "name_node":request.name_node,
                    "type_transaction":request.type_transaction,
                    "date_process": request.date_process,
                    "id_user": request.id_user,
                    "log_process": request.log_process}

        resp = requests.post('http://labrem.ddns.net/api/', data=InfoTran)

        return resp.status_code
    
    def get_info(self,tabla,request):
        resp = requests.get(f'http://labrem.ddns.net:8000/api/{tabla}/1/',timeout=0.01)


def main():

    rclpy.init()
    minimal_service = SendTranDataBase()

    rclpy.spin(minimal_service)

    rclpy.shutdown()


if __name__ == '__main__':
    main()