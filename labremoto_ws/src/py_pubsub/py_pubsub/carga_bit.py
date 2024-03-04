from my_mas.action import CargaBit
from datetime import datetime 
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json
from my_mas.msg import TransGlobal,Operacion,BitLoad

class CargaBitFPGA(Node):

    def __init__(self):
        super().__init__('Carga_Bit_FPGA')
        self._action_server = ActionServer(
            self,CargaBit,'carga_bit_fpga',self.execute_callback)
        self.msg_inicio_node()

        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)

    def msg_inicio_node(self):
        """
        Funcion para publicar el inicio del nodo.
        
        Args:
            none

        Returns:
            none
        """
        msg_operacion = Operacion()
        msg_operacion.nameoperacion =  "Inicio Nodo"
        msg_operacion.descoperacion = f"{self.get_name()}"
        msg_operacion.estatusoperacion = "Iniciado"
        msg_operacion.fechaoperacion = f"{datetime.now()}"
    
        self.create_publisher(Operacion, 'top_supervisor_operaciones', 10).publish(msg_operacion)
        self.get_logger().info(f"{self.get_name()} node created: {datetime.now()}")

    def execute_callback(self, goal_handle):

        self.get_logger().info('Executing upload to FPGA...')
        feedback_msg = CargaBit.Feedback()
        msg = TransGlobal()
        msg.fecha = str(datetime.now())
        msg._name_node = str(self.get_name())


        dispositivos = json.loads(os.popen("Dispositivos_VIVADO_conectado").read())

        if len(dispositivos)!= 0:
            self.get_logger().info("Looking for file .bit ..." )
            path_bitstream = goal_handle.request.path_bit
            try:
    
                upload_r = os.popen(f"openFPGALoader -b xc7z010 {path_bitstream}").read()
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