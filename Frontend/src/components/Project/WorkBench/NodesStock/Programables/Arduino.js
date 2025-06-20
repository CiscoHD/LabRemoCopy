import Arduino from "@/assets/media/Nodes/Programables/ARDUINO_NANO33.png";

const defaultHandleSize = { width: 20, height: 20 };

export default {
  name: "Arduino",
  url: Arduino,
  type: "programable",
  size: { x: "50%", y: "50%" },
  handles: [
    {
      id: "pin1",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: 0, },
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
  ].map(handle => ( {...handle, style: {...defaultHandleSize, ...handle.style},} )),
};
