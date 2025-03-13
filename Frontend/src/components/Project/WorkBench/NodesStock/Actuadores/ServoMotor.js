import E_Servomotor from "@/assets/media/Nodes/Actuadores (A-G)/E_Servomotor.svg";
export default {
  name: "ServoMotor",
  url: E_Servomotor,
  type: "actuador",
  size: { x: "135px", y: "117px" },
  handles: [
    {
      id: "PWM",
      type: "target",
      position: "left",
      style: { left: ".8em", top: "3.35em" },
      isConnectable: true,
    },
  ],
};
