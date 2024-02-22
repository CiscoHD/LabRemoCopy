import rclpy
from rclpy.node import Node
from my_mas.msg import TransGlobal
import sqlite3



class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__('Supervisor_tran')
        self.subscription = self.create_subscription(
            TransGlobal,
            'supervisor',
            self.listener_callback, 10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f"Leido {msg.folio}")
        conexion = sqlite3.connect('/home/ffelix07/Documents/LabRemo/Orchestrator/LABREMODB.cdb3')
        cursor = conexion.cursor()
        query2 =  f""" INSERT INTO TRAN VALUES {(msg.folio,msg.name_node,msg.fecha,msg.resultado)};"""
        cursor.execute(query2)
        conexion.commit()
        conexion.close()
        self.get_logger().info(f"Guardado {msg.folio} from {msg.name_node}")
            
#            except:
#                conexion.close()
#                self.get_logger().info("Error al cargar la información")
#        except:
#            self.get_logger().info("Error al conectar con la base de datos")
            


def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
