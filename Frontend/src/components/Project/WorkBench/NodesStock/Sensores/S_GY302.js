import sensorImg from "@/assets/media/Nodes/Sensores (L-O)/S_GY302.png";
const trueDimensions = { tamX: 315 , tamY: 413   }; 

const defaultHandleStyle = (left) => ({
  left,
  bottom: "0.5em",
  background: "orange",
});

const createHandle = (id, left) => ({
  id,
  type: "target",
  position: "bottom",
  style: defaultHandleStyle(left),
  isConnectable: true,
});

export default {
  name: "s_GY302",
  url: sensorImg,
  type: "sensor",
 size: { x: `${Math.ceil(trueDimensions.tamX*.20)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.20)}px` },
  handles: [
    createHandle("vcc", "20.5%"),
    createHandle("GND", "37%"),
    createHandle("SCL", "52.5%"),
    createHandle("SDA", "70.5%"),
    createHandle("ADDR", "87%"),
  ],
};

