import sensorImg from "@/assets/media/Nodes/Sensores (L-O)/S_AHT20_BMP280.png";
const trueDimensions = { tamX: 315 , tamY: 331  }; 

const defaultHandleStyle = (left) => ({
  left,
  top: "0.7em",
  background: "orange",
});

const createHandle = (id, left) => ({
  id,
  type: "target",
  position: "top",
  style: defaultHandleStyle(left),
  isConnectable: true,
});

export default {
  name: "AHT20",
  url: sensorImg,
  type: "sensor",
   size: { x: `${Math.ceil(trueDimensions.tamX*.20)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.20)}px` },
  handles: [
    createHandle("SCL", "25%"),
    createHandle("GND", "43%"),
    createHandle("SDA", "59.5%"),
  ],
};

