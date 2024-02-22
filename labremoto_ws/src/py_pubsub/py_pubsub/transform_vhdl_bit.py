from my_mas.action import Tranformvhdlbit
import datetime as dt 
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json
from my_mas.msg import TransGlobal
from my_mas.msg import CreateBitStream
import os

class TanformVHDLBit(Node):

    def __init__(self):
        super().__init__('Tranformacion_vhdl_bit')
        self._action_server = ActionServer(
            self,
            Tranformvhdlbit,
            'Admin_transacciones',
            self.execute_callback)
        
        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)



    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing transform...')
        feedback_msg = Tranformvhdlbit.Feedback()
        msg = TransGlobal()
        msg.fecha = str(dt.datetime.now())
        msg._name_node = str(self.get_name())


        self.get_logger().info("Looking for file .vhdl and contains ..." )
        
        
        vhdl_pth = goal_handle.request.path_vhdl
        constrain_path = goal_handle.request.path_constrains
        a = os.path.exists(vhdl_pth) 
        b = os.path.exists(constrain_path)
        if a and b:
            try:
            
                upload_r = os.popen(f"vivado -mode batch -source s-compile.tcl -tclargs {vhdl_pth} {constrain_path}").read()
                feedback_msg.status = 'Tranform finished'
                goal_handle.succeed()
                self.get_logger().info(feedback_msg.status)

                result = Tranformvhdlbit.Result()
                result.status_final = upload_r 
                
                msg.resultado = feedback_msg.status 
                self.publisher_.publish(msg)

                
                return result
            except:
                feedback_msg.status = 'Error Tranform file'
                goal_handle.abort()
        
                result = Tranformvhdlbit.Result()
                result.status_final = feedback_msg.status

                msg.resultado = feedback_msg.status
                self.publisher_.publish(msg)

                self.get_logger().info(result.status_final)
                return result

        else:
            
            feedback_msg.status = f'File {a} {b} found'
                
            goal_handle.abort()
        
            result = Tranformvhdlbit.Result()
            result.status_final = feedback_msg.status

            msg.resultado = feedback_msg.status
            self.publisher_.publish(msg)

            self.get_logger().info(result.status_final)
            return result

def main(args=None):
    rclpy.init(args=args)

    action_server = TanformVHDLBit()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()