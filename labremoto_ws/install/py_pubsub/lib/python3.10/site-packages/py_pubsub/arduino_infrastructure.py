from my_mas.action import Cargahex
from datetime import datetime
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json

from my_mas.msg import Operacion,Auditor,LogSalida

class ArduinoActionServer(Node):

    def __init__(self):
        super().__init__('carga_arduino_hex')
        self._action_server = ActionServer(
            self,Cargahex,'arduino_inf',self.execute_callback)
        self.msg_inicio_node()

        self.publisherauditor_  = self.create_publisher(Auditor, 'top_auditor_transacciones', 10)
        self.publisherconsola_ = self.create_publisher(LogSalida,'top_consola',10)

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

    def create_auditor_msg(self):
        msg = Auditor()
        msg.namenode = self.get_name()
        msg.fechatransaccion = f"{datetime.now()}"
        
        return msg

    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing upload to arduino...')
        feedback_msg = Cargahex.Feedback()
        

        dispositivos = json.loads(os.popen("arduino-cli board list --format json").read())

        if len(dispositivos)!= 0:
            self.get_logger().info("Looking for file .hex ..." )
            sketch_path = goal_handle.request.path_hex 
            PORT = dispositivos[0]['port']['address']
            #FQBN = dispositivos[0]['matching_boards'][0]['fqbn']
            if os.path.exists(sketch_path):
                #copil = os.popen(f"arduino-cli compile --fqbn {FQBN} {sketch_path}").read()               
                #upload_r = os.popen(f"arduino-cli -p {PORT} upload {sketch_path}").read()
                upload_r = os.popen(f"avrdude -c arduino -P {PORT} -b 115200 -p atmega328p -D -U flash:w:{sketch_path}").read()
                feedback_msg.status = 'update finish'
                goal_handle.succeed()
                self.get_logger().info(feedback_msg.status)
                msg_log = LogSalida()
                msg_log.logsalida = feedback_msg.status
                self.publisherconsola_.publish(msg_log)

                result = Cargahex.Result()
                result.status_final = feedback_msg.status 
    
                msg_auditor = self.create_auditor_msg()
                msg_auditor.logproceso = result.status_final
                self.publisherauditor_.publish(msg_auditor)
                
                return result

            else:
                feedback_msg.status = 'File no found'
                goal_handle.abort()
                result = Cargahex.Result()
                result.status_final = feedback_msg.status

                self.get_logger().info(result.status_final)

                msg_auditor = self.create_auditor_msg()
                msg_auditor.logproceso = result.status_final
                self.publisherauditor_.publish(msg_auditor)
                msg_log =  LogSalida()
                msg_log.logsalida = 'File no found'
                self.publisherconsola_.publish(msg_log)

                return result

  
        else: 
            feedback_msg.status = 'Error infrestractura, no arduinos found'
            goal_handle.abort()
            result = Cargahex.Result()
            result.status_final = feedback_msg.status
            self.get_logger().info(result.status_final)

            msg_auditor = self.create_auditor_msg()
            msg_auditor.logproceso = result.status_final
            self.publisherauditor_.publish(msg_auditor)
            msg_log = LogSalida()
            msg_log.logsalida = 'Error infrestractura, no arduinos found'
            self.publisherconsola_.publish(msg_log)
            
            return result


def main(args=None):

    rclpy.init(args=args)
    action_server = ArduinoActionServer()
    rclpy.spin(action_server)


if __name__ == '__main__':
    main()