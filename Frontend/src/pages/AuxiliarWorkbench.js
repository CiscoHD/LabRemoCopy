import React, { useEffect, useCallback, useRef, useState, useContext } from "react";

import ReactFlow, {
  useNodesState,
  useEdgesState,
  addEdge,
  Controls,
  Position,

} from "reactflow";
import "reactflow/dist/style.css";
// import "../components/Workbench/Utils/nodesandpaths.css"

//se importa nuestro tipo de nodo
import ImageNode from "../components/Workbench/Utils/ImageNode";
import ServoNode  from "../components/Workbench/Utils/ServoMotor";

//importacion de imagenes de los componentes
import A_MotorDC from '../media/Dispositivos/Actuadores (A-G)/A_MotorDC.png';
import B_MotorDCx2 from '../media/Dispositivos/Actuadores (A-G)/B_MotorDCx2.png';
import E_Servomotor from '../media/Dispositivos/Actuadores (A-G)/E - Servomotor.png';
import G_Selenoide from '../media/Dispositivos/Actuadores (A-G)/G-Selenoide.png';
import H_RGB from '../media/Dispositivos/Luces (H-K)/H - RGB.png';
import J_7Segmentos from '../media/Dispositivos/Luces (H-K)/J - 7segmentos.png';
import K_DisplayI2C from '../media/Dispositivos/Luces (H-K)/K - Display I2C.png';
import L_LDR from '../media/Dispositivos/Sensores (L-O)/L-LDR.png';
import M_AHT10 from '../media/Dispositivos/Sensores (L-O)/M-aht10.png';

import Arduino from '../media/Boards/ArduinoMEGA.png';
import ZedBoard from '../media/Dispositivos/Programables (P-R)/Zedboard.png';
import ESP32 from '../media/Boards/Esp32nodemcubis_2.png';

import ImageActuador from "../components/Workbench/Pictures/Actuador.png";
import ImageArduino from "../media/Boards/Arduino.png";
import ImageSensorHall3144 from "../components/Workbench/Pictures/Arduino.png";
import ImageServoMotor from "../components/Workbench/Pictures/servomotorSF.png";
import Servo from "../components/Workbench/Pictures/Servo.png"

import { v4 as uuidv4 } from "uuid";
import { MenuContext } from "../context/MenuContext";



const uniqueId = () => uuidv4();

const connectionLineStyle = {
  strokeWidth: 2, // Ancho de la línea de conexión
  stroke: '#0D9276', //"orange", // Color de la línea de conexión (puedes cambiar este color)
  type: "smoothstep",
  // type: 'beizer'
};

const snapGrid = [2,2];
const nodeTypes = {
  imageNode: ImageNode,
};
const defaultViewport = { x: 0, y: 0, zoom: 1.5 };

const handleDragOver = (event) => {
  event.preventDefault();
};

const reactflow = {
  width: "70%",
  height: "80vh",
  borderStyle: "solid",
  top: "10em",
};

export function Savestatus(reactFlowInstance) {
  if (reactFlowInstance) {
    const flow = reactFlowInstance.toObject();
    const UserStatus = JSON.stringify(flow);
    //send User status to database
  }
}

const CustomNodeFlow = ({ setFunctions, functions }) => {
  const reactFlowWrapper = useRef(null);
  const [nodes, setNodes, onNodesChange] = useNodesState([]);
  const [edges, setEdges, onEdgesChange] = useEdgesState([]);
  const [reactFlowInstance, setReactFlowInstance] = useState(null);

  const menuContext = useContext(MenuContext);

  //Guardar Informacion del usuario
  function Savestatus() {
    console.log("Saving status....123");
    if (reactFlowInstance) {
      const flow = reactFlowInstance.toObject();
      const UserStatus = JSON.stringify(flow);
      console.log(UserStatus);;

      //send User status to database
      console.log("Sending status to DB", UserStatus);
    }
  }

  function AddNodes(node) {
    //
    console.log("adding nodes... 123", node);
    /*
    setNodes((nds) => nds.concat(newNode));
    console.log(type)
  
  [reactFlowInstance]
  */
  }
  //Cargar estado de la mesa 
  const LoadUserInfo = useCallback(() => {
    //const { x = 0, y = 0, zoom = 1 } = flow.viewport;
    const restoreFlow = async () => {
      //recibir info del estado de la mesa
      const flow = JSON.parse();

      if (flow) {
        setNodes(flow.nodes || []);
        setEdges(flow.edges || []);
      }
    };

    restoreFlow();
  }, [setNodes]);


  useEffect(() => {
    menuContext.setFunctions({
      save: Savestatus,
      add: AddNodes,
    });

    setNodes([]);
    setEdges([]);
    
  }, [setEdges, setNodes]);

  const onConnect = useCallback(
    (params) =>
      setEdges((eds) =>
        addEdge({ 
          ...params,
          animated: false,
          style: { stroke: "#0D9276", strokeWidth: 2,},
          type: 'smoothstep', 
        }, eds)
      ),
    [setEdges]
  );

  //parte donde se arrastran los componentes a la side bar
  const onDrop = useCallback(
    (event) => {
      event.preventDefault();
      const reactFlowBounds = reactFlowWrapper.current.getBoundingClientRect();
      const type = event.dataTransfer.getData("application/reactflow");

      // check if the dropped element is valid
      if (typeof type === "undefined" || !type) {
        return;
      }
      const position = reactFlowInstance.project({
        x: event.clientX - reactFlowBounds.left,
        y: event.clientY - reactFlowBounds.top,
      });

      let newNode;

      switch (type) {
        //Actuadores
        case "DcMotor": {
          newNode = {
            id: "A",
            type: "imageNode",
            data: {
              image: {
                url: A_MotorDC,
                alt: "DcMotorG",
              },
              size: {
                x: "80px",
                y: "62px",
              },
              handles: [
                {
                  type: "target",
                  id: "PWM",
                  position: Position.Left,
                  style: { left: "1%", bottom:"46.5%",background: "#ff0000" },
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "DcMotorx2": {
          newNode = {
            id: "B",
            type: "imageNode",
            data: {
              image: {
                url: B_MotorDCx2,
                alt: "DcMotorx2",
              },
              size: {
                x: "128px",
                y: "128px",
              },
              handles: [
                {
                  type: "target",
                  id: "ENB",
                  position: Position.Left,
                  style: { left: "13%", top: '38%', background: "#ff0000"},
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 4",
                  position: Position.Left,
                  style: { left: "13%", top: '44%', background: "#fffd00" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 3",
                  position: Position.Left,
                  style: { left: "13%", top: '49%', background: "#ff0000" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 2",
                  position: Position.Left,
                  style: { left: "13%", top: '54%', background: "#ff0000" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 1",
                  position: Position.Left,
                  style: { left: "13%", top: '59%', background: "#ff0000" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "ENA",
                  position: Position.Left,
                  style: { left: "13%", top: '65%', background: "#ff0000"},
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "SteeperA": {
          newNode = {
            id: "C",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "SteeperA",
              },
              size: {
                x: "275px",
                y: "275px",
              },
              handles: [
                {
                  type: "target",
                  id: "IN 1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 2",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 3",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "IN 4",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "SteeperB": {
          newNode = {
            id: "D",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "SteeperB",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "STEP",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "DIRECTION",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Servomotor": {
          newNode = {
            id: "E",
            type: "imageNode",
            data: {
              image: {
                url: E_Servomotor,
                alt: "Servomotor",
              },
              size: {
                x: "100",
                y: "77px",
              },
              handles: [
                {
                  type: "target",
                  id: "PWM",
                  position: Position.Left,
                  style: { left: "8%", top: '45%', background: "#ff0000" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Brushless": {
          newNode = {
            id: "F",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "Brushless",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "PWM",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Selenoide": {
          newNode = {
            id: "G",
            type: "imageNode",
            data: {
              image: {
                url: G_Selenoide,
                alt: "Selenoide",
              },
              size: {
                x: "100px",
                y: "90px",
              },
              handles: [
                {
                  type: "target",
                  id: "INPUT",
                  position: Position.Bottom,
                  style: { left: "4%",bottom: "55%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        //Luces
        case "RGB": {
          newNode = {
            id: "H",
            type: "imageNode",
            data: {
              image: {
                url: H_RGB,
                alt: "ForRGB",
              },
              size: {
                x: "60px",
                y: "60px"
              },
              handles: [
                {
                  type: "target",
                  id: "B",
                  position: Position.Left,
                  style: { left: "3.5%",top: "30%", background: "red" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "G",
                  position: Position.Left,
                  style: { left: "3.5%",top: "41%", background: "green" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "R",
                  position: Position.Left,
                  style: { left: "3.5%",top: "55%", background: "blue" },
                  isConnectable: true,
                },
              ]
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "CuboLed3x3": {
          newNode = {
            id: "I",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "CuboLed3x3",
              },
              size: {
                x: "250px",
                y: "250px"
              },
              handles: [
                {
                  type: "target",
                  id: "A",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "B",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "C",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "D",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "E",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "F",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "G",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "H",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "I",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "LV1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "LV2",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "LV3",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                }
              ]
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "7 Seg. Disp.": {
          newNode = {
            id: "J",
            type: "imageNode",
            data: {
              image: {
                url: J_7Segmentos,
                alt: "7 Segmentos",
              },
              size: {
                x: "120px",
                y: "60px"
              },
              handles: [
                {
                  type: "target",
                  id: "A",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "B",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "C",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "D",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "E",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "F",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "G",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "DP",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp2",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp3",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp4",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp5",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "Disp6",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                }
              ]
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Display IC2": {
          newNode = {
            id: "K",
            type: "imageNode",
            data: {
              image: {
                url: K_DisplayI2C,
                alt: "PantallaGraficadora",
              },
              size: {
                x: "100px",
                y: "100px"
              },
              handles: [
                {
                  type: "target",
                  id: "SCL",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "source",
                  id: "SDA",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "RESET",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "PIN 3",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "DC",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "BLK",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                }
              ]

            },
            position,
            targetPosition: "right",
          };
          break;
        }
        //SENSORES
        case "LDR": {
          newNode = {
            id: "K",
            type: "imageNode",
            data: {
              image: {
                url: L_LDR,
                alt: "LDR",
              },
              size: {
                x: "60px",
                y: "50px"
              },
              handles: [
                {
                  type: "source",
                  id: "OUT",
                  position: Position.Left,
                  style: { left: "-1%",top: "47%", background: "yellow" },
                  isConnectable: true,
                },
              ]

            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "AHT10": {
          newNode = {
            id: "M",
            type: "imageNode",
            data: {
              image: {
                url: M_AHT10,
                alt: "AHT10",
              },
              size: {
                x: "60px",
                y: "110px"
              },
              handles: [
                {
                  type: "target",
                  id: "SCL",
                  position: Position.Left,
                  style: { left: "15%",top:"44.5%", background: "yellow" },
                  isConnectable: true,
                },
                {
                  type: "source",
                  id: "SDA",
                  position: Position.Left,
                  style: { left: "15%",top:"52%", background: "yellow" },
                  isConnectable: true,
                },
              ]
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Luminisoidad": {
          newNode = {
            id: "L",
            type: "imageNode",
            data: {
              url: ImageArduino,
              alt: "Luminosidad",
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "INPUT",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Temperatura/Humedad": {
          newNode = {
            id: "M",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "Temperatura/Humedad",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "PIN 1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Temperatura/Humedad": {
          newNode = {
            id: "M",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "Temperatura/Humedad",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "PIN 1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Hall": {
          newNode = {
            id: "N",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "Hall",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "PIN 1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Proximidad": {
          newNode = {
            id: "O",
            type: "imageNode",
            data: {
              image: {
                url: ImageActuador,
                alt: "Proximidad",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "target",
                  id: "PIN 1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "yellow" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        //Programables
        case "Arduino": {
          newNode = {
            id: "P",
            type: "imageNode",
            data: {
              image: {
                url: Arduino,
                alt: "Arduino",
              },
              size: {
                x: "162.5px",
                y: "87.5px",
              },
              
              handles: [
                {
                  type: "source",
                  id: "pin1",
                  position: Position.Bottom,
                  style: { left: "15%", background: "red" },
                  isConnectable: true,
                },
                {
                  type: "source",
                  id: "pin2",
                  position: Position.Bottom,
                  style: { left: "50%", background: "blue" },
                  isConnectable: true,
                },
                {
                  type: "source",
                  id: "pin3",
                  position: Position.Bottom,
                  style: { left: "85%", background: "orange" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Esp32": {
          newNode = {
            id: "Q",
            type: "imageNode",
            data: {
              image: {
                url: ESP32,
                alt: "Esp32",
              },
              handles: [
                {
                  type: "source",
                  id: "pin1",
                  position: Position.Bottom,
                  style: { left: "70%", background: "red" },
                  isConnectable: true,
                },
                {
                  type: "target",
                  id: "pin2",
                  position: Position.Bottom,
                  style: { left: "85%", background: "blue" },
                  isConnectable: true,
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
        case "Zedboard": {
          newNode = {
            id: "R",
            type: "imageNode",
            data: {
              image: {
                url: ZedBoard,
                alt: "zybo",
              },
              size: {
                x: "250px",
                y: "250px",
              },
              handles: [
                {
                  type: "source",
                  id: "JE4",
                  position: Position.Left,
                  style: { left: "10.5%", top:"45%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE3",
                  position: Position.Left,
                  style: { left: "10.5%", top:"47.2%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE2",
                  position: Position.Left,
                  style: { left: "10.5%", top:"49.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE1",
                  position: Position.Left,
                  style: { left: "10.5%", top:"51.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE4_1",
                  position: Position.Right,
                  style: { left: "13%", top:"45%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE3_1",
                  position: Position.Right,
                  style: { left: "13%", top:"47.2%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE2_1",
                  position: Position.Right,
                  style: { left: "13%", top:"49.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JE1_1",
                  position: Position.Right,
                  style: { left: "13%", top:"51.5%",background: "#ff0000" },
                },


                {
                  type: "source",
                  id: "JD4",
                  position: Position.Left,
                  style: { left: "10.5%", top:"57%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD3",
                  position: Position.Left,
                  style: { left: "10.5%", top:"59.3%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD2",
                  position: Position.Left,
                  style: { left: "10.5%", top:"61.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD1",
                  position: Position.Left,
                  style: { left: "10.5%", top:"63.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD4_1",
                  position: Position.Right,
                  style: { left: "13%", top:"57%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD3_1",
                  position: Position.Right,
                  style: { left: "13%", top:"59.3%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD2_1",
                  position: Position.Right,
                  style: { left: "13%", top:"61.5%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JD1_1",
                  position: Position.Right,
                  style: { left: "13%", top:"63.5%",background: "#ff0000" },
                },


                {
                  type: "source",
                  id: "JC4",
                  position: Position.Left,
                  style: { left: "10.5%", top:"70%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC3",
                  position: Position.Left,
                  style: { left: "10.5%", top:"72%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC2",
                  position: Position.Left,
                  style: { left: "10.5%", top:"74%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC1",
                  position: Position.Left,
                  style: { left: "10.5%", top:"76%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC4_1",
                  position: Position.Right,
                  style: { left: "13%", top:"70%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC3_1",
                  position: Position.Right,
                  style: { left: "13%", top:"72%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC2_1",
                  position: Position.Right,
                  style: { left: "13%", top:"74%",background: "#ff0000" },
                },
                {
                  type: "source",
                  id: "JC1_1",
                  position: Position.Right,
                  style: { left: "13%", top:"76%",background: "#ff0000" },
                },
              ],
            },
            position,
            targetPosition: "right",
          };
          break;
        }
      }
      console.log(newNode);
      setNodes((nds) => nds.concat(newNode));
    },
    [reactFlowInstance]
  );
  return (
    <div style={reactflow} onDragOver={handleDragOver} ref={reactFlowWrapper}>
      {" "}
      <ReactFlow
        nodes={nodes}
        edges={edges}
        onNodesChange={onNodesChange}
        onEdgesChange={onEdgesChange}
        onConnect={onConnect}
        onDrop={onDrop}
        nodeTypes={nodeTypes}
        connectionLineStyle={connectionLineStyle}
        snapToGrid={true}
        snapGrid={snapGrid}
        defaultViewport={defaultViewport}
        onInit={setReactFlowInstance}
        fitView
        attributionPosition="bottom-left"
      >
        <Controls />
      </ReactFlow>
    </div>
  );
};

export default CustomNodeFlow;
