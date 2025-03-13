import J_7Segmentos from "@/assets/media/Nodes/Luces (H-K)/J_7segmentos.svg";

export default {
  name: "Contador",
  url: J_7Segmentos,
  type: "luminoso",
  size: { x: "120px", y: "60px" },
  handles: [
    {
      id: "A",
      type: "target",
      position: "bottom",
      style: { left: 0, background: "orange" },
      isConnectable: true,
    },
  ],
};
