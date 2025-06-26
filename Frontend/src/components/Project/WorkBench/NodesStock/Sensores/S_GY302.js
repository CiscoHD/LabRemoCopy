import S_GY302 from "@/assets/media/Nodes/Sensores (L-O)/S_GY302.png";

export default {
  name: "GY302",
  url: S_GY302,
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
