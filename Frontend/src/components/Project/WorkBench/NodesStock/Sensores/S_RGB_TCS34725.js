import S_RGB_TCS34725 from "@/assets/media/Nodes/Sensores (L-O)/S_RGB_TCS34725.png";

export default {
  name: "RGB_TCS34725",
  url: S_RGB_TCS34725,
  type: "sensor",
  size: { x: "20%", y: "20%" },
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
