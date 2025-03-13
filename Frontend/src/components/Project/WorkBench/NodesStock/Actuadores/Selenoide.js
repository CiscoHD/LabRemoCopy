import G_Selenoide from "@/assets/media/Nodes/Actuadores (A-G)/G_Selenoide.svg";

export default {
  name: "Selenoide",
  url: G_Selenoide,
  type: "actuador",
  size: { x: "100px", y: "90px" },
  handles: [
    {
      id: "INPUT",
      type: "target",
      position: "bottom",
      style: { left: "4%", top: "55%", background: "orange" },
      isConnectable: true,
    },
  ],
};
