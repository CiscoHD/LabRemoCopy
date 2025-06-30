import sensorImg from "@/assets/media/Nodes/Sensores (L-O)/S_GY302.png";

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
  name: "s_GY302",
  url: sensorImg,
  type: "sensor",
  size: { x: "20%", y: "20%" },
  handles: [
    createHandle("vcc", "20.5%"),
    createHandle("GND", "37%"),
    createHandle("SCL", "52.5%"),
    createHandle("SDA", "70.5%"),
    createHandle("ADDR", "87%"),
  ],
};

