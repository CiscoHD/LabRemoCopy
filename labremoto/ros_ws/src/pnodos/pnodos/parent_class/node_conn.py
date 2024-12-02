import sqlite3
from .node_father import NodeFather
from .exceptions import DataBaseNotConnected, RowNotFoundError

class NodeConn:
    #Definir como false o True según si está en produccion (api) o en desarrollo (sqlite)
    def __init__(self, url='/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db', dev = False): #Por defecto en producción
        self.mode_dev = dev #Hay que enviar argumento como True para entrar en modo dev
        self.url = url
        #Diccionario para cada sentencia usada para comunicarse a base de datos
        self.diction_db = {
            # * ----------------- Agregué el topic code a la sentencia de supervisor
            "supervisor" : """INSERT INTO SUPERVISOROPERACIONES( nameoperacion, DescOperacion, EstatusOperacion, FechaOperacion, TopicOperacion) VALUES (?, ?, ?, ?, ?);""",
            "auditor" : """INSERT INTO TRANSACCIONESAUDITOR (IdNode, NameNode, TipoTransaccion, FechaTransaccion, IdUser, LogProceso) VALUES (?, ?, ?, ?, ?, ?);""",
            "contract" : """ SELECT * FROM CONTRATOS WHERE IdContrato = ?;""",
            "input_transactioner" : """ SELECT * FROM USUARIOS WHERE Id = ?;"""
        }
        
    def connection(self):
        if self.mode_dev:
            try:
                conn = sqlite3.connect(self.url)
                cur = conn.cursor()
            except sqlite3.Error as e:
                self.callback_error(e)
                return None, None
            return conn,cur
        # ------------------------ API ------------------------------
        #TODO: Conexión con API

    def insert_log_db(self, tuple_db, sentence): #Tuple_db se pasa como tupla con toda la info del mensaje
        if self.mode_dev:
            try:
                conn,cur = self.connection() #Trata de establecer conexión
                if conn is None or cur is None: #Si no están definidos, no hay conexión
                    raise DataBaseNotConnected()
                msg = ('Success')#Si todo va bien
                
                sentence_db = self.diction_db.get(f"{sentence}")#Busca la sentencia correspondiente en el diccionario
                cur.execute(sentence_db, tuple_db)#Ejecuta la sentencia con los datos de la tupla

            except DataBaseNotConnected as e:
                self.callback_error(e)
                msg = str(e)

            except sqlite3.Error as e:
                self.callback_error(e)
                msg = str(e)#Regresa el mensaje en caso de error

            finally:
                #Al final, cierra el cursor y la conexión
                conn.commit()
                cur.close()
                conn.close()
                return msg
                
    def request_info_db(self, sentence, conditional_id): #Solicitar información a base de datos
        if self.mode_dev:
            conn,cur = self.connection()
            data = None #Variable para guardar la información que es solicitada
            try:
                if conn is None or cur is None:
                    raise DataBaseNotConnected()
                msg = ('Transaction Accepted')
                
                sentence_db = self.diction_db.get(f"{sentence}")#Busca la sentencia correspondiente en el diccionario

                n_rows = 0#Ejecuta la sentencia con el condicional_id (para delimitar las consulta que se haya hecho
                for row in cur.execute(sentence_db, (conditional_id,)): #Se usa la coma para dejarlo como formato de tupla (,,)
                    NodeFather.publisher_consoler(self,row,f'Row N{n_rows+1}') #imprime cada fila que coincida
                    n_rows = n_rows + 1
                    data = row #Guarda la información de la fila

                if n_rows  < 1 or data is None: #Si no hay contratos, lanza excepción
                    raise RowNotFoundError()

            except RowNotFoundError as e:
                self.callback_error(e)
                msg = str(e)

            except sqlite3.Error as e:
                self.callback_error(e)
                msg = str(e)#Regresa el mensaje en caso de error
            finally:
                conn.commit()#Al final, cierra el cursor y la conexión
                cur.close()
                conn.close()
                return msg, data
                
    def callback_error(self,e="unexpected error"):
        NodeFather.publisher_consoler(self,str(e),'Error')
