import ROSLIB from 'roslib';
import { createContext } from 'react';
import { useState, useEffect } from 'react';


import {ip_server} from '../components/reducer';


export const RosContext = createContext();

export function RosProvider(props) {
  const [status, setStatus] = useState('Not connected');
  const [isConnected, setIsConnected] = useState(false);
  const [consoleLog, setConsoleLog] = useState([
    {lstnr: 'Listener #1',
      mssg: `La consola ${
        !isConnected?'':'NO'} se ha conectado 
        ${!isConnected?' exitosamente! :)':':('}`}
  ]);

  const defaultConfig = {
    url: `ws://${ip_server}:2090`,
    // url: `ws://localhost:2090`,
  };

  const ros = new ROSLIB.Ros({encoding: 'ascii', url: defaultConfig.url});
    
  ros.on("connection", function() {
    setStatus("Connected");
    setIsConnected(true);
  })

  ros.on("close", function() {
    setStatus("Not connected");
    if(consoleLog.includes(
      { lstnr: 'Listener #1',
        mssg: `La consola ${!isConnected?'':
        'NO'} se ha conectado ${!isConnected?' exitosamente! :)':
        ':('}`
      }
    )){
        setConsoleLog([...consoleLog,
          {lstnr: 'Listener #1',
          mssg: `La consola ${!isConnected?'':
          'NO'} se ha conectado ${!isConnected?' exitosamente! :)':
          ':('}`}
        ])
    }
    setIsConnected(false);
  })

  ros.on("error", function(error) {
    console.log("Error connecting to websocket server =(: ", error);
  })


  const fileTopic = new ROSLIB.Topic({
    ros : ros,
    name : '/top_transacciones_entrada',
    messageType : 'my_mas/msg/TransEntrada'
  });

  var CargaHexTopic = new ROSLIB.Topic({
    ros : ros,
    name : '/archivos_hex',
    messageType : 'my_mas/msg/FileHexLoad'
  });
  
  const TransformBitTopic = new ROSLIB.Topic({
    ros : ros,
    name : '/top_create_bit',
    messageType : 'my_mas/msg/CreateBitStream'
  });
  
  const CargaBitTopic = new ROSLIB.Topic({
    ros : ros,
    name : '/top_archivo_bit',
    messageType : 'my_mas/msg/FileBitLoad'
  });

  const listener = new ROSLIB.Topic({
    ros : ros,
    name : '/top_consola',
    messageType : 'my_mas/msg/LogSalida'
  });

  function pubMessage(){
    const msg = new ROSLIB.Message({
      tipotransaccion : 'carga_hex',
      idestudiante : '1' ,
      idsesion : '1'
    });
    fileTopic.publish(msg);
  }

  const pathhex='/un/archivo/ficticio.hex'

  //Arduino
  function CargaHexpubMessage(){
      const msg = new ROSLIB.Message({
        path_hex : 'pathhex.hex',
        status : 'encendido'
      });
      CargaHexTopic.publish(msg);
      console.log('Cargando hex...');
      CargaHexTopic.unsubscribe();


      CargaHexTopic = new ROSLIB.Topic({
        ros : ros,
        name : '/archivos_hex',
        messageType : 'my_mas/msg/FileHexLoad'
      });
    }
  //Transformar
  function TransformBitTopicpubMessage(){
      const pathvhdl = '';
      const pathconstrains = '';
      const pathsavefolder = '';

      const msg = new ROSLIB.Message({
      path_vhdl : pathvhdl,
      path_constrains : pathconstrains,
      path_savefolder : pathsavefolder
      });
      TransformBitTopic.publish(msg);
    }
  //Carga
  function CargaBitTopicpubMessage(){
      const msg = new ROSLIB.Message({
        path_bit : pathhex,
        status : 'encendido'
      });
      CargaBitTopic.publish(msg);
    }

  listener.subscribe( function(message) {
    console.log("Received message on " + listener.name + ": " + message.logsalida);
    setConsoleLog([...consoleLog,{
      lstnr: listener.name,
      mssg:  message.logsalida
  }])
    listener.unsubscribe();
  });

  



  return (
    <RosContext.Provider value={{ ros, status, isConnected, listener,
    pubMessage, 
    CargaHexpubMessage, TransformBitTopicpubMessage, CargaBitTopicpubMessage,
    // Variables
    consoleLog,
    //Functions
    setConsoleLog,
     }}>
      {props.children}
    </RosContext.Provider>
  );
}