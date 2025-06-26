import S_DC_INA219 from "@/assets/media/Nodes/Sensores (L-O)/S_DC_INA219.png";

export default {
  name: "DC_INA219",
  url: S_DC_INA219,
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
