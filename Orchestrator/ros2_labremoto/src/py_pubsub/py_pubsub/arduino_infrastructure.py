from my_mas.action import Cargahex
import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
import os
import json

class ArduinoActionServer(Node):

    def __init__(self):
        super().__init__('carga_arduino_action_server')
        self._action_server = ActionServer(
            self,
            Cargahex,
            'arduino_inf',
            self.execute_callback)


    def execute_callback(self, goal_handle):
        self.get_logger().info('Executing upload to arduino...')
        feedback_msg = Cargahex.Feedback()

  
        dispositivos = json.loads(os.popen("arduino-cli board list --format json").read())

        if len(dispositivos)!= 0:
            self.get_logger().info("Looking for file .hex ..." )
            #try:
            sketch_path = goal_handle.request.path_hex 
            PORT = dispositivos[0]['port']['address']
            FQBN = dispositivos[0]['matching_boards'][0]['fqbn']
            try:
                #copil = os.popen(f"arduino-cli compile --fqbn {FQBN} {sketch_path}").read()               
                #upload_r = os.popen(f"arduino-cli -p {PORT} upload {sketch_path}").read()
                upload_r = os.popen(f"avrdude -c arduino -P {PORT} -b 115200 -p atmega328p -D -U flash:w:{sketch_path}").read()
                feedback_msg.status = 'update finish'
                goal_handle.succeed()
                self.get_logger().info(feedback_msg.status)

                result = Cargahex.Result()
                result.status_final = upload_r 
                
                return result

            except:
                feedback_msg.status = 'File no found'
                goal_handle.abort()
                result = Cargahex.Result()
                result.status_final = feedback_msg.status
                self.get_logger().info(result.status_final)
                return result

  
        else: 
            feedback_msg.status = 'Error infrestractura, no arduinos found'
            goal_handle.abort()
            result = Cargahex.Result()
            result.status_final = feedback_msg.status
            self.get_logger().info(result.status_final)
            return result


def main(args=None):
    rclpy.init(args=args)

    action_server = ArduinoActionServer()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()
