import S_GY302 from "@/assets/media/Nodes/Sensores (L-O)/S_GY302.png";

const defaultHandleSize = { width: 1, height: 1 };

export default {
  name: "s_GY302",
  url: S_GY302,
  type: "sensor",
  size: { x: "20%", y: "20%" },
  handles: [
    {
      id: "vcc",
      type: "target",
      position: "bottom",
      style: { left: "20.5%", bottom: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "GND",
      type: "target",
      position: "bottom",
      style: { left: "37%", bottom: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SCL",
      type: "target",
      position: "bottom",
      style: { left: "52.5%", bottom: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SDA",
      type: "target",
      position: "bottom",
      style: { left: "70.5%", bottom: "0.7em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "ADDR",
      type: "target",
      position: "bottom",
      style: { left: "87%", bottom: "0.7em", background: "orange" },
      isConnectable: true,
    },
  ],
};

