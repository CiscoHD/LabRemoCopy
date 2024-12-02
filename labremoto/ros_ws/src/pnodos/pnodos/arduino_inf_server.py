import rclpy
from pvariables.action import HexCharge
from rclpy.node import Node
from parent_class import NodeFather, ActionParentServer, PortNotFoundError,DeviceNotFoundError, FileNotFoundError 
import os
import json

class ArduinoActionServer(Node, NodeFather, ActionParentServer):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'arduino_inf_server')
        NodeFather.__init__(self)
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentServer.__init__(self, HexCharge, 'arduino_inf')

        self.initialization_notice()
        
    def execute_callback(self, goal_handle):
        try:
            #Mandar el mensaje a la funcion listener_callback del ClientActionParent Class y recibir feedback_msg y result como retorno
            ActionParentServer.execute_goal(self, goal_handle)
            port = '/dev/arduino_uno' # TODO: Aquí hay que hacer una función que administre los puertos para cuando haya varios arduinos conectados

            self.send_feedback(f'Verifying available port: {port}') #Envia feedback
            if not self.available_port(port): #Verifica el puerto
                raise PortNotFoundError() #Lanza exception
            
            self.send_feedback(f'Port: {port} is available') #Envia puerto como feedback

            file_path = goal_handle.request.path_hex #Recupera la ruta del archivo
            self.send_feedback(f'Searching file: {file_path}') #Devulve la ruta del archivo como feedback

            if not os.path.exists(file_path):#Comprueba que el archivo exista
                raise FileNotFoundError() #Lanza exception
            
            self.send_feedback('Executing upload to arduino')#Feedback

            #Ejecuta el comando desde el método de clase
            ActionParentServer.execute_command(self, 'arduino', port, file_path)
        
        except DeviceNotFoundError as e:#Haciendo una excepción para los tipos de error
            self.callback_error(e)

        except PortNotFoundError as e:
            self.callback_error(e)#Llamando el método para imprimir errores

        except FileNotFoundError as e:
            self.callback_error(e)

        except Exception as e:
            self.callback_error(e)  # Error genérico adicional

        finally:
            return self.result #Sin importar que, retorna el resultado
    
def main(args=None):
    rclpy.init(args=args)
    arduino_inf_server = ArduinoActionServer()
    rclpy.spin(arduino_inf_server)
    
if __name__ == "__main__":
    main() 