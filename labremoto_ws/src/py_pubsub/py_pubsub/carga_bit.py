from my_mas.action import CargaBit
import datetime as dt 
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json
from my_mas.msg import TransGlobal
from my_mas.msg import BitLoad

class CargaBitFPGA(Node):

    def __init__(self):
        super().__init__('Carga_Bit_FPGA')
        self._action_server = ActionServer(
            self,
            CargaBit,
            'Admin_transacciones',
            self.execute_callback)
        
        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)



    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing upload to FPGA...')
        feedback_msg = CargaBit.Feedback()
        msg = TransGlobal()
        msg.fecha = str(dt.datetime.now())
        msg._name_node = str(self.get_name())


        dispositivos = json.loads(os.popen("Dispositivos_VIVADO_conectado").read())

        if len(dispositivos)!= 0:
            self.get_logger().info("Looking for file .bit ..." )
            path_bitstream = goal_handle.request.path_bit
            try:
    
                upload_r = os.popen(f"vivado -mode batch -source s-upload.tcl -tclargs {path_bitstream}").read()
                feedback_msg.status = 'update finish'
                goal_handle.succeed()
                self.get_logger().info(feedback_msg.status)

                result = CargaBit.Result()
                result.status_final = upload_r 
                
                msg.resultado = feedback_msg.status 
                self.publisher_.publish(msg)

                
                return result

            except:
                feedback_msg.status = 'File no found'
                goal_handle.abort()
                result = CargaBit.Result()
                result.status_final = feedback_msg.status

                msg.resultado = feedback_msg.status
                self.publisher_.publish(msg)

                self.get_logger().info(result.status_final)


                
                return result

  
        else: 
            feedback_msg.status = 'Error infrestractura, no FPGA found'
            goal_handle.abort()
            result = CargaBit.Result()
            result.status_final = feedback_msg.status

            msg.resultado = feedback_msg.status
            self.publisher_.publish(msg)
            self.get_logger().info(result.status_final)


            
            return result


def main(args=None):
    rclpy.init(args=args)

    action_server = CargaBitFPGA()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()