from .node_father import NodeFather
import rclpy 
from rclpy.action import ActionClient

class ActionParentClient:
    # Se usa como parámetro action_type, que es la acción personalizada .action
    def __init__(self,action_type, action_name):
        #Crea una instancia de cliente de acción con el action_type
        self._action_client = ActionClient(self,action_type, action_name)
        #Usa el action_name para nombrar la acción según el parámetro
        self.action_type = action_type
    
    #Falta implementar la recepción de feedback
    def feedback_callback(self,feedback_msg):
        #Recibiendo feedback del action_server y publicando en consola
        NodeFather.publisher_consoler(self,feedback_msg.feedback.status,'Feedback')

    def send_goal(self, path, path_constrains=None):
        #Crea una goal con el tipo de Action usado
        goal_msg = self.action_type.Goal()
        #Asigna las rutas a los atributos del goal
        if path_constrains is None:
            #Depende de los argumentos el atributo creado
            goal_msg.path_hex = path
        else:
            # Solo un condicional porque solo son 2 tipos de atributos para las Actions
            goal_msg.path_vhdl = path
            goal_msg.path_constrains = path_constrains

        #Utiliza el método de action_client que es una instancia del mismo objeto (Hijos de esta clase en cada caso)
        self._action_client.wait_for_server()
        # Agrega callback function para recibir el feedback
        self._send_goal_future = self._action_client.send_goal_async(goal_msg,feedback_callback=self.feedback_callback)
        # Agrega callback para cuando la action finalice
        self._send_goal_future.add_done_callback(self.goal_response_callback)
        
    def goal_response_callback(self, future): #Usa el future
        goal_handle = future.result() #Obtiene el resultado del future
        if not goal_handle.accepted: #Verifica que haya sido aceptada
            NodeFather.publisher_consoler(self,'Goal rejected.')
            return #En caso de error del server

        NodeFather.publisher_consoler(self,'Goal accepted.')

        #Obtiene los resultados de manera asincrona
        self._get_result_future = goal_handle.get_result_async()
        #Teniendo el resultado, llama la callback para utilizarlo
        self._get_result_future.add_done_callback(self.get_result_callback)
    
    def get_result_callback(self,future): #Usa el futuro
        result = future.result().result.status_final #Obtiene el resultado
        #Publica en consola el resultado de la acción que fue enviada 
        NodeFather.publisher_consoler(self,result,'Action result')
        #Crea un mensaje del auditor utilizando la función en la clase padre
        NodeFather.auditor_msg(self, logprocess=f"Goal sent from {self.get_name()} and result {result}", typetransaction="Goal Finished")
        
        # rclpy.shutdown() #Comentado para que no detenga la ejecución del nodo y acepte muchas acciones
    
    #* Esta función es predeterminada para cada action client, se debe soobreescribir en cada nodo. El parámetro de mensaje se envía en cada nodo desde su propia listener_callback a esta callback de la clase parent.
    def function_callback(self, msg): #Recupera el mensaje que viene desde la instancia y la listener_callback
        #Se ahorra la variable que era la instancia de esta misma clase para solo usar self
        if msg.path_hex != None:
            #Si sí existe, se usa el path_hex
            self.send_goal(msg.path_hex)
        else:
            #Si no existe el path_hex se trabaja con vhdl
            self.send_goal(msg.path_vhdl, msg.path_constrains)
        #Si path_constrains (Config para la tarjeta de interconexión) es None la función de send_goal lo toma para solo usar al path_hex