import ESP32 from "@/assets/media/Nodes/Programables/ESP32.png";

const defaultHandleSize = { width: 20, height: 20 };
export default {
  name: "Esp32",
  url: ESP32,
  type: "programable",
  size: { x: "162.5px", y: "87.5px" },
  handles: [
    {
      id: "pin1_s",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: "90%" },
      isConnectable: true,
    },
    {
      id: "pin2_s",
      type: "source",
      position: "bottom",
      style: { bottom: 0, left: "80%" },
      isConnectable: true,
    },
  ].map(handle => ( {...handle, style: {...defaultHandleSize, ...handle.style},} )),
};
