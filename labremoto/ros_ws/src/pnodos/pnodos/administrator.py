import rclpy
import time
from pvariables.msg import Contract, TransGlobal
from rclpy.node import Node
from parent_class import NodeFather, NodeConn, ContractNotValidError, main_base

class AdministratorContracts(Node, NodeFather, NodeConn):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'administrator_contracts')
        NodeFather.__init__(self,'top_transactions')
        NodeConn.__init__(self,'/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db',True) 
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(Contract, self.topic_code, self.listener_callback, 10)
        self.subscription_

        #Se fue la linea de publisher_auditor pq ahora el publisher está implementado en la clase parent
        self.publisher_admintrans_ = self.create_publisher(TransGlobal,self.get_code_tema('top_transactions_accepted'),10)
        #Se fue la linea de publisher console por lo mismo de arriba

        self.initialization_notice()
        
    def listener_callback(self, msg):
        try:
            NodeFather.publisher_consoler(self, msg.id_contract, "Request received for contract")
            result, data = NodeConn.request_info_db(self,'contract',msg.id_contract)#Envia mensaje a base de datos para consultar validez
            NodeFather.publisher_consoler(self, data, result) #Publica los resultados
            
            #! Ahora el contrato se va a validar desde aquí (Serái bueno usar un atributo en la fila)
            # ! Falta desarrollar las condiciones para que sea un contrato aceptada o valido
            # TODO Hacer la función de verificación de contratos
            #Comunicación con el backend, a través de ROS BRIDGE se recibe las operaciones y el certificado
            #Enviar al back y esperar TRUE or FALSE (algo por el estílo para verificar que la operación a realizar sea válida)
            #raise ContractNotValidError() #*Usar esta en caso de que después de verificarlo no sea valido 

            #? Mensajes provicional para pruebas - ARDUINO
        #    data = {'result' : 'Pruebas', 'status' : 'accepted', 'name_node' : 'arduino', 'date' : 'TimeActual', 'folio' : 'Assigned by BBDD' }
            #? ESP32
        #    data = {'result' : 'Pruebas', 'status' : 'accepted', 'name_node' : 'esp32', 'date' : time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), 'folio' : 'Assigned by BBDD' }

            data = {'result' : 'Pruebas', 'status' : 'accepted', 'name_node' : 'raspberry', 'date' : time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()), 'folio' : 'Assigned by BBDD' }


            msg_tran_accepted = TransGlobal()#En caso de que salga bien inicia el mensaje con la información que viene de la base
            #TODO: Tal vez agregar aquí otro identificador más explicito para saber la operación a realizar // por ejemplo: action = data.get('type_action) o algo por el estilo
            msg_tran_accepted.result = data.get('result')
            msg_tran_accepted.status = data.get('status')
            msg_tran_accepted.name_node = data.get('name_node')
            msg_tran_accepted.date = data.get('date')
            msg_tran_accepted.folio = data.get('folio')

            NodeFather.publisher_consoler(self,msg_tran_accepted,'Transaction published')
            self.publisher_admintrans_.publish(msg_tran_accepted) #Publica en las transacciones aceptadas
        except ContractNotValidError(e):
            self.callback_error(e)

        except Exception as e:
            self.callback_error(e)

def main(args=None):
    rclpy.init(args=args)
    administrator = AdministratorContracts()
    main_base(administrator)
    
if __name__ == "__main__":
    main() 