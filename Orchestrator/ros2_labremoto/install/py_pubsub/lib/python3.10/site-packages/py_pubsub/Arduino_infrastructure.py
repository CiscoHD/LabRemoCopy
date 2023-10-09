import arduino
from my_mas.action import Cargahex
import time
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

import pandas as pd
import os
import json


def devices_arduino_info():
    try:
        dispositivos = pd.concat(list(map(pd.json_normalize,json.loads(os.popen("arduino-cli board list --format json").read()))))
        return dispositivos
    except ValueError:
        return "No dispositivos conectados" 

class ActionServer(Node):

    def __init__(self):
        super().__init__('carga_arduino_action_server')
        self._action_server = ActionServer(
            self,
            Cargahex,
            'arduino_inf',
            self.execute_callback)

    def execute_callback(self,goal_handle):
        
        feedback_msg = Cargahex.Feedback()
        feedback_msg.status = 'Executing...'
        goal_handle.publish_feedback(feedback_msg)

        dispositivos = devices_arduino_info()

        feedback_msg.status = f'No. dispositivos {len(dispositivos)}'
        goal_handle.publish_feedback(feedback_msg)

        port = dispositivos['port.label'][0]
        fqbn_ard = dispositivos.iloc[0]['matching_boards'][0]['fqbn']

        sketch_path = goal_handle.request.path_hex
    
        ard_infres = arduino.TestArduinoCLI()
        ard_infres.setUp()

        feedback_msg.status = 'load'
        goal_handle.publish_feedback(feedback_msg)
        feedback_msg.status = ard_infres.testCompilationSuccess(fqbn_ard,sketch_path)

        goal_handle.succeed()

        result = Cargahex.status_final()
        result.status_final = f"conexión {port} {fqbn_ard}"

        return result


def main(args=None):
    rclpy.init(args=args)

    action_server = ActionServer()

    rclpy.spin(action_server)


if __name__ == '__main__':
    main()