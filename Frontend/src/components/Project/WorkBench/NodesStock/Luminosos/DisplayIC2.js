import K_DisplayI2C from "@/assets/media/Nodes/Luces (H-K)/K_Display I2C.svg";
export default {
  name: "Display IC2",
  url: K_DisplayI2C,
  type: "luminoso",
  size: { x: "100px", y: "100px" },
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
