import B_MotorDCx2 from "@/assets/media/Nodes/Actuadores (A-G)/B_MotorDCx2.svg";

const left = "1.1em";

export default {
  name: "DcMotorx2",
  url: B_MotorDCx2,
  type: "actuador",
  size: { x: "128px", y: "128px" },
  handles: [
    {
      id: "ENB",
      type: "target",
      position: "left",
      style: { left: left, top: "3.05em" },
      isConnectable: true,
    },
    {
      id: "IN 4",
      type: "target",
      position: "left",
      style: { left: left, top: "3.5em" },
      isConnectable: true,
    },
    {
      id: "IN 3",
      type: "target",
      position: "left",
      style: { left: left, top: "3.95em" },
      isConnectable: true,
    },
    {
      id: "IN 2",
      type: "target",
      position: "left",
      style: { left: left, top: "4.4em" },
      isConnectable: true,
    },
    {
      id: "IN 1",
      type: "target",
      position: "left",
      style: { left: left, top: "4.8em" },
      isConnectable: true,
    },
    {
      id: "ENA",
      type: "target",
      position: "left",
      style: { left: left, top: "5.25em" },
      isConnectable: true,
    },
  ],
};
