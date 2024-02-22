
import ROSLIB from 'roslib';
import { createContext } from 'react';
import { useState } from 'react';

export const rosContext = createContext();


export function RosProvider(props) {
  const [status, setStatus] = useState("Not connected");
  const [isConnected, setIsConnected] = useState(false);
  const defaultConfiguration = {
    url: 'ws://localhost:9090',
  };
  const ros = new ROSLIB.Ros({encoding: 'ascii', url: defaultConfiguration.url});

  ros.on("connection", function() {
    setStatus("connected");
    setIsConnected(true);
  })

  ros.on("close", function() {
    setStatus("Not connected");
    setIsConnected(false);
  })

  ros.on("error", function(error) {
    console.log("Error connecting to websocket server: ", error);
  })

  const fileTopic = new ROSLIB.Topic({
    ros : ros,
    name : '/top_transacciones_entrada',
    messageType : 'my_mas/msg/TransEntrada'
  });

  function pubMessage(){
    const msg = new ROSLIB.Message({
      tipotransaccion : 'CargaHex',
      status : 'Peticion',
      idestudiante : '1',
      idsesion : '1',
      descripcion : ''
    });
    fileTopic.publish(msg);
  }

  const listener = new ROSLIB.Topic({
    ros : ros,
    name : '/top_consola',
    messageType : 'my_mas/msg/LogSalida'
  });

  listener.subscribe( function(message) {
    console.log("Received message on " + listener.name + ": " + message.file);
    listener.unsubscribe();
  });


  return (
    <rosContext.Provider value={{ros, status, isConnected, pubMessage}}>
      {props.children}
    </rosContext.Provider>
  );

}