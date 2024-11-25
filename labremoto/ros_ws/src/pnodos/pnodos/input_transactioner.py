import rclpy
from pvariables.msg import Contract, TransInput
from rclpy.node import Node
from parent_class import NodeFather, NodeConn, main_base

#Nodo para manejar publiaciones en consola
class InputTransactioner(Node, NodeFather, NodeConn):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'input_transactioner')
        #Suscripción al topic de ros_Bridge
        NodeFather.__init__(self,'top_transactions_input')
    
        #Agregar self al topic_code para acceder al creado en node_father
        #El topic aqui pasa directo para hacer pruebas con publicar desde terminal
        # ! Debe de ir el topic o del objeto self, o del metodo get_code_tema
        self.subscription_ = self.create_subscription(TransInput, 'top_transactions_input', self.listener_callback, 10)
        self.subscription_

        self.publisher_contract_ = self.create_publisher(Contract, self.get_code_tema('top_transactions'), 10)

        self.initialization_notice()
        
    def listener_callback(self, msg):
        # # * Comando de prueba
        # #ros2 toc pub /input_transactioner pvariables/TransInput "{type_transaction : 'charge_hex', status : 'des', id_student : 'des', id_session : 'des', description : 'desc'}"
        # NodeFather.publisher_consoler(self,msg.type_transaction,"Input transaction received")
        # result,data = NodeConn.request_info_db(self, "input_transactioner", msg.id_student)
    
        # if result > 1:
        #     #Si hay errores los imprime en consola  
        #     NodeFather.publisher_consoler(self,result[1],result[0])
        # elif msg.type_transaction == "charge_hex":
            msg_contract = Contract()
            ## ? Por qué el id 4?
            ## ! Hay que revisar que tal vez aquí se envie el id del estudiante
            #! -------- Falta cambiar para usar la variable data para armar el mensaje
            msg_contract.id_contract = 4
            msg_contract.name_contract = 'charge'
            msg_contract.type_contract = 'hex'
            msg_contract.desc_contract = msg.description

            # ? Qué especificación usa el mensaje del contrato
            msg_contract.specification_contract
            self.publisher_contract_.publish(msg_contract)
            #Si no hay errores, continua...
        # ** Posiblemente después aquí se agregué la funcionalidad
        # ** de los archivos bit para también enviar el contrato al administrator
        #elif msg.type_trasaction == "charge_bit"

    
def main(args=None):
    rclpy.init(args=args)
    input_transactioner = InputTransactioner()
    main_base(input_transactioner)
    
if __name__ == "__main__":
    main() 