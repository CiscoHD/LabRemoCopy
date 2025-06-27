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
      style: { left: "10%", bottom: "-0.5em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "GND",
      type: "target",
      position: "bottom",
      style: { left: "28%", bottom: "-0.5em", background: "orange" },
      isConnectable: true,
    },
    {
      id: "SCL",
      type: "target",
      position: "bottom",
      style: { left: "46%", bottom: "-0.5em", background: "blue" },
      isConnectable: true,
    },
    {
      id: "SDA",
      type: "target",
      position: "bottom",
      style: { left: "64%", bottom: "-0.5em", background: "blue" },
      isConnectable: true,
    },
    {
      id: "vin-",
      type: "target",
      position: "bottom",
      style: { left: "82%", bottom: "-0.5em", background: "gray" },
      isConnectable: true,
    },
    {
      id: "vin+",
      type: "target",
      position: "bottom",
      style: { left: "95%", bottom: "-1em", background: "red" },
      isConnectable: true,
    },
  ],
};

