import rclpy
from pvariables.action import PyCharge
from rclpy.node import Node
from parent_class import NodeFather, ActionParentServer, PortNotFoundError, DeviceNotFoundError, FileNotFoundError
import os

class RaspActionServer(Node, NodeFather, ActionParentServer):

    def __init__(self):
        Node.__init__(self,'rasp_inf_server')
        NodeFather.__init__(self)
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentServer.__init__(self, PyCharge, 'rasp_inf')

        self.initialization_notice()
    
    def execute_callback(self,goal_handle):
        try:
            ActionParentServer.execute_goal(self, goal_handle) #Inicializar feedback y result
            port = '/dev/raspberry' # TODO: Aquí hay que hacer una función que administre los puertos para cuando haya varias esp32 conectados
            #Tal vez aquí se pueda usar la exception de DeviceNotFound

            self.send_feedback(f'Verifying available port: {port}') #Envia feedback
            if not ActionParentServer.available_port(self,port): #Verifica el nombre esté ligado a un puerto 
                raise PortNotFoundError() #Lanza exception
            
            self.send_feedback(f'Port: {port} is available') #Envia puerto como feedback

            file_path = goal_handle.request.path_py #Ruta de archivo .bin
            self.send_feedback(f'Searching file: {file_path}') #Devulve la ruta del archivo como feedback

            if not os.path.exists(file_path):#Comprueba que el archivo exista
                raise FileNotFoundError() #Lanza exceptión personalizada
            
            self.send_feedback('Executing upload to Raspberry')#Feedback

            #Ejecuta el comando desde el método de clase
            ActionParentServer.execute_command(self, 'raspberry', port, file_path)

        except DeviceNotFoundError as e:#Haciendo una excepción para los tipos de error
            self.callback_error(e)

        except PortNotFoundError as e: #Error para cuando el puerto no coincida con el nombre custom
            self.callback_error(e)

        except FileNotFoundError as e:
            self.callback_error(e)#Llamando el método para imprimir errores

        except Exception as e:
            self.callback_error(e)  # Error genérico adicional
            
        finally:
            return self.result #Sin importar que, retorna el resultado

def main(args=None):
    rclpy.init(args=args)
    rasp_inf_server = RaspActionServer()
    rclpy.spin(rasp_inf_server)
    
if __name__ == "__main__":
    main() 