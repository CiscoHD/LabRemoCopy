import rclpy
from pvariables.msg import Operation
from pvariables.action import CargaHex
from rclpy.node import Node
from nodefather import NodeFather, ActionParentServer, main_base
import os
import json

class DeviceNotFoundError(Exception):
    #*Excepción personalizada para indicar que no se encontró el dispositivo
    pass
class PortNotFoundError(Exception):
    #*Excepción personalizada para indicar que no se encontró el puerto
    pass

class ArduinoActionServer(Node, NodeFather, ActionParentServer):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'arduino_inf_server')
        NodeFather.__init__(self)
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentServer.__init__(self, CargaHex, 'arduino_inf')

        self.initialization_notice()
        
    def execute_callback(self, goal_handle):
        try:
            #Mandar el mensaje a la funcion listener_callback del ClientActionParent Class y recibir
            #...feedback_msg y result como retorno
            ActionParentServer.execute_goal(self, goal_handle)

            #Busca los dispositivos conectados (tarjetas) 
            devices = json.loads(os.popen("arduino-cli board list --format json").read())
            
            if not devices or 'detected_ports' not in devices or not devices['detected_ports']:
                raise DeviceNotFoundError()# Verifica que existan dispositivos y puertos detectados

            self.send_feedback(f'Available devices: {devices}') #Envia los dispositivos como feedback
            
            port = None #Busca el puerto del dispositivo conectado
            for device in devices['detected_ports']:
                if 'port' in device and 'address' in device['port'] and ('USB' in device['port']['address'] or 'ACM' in device['port']['address']):
                    # Verifica que exista la propiedad de port y de address. Verifica que el puerto sea el correspondiente para arduinos
                    port = device['port']['address']
                    break
            
            if port is None:#Comprueba que el puerto esté definido
                raise PortNotFoundError()
            
            self.send_feedback(f'Microcontroller port: {port}') #Envia puerto como feedback
        

            file_path = goal_handle.request.path_hex #Recupera la ruta del archivo
            if not os.path.exists(file_path):#Comprueba que el archivo exista
                raise FileNotFoundError()
            
            self.send_feedback(f'Searching file: {file_path}') #Devulve el archivo como feedback
            
            #NodeFather.publisher_consoler(self, 'Upload to arduino', 'Executing')
            self.send_feedback('Executing upload to arduino')

            #Ejecuta el comando desde el método de clase
            ActionParentServer.execute_command(self, 'arduino', port, file_path)
        
        except DeviceNotFoundError as e:#Haciendo una excepción para los tipos de error
            self.callback_error(err=1)
            self.send_feedback(str(e))#Convierte a un mensaje de texto el error

        except PortNotFoundError as e:
            self.callback_error(err=2)#Llamando el método para imprimir errores
            self.send_feedback(str(e))#Usando método para imprimir y mandar feedback

        except FileNotFoundError as e:
            self.callback_error(err=3)
            self.send_feedback(str(e))

        except Exception as e:
            self.callback_error(err=0)  # Error genérico adicional
            self.send_feedback("Unexpected error: {e}")

        finally:
            return self.result #Sin importar que, retorna el resultado
    
def main(args=None):
    rclpy.init(args=args)
    arduino_inf_server = ArduinoActionServer()
    main_base(arduino_inf_server)
    
if __name__ == "__main__":
    main() 