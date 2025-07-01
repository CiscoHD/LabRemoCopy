import sensorImg from "@/assets/media/Nodes/Sensores (L-O)/S_DC_INA219.png";
const trueDimensions = { tamX: 375, tamY: 321  }; 
const defaultHandleStyle = (left) => ({
  left,
  bottom: "0.7em",
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
  name: "s_DC_INA219",
  url: sensorImg,
  type: "sensor",
   size: { x: `${Math.ceil(trueDimensions.tamX*.20)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.20)}px` },
  handles: [
    createHandle("vcc", "27%"),
    createHandle("GND", "37%"),
    createHandle("SCL", "47%"),
    createHandle("SDA", "57%"),
    createHandle("vin-", "67%"),
    createHandle("vin+", "77%"),
  ],
};

