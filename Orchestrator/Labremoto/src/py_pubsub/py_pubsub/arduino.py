import subprocess
import shlex
import unittest

import pandas as pd
import os
import json

def devices_arduino_info():
    try:
        dispositivos = pd.concat(list(map(pd.json_normalize,json.loads(os.popen("arduino-cli board list --format json").read()))))
        return dispositivos
    except ValueError:
        return "No dispositivos conectados" 


class FailureCommandException(Exception):
  """
  Attributes
  ----------

  message : str
    Message of the error 
  """
  def __init__(self, message = "Error: "):
    self.message = message
    super().__init__(self.message)
  

class ExecuteCommand():
  """
  Ejecutor de comandos en la terminal de linux.
  
  ...
  
  Attributes
  ----------
  output : str
  	Salida del comando ejecutado en la terminal.
  args : list
  	Comando de terminal a ejecutar en formato de lista de argumentos.
  warning : list
    Lista de advertencias tras la ejecución del comando.
  error : str
    Error obtenido tras la ejecución del comando.
  """
  
  def __init__(self):
     self.output = ""
     self.args = []
     self.warning = ""
     self.error = ""

  def execute(self, command):
    """
    Ejecuta el comando en un subproceso y guarda los datos de salida.
    
    Parameters
    ----------
    command: str
    	Comando que sera ejecutado en terminal.
    """
    self.args = shlex.split(command)
    process = subprocess.Popen(self.args, 
                              stdout=subprocess.PIPE, 
                              stderr=subprocess.PIPE, 
                              text=True)
    try:
      self.output, stderr = process.communicate(timeout=10)
      try:
        if process.poll() != 0:
          self.checkErrors(stderr)
        else:
          if len(self.output) == 0 and len(stderr) != 0:
            self.output, stderr = stderr, self.output
            self.checkWarnings(self.output)
            self.warning = stderr
      except FailureCommandException as e:
        print(e.message) # Envio del mensaje de regreso al nodo
    except subprocess.TimeoutExpired as e:
      process.kill()
      self.error = e.stderr
      print(e.stdout)
      print("ERROR: Tiempo de espera de ejecución excedido: \n\n " + self.error)

  def checkErrors(self, stderr):
    """
    Obtiene los errores tras la ejecución del comando.

    Raises
    ------

    FailureCommandException : Error with the execution of the command.
    """
    if stderr != "":
      self.error = stderr
      raise FailureCommandException("ERROR: Error en la ejecución de la instrucción. Salida de la ejecución: \n\n " + (self.error))
    
  def checkWarnings(self, output):
    """
    Obtiene las advertencias tras la ejecución del comando.
    """
    if output.casefold().find("warning") > 0:
      self.warning = output


class TestArduinoCLI(unittest.TestCase):
  def setUp(self) -> None:
    self.executer = ExecuteCommand()
    print("\n[Metodo: " + self._testMethodName + "]\n")
  
  def testCompilationSuccess(self,FQBN,sketch_path):
    command = f"arduino-cli compile --fqbn {FQBN} {sketch_path}"
    self.executer.execute(command)
    self.assertEqual(self.executer.error, "","No hay errores en la compilación")
    self.assertEqual(self.executer.warning, "","No hay advertencias en la compilación")
    print(self.executer.output)
  
  def testCompilationFailure(self,FQBN,sketch_path):
    command = f"arduino-cli compile --fqbn {FQBN} {sketch_path}"
    self.executer.execute(command)
    self.assertNotEqual(self.executer.error, "", "Error en la compilación")
    print(self.executer.error)

  def testWarnings(self,FQBN,sketch_path):
    command = f"arduino-cli compile --warnings -Wall --fqbn {FQBN} {sketch_path}"
    self.executer.execute(command)
    self.assertNotEqual(self.executer.warning, "", "Hay advertencias en la compilación")
    print(self.executer.warning)


  def testUploadSuccess(self,PORT,sketch_path, binary = False):
    if binary:
      command = f"arduino-cli upload -i {sketch_path} -p {PORT} "
    else:
      command = f"arduino-cli upload {sketch_path} -p {PORT} "
    
    #"avrdude -patmega328p -carduino -b115200 -P /dev/ttyUSB0 -D -Uflash:w:./arduino/output/arduino_test.ino.hex"
    self.executer.execute(command)
    self.assertEqual(self.executer.error, "", "No hay errores en la compilación")
    self.assertEqual(self.executer.warning, "", "No hay advertencias en la compilación")
    print(self.executer.output)


  def testUploadFailure(self,PORT,sketch_path):
    command = f"arduino-cli -p {PORT} upload {sketch_path}"
    #"avrdude -patmega328p -carduino -b115200 -P /dev/ttyUSB0 -D -Uflash:w:./arduino/output/arduino_test.ino.he"
    self.executer.execute(command)
    self.assertNotEqual(self.executer.error, "", "Error en la carga")
    print(self.executer.error)

if __name__ == "__main__":
  unittest.main()