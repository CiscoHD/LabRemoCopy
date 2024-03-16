import React, { useState,useEffect } from 'react';


// import A_MotorDC from '../../../media/Dispositivos/A_MotorDC.png';
// import B_MotorDCx2 from '../../../media/Dispositivos/B_MotorDCx2.png';
// import E_Servomotor from '../../../media/Dispositivos/E - Servomotor.png';
// import G_Selenoide from '../../../media/Dispositivos/G-Selenoide.png';
// import H_RGB from '../../../media/Dispositivos/H_RGB.png';
// import J_7Segmentos from '../../../media/Dispositivos/J - 7segmentos.png';
// import K_DisplayI2C from '../../../media/Dispositivos/K - Display I2C.png';
// import L_LDR from '../../../media/Dispositivos/L-LDR.png';
// import M_AHT10 from '../../../media/Dispositivos/M-aht10.png';

import A_MotorDC from '../../../media/Dispositivos/Actuadores (A-G)/A_MotorDC.png';
import B_MotorDCx2 from '../../../media/Dispositivos/Actuadores (A-G)/B_MotorDCx2.png';
import E_Servomotor from '../../../media/Dispositivos/Actuadores (A-G)/E - Servomotor.png';
import G_Selenoide from '../../../media/Dispositivos/Actuadores (A-G)/G-Selenoide.png';
import H_RGB from '../../../media/Dispositivos/Luces (H-K)/H - RGB.png';
import J_7Segmentos from '../../../media/Dispositivos/Luces (H-K)/J - 7segmentos.png';
import K_DisplayI2C from '../../../media/Dispositivos/Luces (H-K)/K - Display I2C.png';
import L_LDR from '../../../media/Dispositivos/Sensores (L-O)/L-LDR.png';
import M_AHT10 from '../../../media/Dispositivos/Sensores (L-O)/M-aht10.png';

import Arduino from '../../../media/Boards/ArduinoMEGA.png';
import ZedBoard from '../../../media/Dispositivos/Programables (P-R)/Zedboard.png';
import ESP32 from '../../../media/Boards/Esp32nodemcubis_2.png';

import ImageArduino from "../Pictures/Arduino.png"
import ImageMotorY from "../Pictures/Actuador.png"
import ImageServoMotor from "../Pictures/servomotorSF.png"
import HideButtonIcon from "../Pictures/mover.png"

import './sidebar.css'

const imageStyle = {
  width: '50px', // Define el ancho de las imágenes
  height: '50px', // Define la altura de las imágenes
  transition: 'transform 0.3s ease', // Agrega transición para el efecto de selección
  borderRadius: '50%', // Hace las esquinas redondeadas para las imágenes
};

const labelStyle = {
  fontSize: '14px', // Define el tamaño de fuente de las etiquetas
  textAlign: 'center', // Centra el texto
  marginTop: '5px', // Espacio entre la imagen y la etiqueta
};

const NavbarStyle = {
  overflow: 'scroll',
  overflowX: 'hidden',
  backgroundColor: '#EB984ECC', // Color del fondo
  color: "white",
  height: "60%",
  width: "12%",
  borderStyle: "solid",
  borderColor: "#EB984E",
  position: "absolute",
  top: "12rem",
  right:"1em",
  borderRadius: "20px", // Añade bordes redondeados a la barra lateral

};

const HideButtonStyle = {
  position: 'absolute',
  top: 0,
  left: 0,
  transform: 'translate(-50%, -50%)',
  cursor: 'pointer',
};

const Sidebar = () => {
  const [isHidden, setIsHidden] = useState(false);

  const onDragStart = (event, nodeType) => {
    event.dataTransfer.setData('application/reactflow', nodeType);
    event.dataTransfer.effectAllowed = 'move';
  };
//Cambiar por la imagen correcta
  const inventory = [
    //PROGRAMABLES
    { name: 'Arduino', src: Arduino, type: 'programable' },
    { name: 'Esp32', src: ESP32, type: 'programable' },
    { name: 'Zedboard', src: ZedBoard, type: 'programable' },

    //ACTUADORES
    { name: 'DcMotor', src: A_MotorDC, type: 'actuador' },
    { name: 'DcMotorx2', src: B_MotorDCx2, type: 'actuador'  },
    { name: 'Servomotor', src: E_Servomotor, type: 'actuador'  },
    { name: 'Selenoide', src: G_Selenoide, type: 'actuador'  },
    // { name: 'Servomotor', src: ImageServoMotor, type: 'actuador'},
    // { name: 'Brushless', src: ImageArduino, type: 'actuador'  },
    // { name: 'Solenoide', src: ImageArduino, type: 'actuador'  },

    //LUCES
    { name: 'RGB', src: H_RGB, type: 'Luminoso'},
    { name: '7 Seg. Disp.', src: J_7Segmentos, type: 'Luminoso'},
    { name: 'Display IC2', src: K_DisplayI2C, type: 'Luminoso'},

    //SENSORES
    { name: 'LDR', src: L_LDR, type: 'Sensor'},
    { name: 'AHT10', src: M_AHT10, type: 'Sensor'}
  ];

  const handleMouseEnter = (event) => {
    event.target.style.transform = 'scale(1.2)'; // Aumenta ligeramente la imagen
    event.target.style.cursor = 'pointer'; // Cambia el cursor al pasar sobre la imagen
  };

  const handleMouseLeave = (event) => {
    event.target.style.transform = 'scale(1)'; // Restaura el tamaño original de la imagen
    event.target.style.cursor = 'default'; // Restaura el cursor predeterminado
  };

  const toggleSidebar = () => {
    setIsHidden(!isHidden);
  };

  return (
    <div className={'sidebar'} style={{ /*...NavbarStyle,*/ display: isHidden ? 'none' : 'block' }}>
      {/* <div style={HideButtonStyle} onClick={toggleSidebar}>
        <img src={HideButtonIcon} alt="Hide" width="35" height="35" />
      </div> */}
      <p className='sidebar-title'>Lista de Componentes</p>
      <span className='sidebar-type-separator'>
            <span></span>
      </span>
      <Catalog
        onDragStart={onDragStart}
        inventory={inventory}
        imageStyle={imageStyle}
        labelStyle={labelStyle}
        onMouseEnter={handleMouseEnter}
        onMouseLeave={handleMouseLeave}
      />
    </div>
  );
};

const Catalog = ({ onDragStart, inventory, imageStyle, labelStyle, onMouseEnter, onMouseLeave }) => {
  const [types,setTypes]=useState([]);


  useEffect(() => {
    inventory.map((itm) =>{
      if(!types.includes(itm.type)){
        setTypes([...types,itm.type]);
      }
    })
  }, [types]);

  return (
    <div>

      { types.map((type) => {
        return(
          <div className='sidebar-title'>{type.toUpperCase()}
            {inventory.map((item, index) => {       
            return(
            (item.type==type)&&<div key={index}>
              <img
                src={item.src}
                alt={item.name}
                onDragStart={(event) => onDragStart(event, item.name)}
                draggable
                style={imageStyle}
                onMouseEnter={onMouseEnter}
                onMouseLeave={onMouseLeave}
              />
              <div style={labelStyle}>{item.name}</div>
            </div>
          )})}
          <span className='sidebar-type-separator'>
            <span></span>
          </span>
          </div>
        )
      })
      }
    </div>
  );
};
function DeleteFromInventory(item, Inventory){
  
  for(let i in Inventory){
    if(item == Inventory[i].name){
      Inventory.splice(i, 1)
    }
  }
}

export default Sidebar;
