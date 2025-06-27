import L_LDR from "@/assets/media/Nodes/Sensores (L-O)/L_LDR.svg";

export default {
  name: "LDR",
  url: L_LDR,
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
