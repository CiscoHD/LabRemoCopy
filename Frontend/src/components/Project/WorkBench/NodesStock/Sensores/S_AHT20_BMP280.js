import S_AHT20_BMP280 from "@/assets/media/Nodes/Sensores (L-O)/S_AHT20_BMP280.png";
const defaultHandleSize = { width: 3, height: 3 };
export default {
  name: "AHT20",
  url: S_AHT20_BMP280,
  type: "sensor",
  size: { x: "20%", y: "20%" },
  handles: [
    {
      id: "SCL",
      type: "target",
      position: "top",
      style: { left: "25%", top: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "GND",
      type: "target",
      position: "top",
      style: { left: "43%", top: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SDA",
      type: "target",
      position: "top",
      style: { left: "59.5%", top: "0.7em", background: "orange" },
      isConnectable: true,
    },
  ],
};

