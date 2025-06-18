import SENS_AHT20_BMP280 from "@/assets/media/Nodes/Sensores (L-O)/SENS_AHT20_BMP280.png";

export default {
  name: "AHT20",
  url: SENS_AHT20_BMP280,
  type: "sensor",
  size: { x: "80px", y: "20%" },
  handles: [
    {
      id: "OUT",
      type: "source",
      position: "left",
      style: { left: "0em", top: "1.5em", background: "orange" },
      isConnectable: true,
    },
  ],
};
