import rclpy
from pvariables.action import VhdlToBit
from rclpy.node import Node
from parent_class import NodeFather, ActionParentServer, PortNotFoundError, DeviceNotFoundError, FileNotFoundError
import os

class VhdlToBitActionServer(Node, NodeFather, ActionParentServer):

    def __init__(self):
        Node.__init__(self,'vhdlToBit_inf_server')
        NodeFather.__init__(self)
        #Se da como parámetro el self, el action_type y el action_name
        ActionParentServer.__init__(self, VhdlToBit, 'vhdlToBit_inf')

        self.initialization_notice()
    
    def execute_callback(self,goal_handle):
        try:
            ActionParentServer.execute_goal(self, goal_handle) #Inicializar feedback y result

            constrains_path = goal_handle.request.path_constrains
            file_path = goal_handle.request.path_vhdl #Ruta de archivos
            self.send_feedback(f'Searching files: {file_path} and {constrains_path}') #Devulve la ruta del archivo como feedback

            if not os.path.exists(file_path) or not os.path.exists(constrains_path):#Comprueba que el archivo exista
                raise FileNotFoundError() #Lanza exceptión personalizada
            
            self.send_feedback('Executing VHDL To Bit Stream')#Feedback

            #Ejecuta el comando desde el método de clase
            ActionParentServer.execute_command(self, 'vhdl_to_bit', file_path, constrains_path) 
            #TODO: Falta el script para convertir el vhdl to bit

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
    vhdlToBit_inf_server = VhdlToBitActionServer()
    rclpy.spin(vhdlToBit_inf_server)
    
if __name__ == "__main__":
    main() 