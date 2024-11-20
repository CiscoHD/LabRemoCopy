import sqlite3

conn = sqlite3.connect("/home/laboratorio_remo_remasterizado/labremoto/files/db_develop.db")
cur = conn.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS SUPERVISOROPERACIONES(nameoperacion text, DescOperacion text, EstatusOperacion text, FechaOperacion text, TopicOperacion text)")
cur.execute("CREATE TABLE IF NOT EXISTS TRANSACCIONESAUDITOR(IdNode integer, NameNode text, TipoTransaccion text, FechaTransaccion text, IdUser text, LogProceso text)")
cur.execute("CREATE TABLE IF NOT EXISTS CONTRATOS(IdContrato integer, result text, status text,name_node text,date text,folio text)")

# * ---- Insertar datos de prueba
#cur.execute("""INSERT INTO SUPERVISOROPERACIONES( nameoperacion, DescOperacion, EstatusOperacion, FechaOperacion, TopicOperacion) VALUES (?, ?, ?, ?, ?);""",("h1","h2","h3","h4","h5"))
#cur.execute("""INSERT INTO TRANSACCIONESAUDITOR (IdNode, NameNode, TipoTransaccion, FechaTransaccion, IdUser, LogProceso) VALUES (?, ?, ?, ?, ?, ?);""", (0, "nodo", "txt", "", "", ""))

# * Ver las tablas existentes
# tables = cur.execute("SELECT * FROM sqlite_master WHERE type = 'table';")
# for table in tables:
#     print(table)

print("Results:")
# * Imprimir filas de las tablas
#for row in cur.execute("SELECT * FROM CONTRATOS"):
#    print(row)

sentence_2 = "SELECT * FROM CONTRATOS WHERE IdContrato = ?;"
conditional_id = 4
n_contratos = 0
for row in cur.execute(sentence_2, (conditional_id,)):
    print(row)
    n_contratos = n_contratos +1
print(f"MN: {n_contratos}")
# sentence = "INSERT INTO CONTRATOS (IdContrato, result, status, name_node, date, folio) VALUES (?, ?, ?, ?, ?, ?) "
# data = (7, 'sucess', 'success', 'nodo_pruebas', '03/10/2024','folio')
# result = cur.execute(f"{sentence_2}", (4,))

conn.commit()
cur.close()
conn.close()