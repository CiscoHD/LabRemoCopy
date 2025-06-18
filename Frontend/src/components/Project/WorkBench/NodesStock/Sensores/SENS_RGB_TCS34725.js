import SENS_RGB_TCS34725 from "@/assets/media/Nodes/Sensores (L-O)/SENS_RGB_TCS34725.png";

export default {
  name: "RGB_TCS34725",
  url: SENS_RGB_TCS34725,
  type: "sensor",
  size: { x: "80px", y: "50px" },
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
