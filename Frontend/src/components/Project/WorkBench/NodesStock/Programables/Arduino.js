import Arduino from "@/assets/media/Nodes/Programables/ARDUINO_NANO33.png";

export default {
  name: "Arduino",
  url: Arduino,
  type: "programable",
  size: { x: "162.5px", y: "87.5px" },
  handles: [
    {
      id: "pin1",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: 0 },
      isConnectable: true,
    },
    {
      id: "pin2",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: "46.5%" },
      isConnectable: true,
    },
    {
      id: "pin3",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: "95%" },
      isConnectable: true,
    },
  ],
};
