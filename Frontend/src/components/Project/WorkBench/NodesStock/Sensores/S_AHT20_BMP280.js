import S_AHT20_BMP280 from "@/assets/media/Nodes/Sensores (L-O)/S_AHT20_BMP280.png";

export default {
  name: "AHT20",
  url: S_AHT20_BMP280,
  type: "sensor",
  size: { x: "70px", y: "50%" },
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
