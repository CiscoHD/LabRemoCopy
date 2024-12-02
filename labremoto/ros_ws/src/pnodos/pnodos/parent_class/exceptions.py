# -------------------------------------------------------------------------#
#*Exceptions de base de datos
#--------------------------------------------------------------------------#
class DataBaseNotConnected(Exception):#*Exception cuando no se logra la conexión con la BBDD
    def __init__(self,msg="Error in database Connection"):
        super().__init__(msg)

class RowNotFoundError(Exception):
    def __init__(self,msg="There are not rows"):
        super().__init__(msg)

class ContractNotValidError(Exception):#*Excepción personalizada para indicar que no se encontró contrato para las acciones
    def __init__(self, msg="Action Contract not found"):
        super().__init__(msg)# Constructor de la clase base (Exception)

class DataNotFoundError(Exception):#*Exception cuando encuentra contrato pero no la info suficiente (solo suposición)
    def __init__(self, msg="Contract data is not complete"):
        super().__init__(msg)# Constructor de la clase base (Exception)
# -------------------------------------------------------------------------#
#*Exceptions de acciones
#--------------------------------------------------------------------------#

class DeviceNotFoundError(Exception):#*Excepción personalizada para indicar que no se encontró el dispositivo
    def __init__(self, msg="Microcontroller not found"):
        super().__init__(msg)# Constructor de la clase base (Exception)

class PortNotFoundError(Exception):#*Excepción personalizada para indicar que no se encontró el puerto
    def __init__(self, msg="Device Port not found"):
        super().__init__(msg)# Constructor de la clase base (Exception)

class CommandExecutionFailedError(Exception): #*Excepción de error al ejecutar comandos
    def __init__(self, msg="Failed on Execution Command"):
        super().__init__(msg)# Constructor de la clase base (Exception)

class FileNotFoundError(Exception):#*Error por no encontrar el archivo
    def __init__(self, msg="File to upload not found"):
        super().__init__(msg)# Constructor de la clase base (Exception)
