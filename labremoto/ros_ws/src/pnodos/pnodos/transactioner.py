import rclpy
from pvariables.msg import TransGlobal, FileHexLoad, FileBinLoad, FilePyLoad, CreateBitStream
from rclpy.node import Node
from parent_class import NodeFather, main_base

#Nodo para manejar publiaciones en consola
class AdminTransactioner(Node, NodeFather):
    
    def __init__ (self):
        #Agregar self a la inicialización de clases
        Node.__init__(self,'admin_transactioner')
        NodeFather.__init__(self,'top_transactions_accepted')
    
        #Agregar self al topic_code para acceder al creado en node_father
        self.subscription_ = self.create_subscription(TransGlobal, self.topic_code, self.listener_callback, 10)
        self.subscription_

        self.publisher_arduino_ = self.create_publisher(FileHexLoad, self.get_code_tema('top_files_hex'), 10)
        self.publisher_bit_ = self.create_publisher(CreateBitStream, self.get_code_tema('top_files_bit'), 10)
        self.publisher_esp32_ = self.create_publisher(FileBinLoad, self.get_code_tema('top_files_bin'),10)
        self.publisher_raspberry_ = self.create_publisher(FilePyLoad, self.get_code_tema('top_files_py'),10)

        self.initialization_notice()
        
    def listener_callback(self, msg):
        #Recibe mensajes para consola y los imprime
        NodeFather.publisher_consoler(self, msg.folio, "Accepted Transaction Received. Folio")

        msg_type = CreateBitStream()
        # TODO En esta variable se podría crear una función que busque u obtenga el archivo
        # ! Podría ser con el folio que se pasa en el mensaje y después buscar el archivo en DB
        #file_path = '/home/laboratorio_remo_remasterizado/labremoto/files/build/blink.ino.hex'
        #* Path del binario para la esp32
        #file_path = '/home/laboratorio_remo_remasterizado/labremoto/files/build/blink.ino.with_bootloader.bin'
        #* Path del archivo py para raspberry
        file_path = '/home/laboratorio_remo_remasterizado/labremoto/files/prueba_rasp.py'
        #* Usando path de archivo de prueba
        #? de dónde vendrá este path? En dónde estará ubicado?
        type_action = None
        if msg.name_node == 'arduino': #Revisar si puedo poner otro parámetro para distinguir el tipo de acción
            msg_type = FileHexLoad()
            msg_type.path_hex = file_path
            type_action = 'Arduino'
            self.publisher_arduino_.publish(msg_type)

        elif msg.name_node == 'vhdl':
            msg_type = CreateBitStream()
            msg_type.path_vhdl = file_path
            type_action = 'VHDL'
            self.publisher_bit_.publish(msg_type)

        elif msg.name_node == 'esp32':
            msg_type = FileBinLoad()
            msg_type.path_bin = file_path
            type_action = 'ESP32'
            self.publisher_esp32_.publish(msg_type)
            
        elif msg.name_node == 'raspberry':
            msg_type = FilePyLoad()
            msg_type.path_py = file_path
            type_action = 'Raspberry'
            self.publisher_raspberry_.publish(msg_type)

        NodeFather.publisher_consoler(self, type_action, "Selecting type action")
    
def main(args=None):
    rclpy.init(args=args)
    admin_transactioner = AdminTransactioner()
    main_base(admin_transactioner)
    
if __name__ == "__main__":
    main() 