import H_RGB from "@/assets/media/Nodes/Luces (H-K)/H_RGB.svg";

const left = ".2em";

export default {
  name: "RGB",
  url: H_RGB,
  type: "luminoso",
  size: { x: "60px", y: "60px" },
  handles: [
    {
      id: "R",
      type: "target",
      position: "left",
      style: { left: left, top: "2.15em", background: "red" },
      isConnectable: true,
    },
    {
      id: "G",
      type: "target",
      position: "left",
      style: { left: left, top: "1.7em", background: "green" },
      isConnectable: true,
    },
    {
      id: "blue",
      type: "target",
      position: "left",
      style: { left: left, top: "1.25em", background: "blue" },
      isConnectable: true,
    },
  ],
};
