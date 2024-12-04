import rclpy
from pvariables.action import BitCharge
from rclpy.node import Node
from parent_class import NodeFather, ActionParentServer, PortNotFoundError, DeviceNotFoundError, FileNotFoundError
import os

class FPGA_ActionServer(Node, NodeFather, ActionParentServer):
#!! HACER PRUEBAS CON TARJETA FÍSICA REAL

    def __init__(self):
        Node.__init__(self,'fpga_inf_server')
        NodeFather.__init__(self)
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentServer.__init__(self, BitCharge, 'fpga_inf')

        self.initialization_notice()
    
    def execute_callback(self,goal_handle):
        try:
            ActionParentServer.execute_goal(self, goal_handle) #Inicializar feedback y result
            script = 'script.tcl' # TODO: Aquí hay que hacer el script para encontrar los dispositivos de vivado (.tcl)

            self.send_feedback('Verifying available device') #Envia feedback
            #! Probar que funcionen los comandos y la acción en general
            if not ActionParentServer.devices_vivado(self,script): #Verifica con el script los dispositivos
                raise DeviceNotFoundError() #Lanza exception
            
            self.send_feedback('The device is available') #Feedback

            file_path = goal_handle.request.path_bit#Ruta de archivo .bit
            self.send_feedback(f'Searching file: {file_path}') #Devulve la ruta del archivo como feedback

            if not os.path.exists(file_path):#Comprueba que el archivo exista
                raise FileNotFoundError() #Lanza exceptión personalizada
            
            self.send_feedback('Executing upload to FPGA')#Feedback

            #Ejecuta el comando desde el método de clase
            ActionParentServer.execute_command(self, 'fpga', file_path) #Este solo usa el path

        except DeviceNotFoundError as e:#Haciendo una excepción para los tipos de error
            self.callback_error(e)

        except FileNotFoundError as e:
            self.callback_error(e)#Llamando el método para imprimir errores

        except Exception as e:
            self.callback_error(e)  # Error genérico adicional
            
        finally:
            return self.result #Sin importar que, retorna el resultado

def main(args=None):
    rclpy.init(args=args)
    fpga_inf_server = FPGA_ActionServer()
    rclpy.spin(fpga_inf_server)
    
if __name__ == "__main__":
    main() 