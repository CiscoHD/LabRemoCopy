import sensorImg from "@/assets/media/Nodes/Sensores (L-O)/S_AHT20_BMP280.png";

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
  size: { x: "20%", y: "20%" },
  handles: [
    createHandle("SCL", "25%"),
    createHandle("GND", "43%"),
    createHandle("SDA", "59.5%"),
  ],
};

