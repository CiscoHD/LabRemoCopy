import M_AHT10 from "@/assets/media/Nodes/Sensores (L-O)/M_aht10.svg";

export default {
  name: "AHT10",
  url: M_AHT10,
  type: "sensor",
  size: { x: "60px", y: "110px" },
  handles: [
    {
      id: "SCL",
      type: "target",
      position: "left",
      style: { left: "15%", top: "44.5%", background: "orange" },
      isConnectable: true,
    },
    {
      id: "OUT",
      type: "source",
      position: "left",
      style: { left: "15%", top: "52%", background: "orange" },
      isConnectable: true,
    },
  ],
};
