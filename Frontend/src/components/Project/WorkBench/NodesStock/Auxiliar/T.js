import T from "@/assets/media/Nodes/Auxiliar/T.svg";

/**
 * La función de este nodo auxiliar es poder conectar un handle source con otro source
 */
export default {
  name: "Aux",
  url: T,
  type: "auxiliar",
  size: { x: "100px", y: "100px" },
  handles: [
    {
      id: "IN_1",
      type: "target",
      position: "left",
      style: { left: "0%", top: "9%" },
      isConnectable: true,
    },
    {
      id: "IN_2",
      type: "target",
      position: "right",
      style: { left: "17%", top: "9%" },
      isConnectable: true,
    },
  ],
};
