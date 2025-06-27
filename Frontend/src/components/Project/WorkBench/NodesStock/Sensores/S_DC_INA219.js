import S_DC_INA219 from "@/assets/media/Nodes/Sensores (L-O)/S_DC_INA219.png";

const defaultHandleSize = { width: 1, height: 1 };

export default {
  name: "s_DC_INA219",
  url: S_DC_INA219,
  type: "sensor",
  size: { x: "20%", y: "20%" },
  handles: [
    {
      id: "vcc",
      type: "target",
      position: "bottom",
      style: { left: "27%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "GND",
      type: "target",
      position: "bottom",
      style: { left: "37%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SCL",
      type: "target",
      position: "bottom",
      style: { left: "47%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SDA",
      type: "target",
      position: "bottom",
      style: { left: "57%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "vin-",
      type: "target",
      position: "bottom",
      style: { left: "67%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "vin+",
      type: "target",
      position: "bottom",
      style: { left: "77%", bottom: "1em", background: "orange" },
      isConnectable: true,
    },
  ],
};

