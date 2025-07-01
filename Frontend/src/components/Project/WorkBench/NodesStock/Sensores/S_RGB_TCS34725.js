import S_RGB_TCS34725 from "@/assets/media/Nodes/Sensores (L-O)/S_RGB_TCS34725.png";
const trueDimensions = { tamX: 387 , tamY: 337   }; 
const defaultHandleStyle = (left) => ({
  left,
  bottom: "0.45em",
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
  name: "RGB_TCS34725",
  url: S_RGB_TCS34725,
  type: "sensor",
 size: { x: `${Math.ceil(trueDimensions.tamX*.20)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.20)}px` },
  handles: [
    createHandle("LED", "12%"),
    createHandle("INT", "24%"),
    createHandle("SDA", "36%"),
    createHandle("SCL", "48%"),
    createHandle("3V3", "60%"),
    createHandle("GND", "72%"),
    createHandle("VIN", "84%"),

  ],
};
