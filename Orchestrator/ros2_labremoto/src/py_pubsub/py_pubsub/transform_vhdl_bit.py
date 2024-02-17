from my_mas.action import Tranformvhdlbit
from datetime import datetime
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json
from datetime import datetime
from my_mas.msg import Operacion,Auditor
import os

class TanformVHDLBit(Node):

    def __init__(self):
        super().__init__('Tranformacion_vhdl_bit')
        self._action_server = ActionServer(
            self,
            Tranformvhdlbit,
            'transformar_bit',
            self.execute_callback)
        
        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(self.create_operacion_msg())
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")


        self.publisherauditor_  = self.create_publisher(Auditor, 'top_auditor_transacciones', 10)

    def create_operacion_msg(self):
        msg = Operacion()
        msg.nameoperacion =  "Inicio Nodo"
        msg.descoperacion = f"{self.get_name()}"
        msg.estatusoperacion = "Publicado"
        msg.fechaoperacion = f"{datetime.now()}"
        
        return msg

    def create_auditor_msg(self):
        msg = Auditor()
        msg.namenode = self.get_name()
        msg.fechatransaccion = f"{datetime.now()}"
        
        return msg

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing transform...')
        feedback_msg = Tranformvhdlbit.Feedback()


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
                
                
                return result
            except:
                feedback_msg.status = 'Error Tranform file'
                goal_handle.abort()
        
                result = Tranformvhdlbit.Result()
                result.status_final = feedback_msg.status

                self.get_logger().info(result.status_final)
                return result

        else:
            
            feedback_msg.status = f'File {a} {b} found'
                
            goal_handle.abort()
        
            result = Tranformvhdlbit.Result()
            result.status_final = feedback_msg.status
            self.get_logger().info(result.status_final)

            msg_auditor = self.create_auditor_msg()
            msg_auditor.logproceso = result.status_final
            self.publisherauditor_.publish(msg_auditor)
            
            return result

def main(args=None):
    rclpy.init(args=args)

    action_server = TanformVHDLBit()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()