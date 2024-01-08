import requests

class Maqueta():
   def __init__(self):
        self.id_maqueta = ""
        self.ultimo_usuario = ""
        self.ultima_modificacion = ""
        self.status = ""


class Sesion():
   def __init__(self):
        self.id_sesion = ""
        self.fecha_inicio = ""
        self.fecha_salida = ""
        self.id_guardado = ""
        self.Maqueta = ""
      

class Usuario():
    def __init__(self):
        self.id = ""
        self.username = ""
        self.nombre = ""
        self.email = ""
        self.admin = False
        self.sesion = False

    def verificacion(self,code):
        tabla = 'Usuario'
        campo= ''
        resp = requests.get(f'http://labrem.ddns.net:8000/api/{tabla}/1/{campo}',timeout=0.01)
        if resp == code:
            return True
    


class Transaccion():

    def __init__(self):
        self.id_transaccion = "" 
        self.id_node = ""
        self.name_node = ""
        self.type_transaction = ""
        self.date_process = ""
        self.id_user = ""
        self.log_process = ""


