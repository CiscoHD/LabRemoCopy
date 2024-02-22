from my_mas.action import Cargahex
import datetime as dt 
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json
from my_mas.msg import TransGlobal

class ArduinoActionServer(Node):

    def __init__(self):
        super().__init__('Carga_arduino_hex')
        self._action_server = ActionServer(
            self,
            Cargahex,
            'arduino_inf',
            self.execute_callback)
        
        self.publisher_ = self.create_publisher(TransGlobal, 'supervisor', 10)



    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing upload to arduino...')
        feedback_msg = Cargahex.Feedback()
        msg = TransGlobal()
        msg.fecha = str(dt.datetime.now())
        msg._name_node = str(self.get_name())


        dispositivos = json.loads(os.popen("arduino-cli board list --format json").read())

        if len(dispositivos)!= 0:
            self.get_logger().info("Looking for file .hex ..." )
            sketch_path = goal_handle.request.path_hex 
            PORT = dispositivos[0]['port']['address']
            #FQBN = dispositivos[0]['matching_boards'][0]['fqbn']
            try:
                #copil = os.popen(f"arduino-cli compile --fqbn {FQBN} {sketch_path}").read()               
                #upload_r = os.popen(f"arduino-cli -p {PORT} upload {sketch_path}").read()
                upload_r = os.popen(f"avrdude -c arduino -P {PORT} -b 115200 -p atmega328p -D -U flash:w:{sketch_path}").read()
                feedback_msg.status = 'update finish'
                goal_handle.succeed()
                self.get_logger().info(feedback_msg.status)

                result = Cargahex.Result()
                result.status_final = upload_r 
                
                msg.resultado = feedback_msg.status 
                self.publisher_.publish(msg)

                
                return result

            except:
                feedback_msg.status = 'File no found'
                goal_handle.abort()
                result = Cargahex.Result()
                result.status_final = feedback_msg.status

                msg.resultado = feedback_msg.status
                self.publisher_.publish(msg)

                self.get_logger().info(result.status_final)


                
                return result

  
        else: 
            feedback_msg.status = 'Error infrestractura, no arduinos found'
            goal_handle.abort()
            result = Cargahex.Result()
            result.status_final = feedback_msg.status

            msg.resultado = feedback_msg.status
            self.publisher_.publish(msg)
            self.get_logger().info(result.status_final)


            
            return result


def main(args=None):
    rclpy.init(args=args)

    action_server = ArduinoActionServer()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()