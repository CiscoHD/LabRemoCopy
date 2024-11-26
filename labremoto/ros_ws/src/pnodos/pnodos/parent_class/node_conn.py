import sqlite3

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
            "admin" : """ SELECT * FROM CONTRATOS WHERE IdContrato = ?;""",
            "input_transactioner" : """ SELECT * FROM USUARIOS WHERE Id = ?;"""
        }
        self.diction_db_errors = {
            # * Poner los errores
            # Type error | Descr error
            "default": ('Database Error', 'Database error, try again.'),
            "admin" : ('Transaction Error', 'Transaction not found.'),
            "admin_condition": ('Transaction Error', 'Transaction Rejected.'),
            "input_transactioner" : ('Transaction Error',"Transaction cannot be processed")
        }
        
    def connection(self):
        if self.mode_dev:
            try:
                conn = sqlite3.connect(self.url)
                cur = conn.cursor()
            except sqlite3.Error as e:
                return None, 'Error in database connection.'
            return conn,cur
        # ------------------------ API ------------------------------

    def insert_log_db(self, tuple_db, sentence): #Tuple_db se pasa como tupla con toda la info del mensaje
        if self.mode_dev:
            conn,cur = self.connection()
            if conn is not None:
                msg = ('Success')
                try:
                    #Busca la sentencia correspondiente en el diccionario
                    sentence_db = self.diction_db.get(f"{sentence}")
                    #Ejecuta la sentencia con los datos de la tupla
                    cur.execute(sentence_db, tuple_db)
                except(sqlite3.Error):
                    #Regresa el mensaje en caso de error
                    msg = self.diction_db_errors.get("default")
                finally:
                    #Al final, cierra el cursor y la conexión
                    conn.commit()
                    cur.close()
                    conn.close()
                    return msg
                
    def request_info_db(self, sentence, conditional_id):
        if self.mode_dev:
            conn,cur = self.connection()
            data = None
            if conn is not None:
                msg = ('Transaction Accepted')
                try:
                    #Busca la sentencia correspondiente en el diccionario
                    sentence_db = self.diction_db.get(f"{sentence}")
                    #Ejecuta la sentencia con los datos de la tupla
                    
                    sentence_2 = "SELECT * FROM CONTRATOS WHERE IdContrato = ?;"
                    n_contracts = 0
                    for contract in cur.execute(sentence_db, (conditional_id,)):
                        print(contract)
                        n_contracts = n_contracts +1
                    #Si viene desde el nodo administrator y no hay resultados
                    if n_contracts  < 1:
                        #Asigna error por defecto buscando en el diccionario
                        msg = self.diction_db_errors.get(f"{sentence_db}") 
                        #Asigna otro tipo de error según una condición
                        # ! Falta desarrollar las condiciones para que sea una transacción aceptada
                        #Comunicación con el backend, a través de ROS BRIDGE se recibe las operaciones y el certificado
                        #Enviar al back y esperar TRUE or FALSE
                        # TODO Hacer la función de verificación de contratos
                    #Condicion en caso de que solo la sentencia caso admin encuentre contratos
                    #if (sentence_db == "admin" and n_contracts>0) or True == True:                        #Busca los errores del admin en la condition por desarrollar
                    else:
                        #!regresa el mensaje  #! Hay que revisar lo que devuelve la BBDD
                        #! Mensaje provicional para pruebas
                        data = {'result' : 'Pruebas', 'status' : 'accepted', 'name_node' : '', 'date' : 'TimeActual', 'folio' : 'Assigned by BBDD' }
                        #msg = self.diction_db_errors.get(f"{sentence_db}_condition")
                except(sqlite3.Error):
                    #Regresa el mensaje en caso de error
                    msg = self.diction_db_errors.get("default")
                finally:
                    #Al final, cierra el cursor y la conexión
                    conn.commit()
                    cur.close()
                    conn.close()
                    return msg, data
