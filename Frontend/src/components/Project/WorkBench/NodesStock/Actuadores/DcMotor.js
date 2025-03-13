import A_MotorDC from "@/assets/media/Nodes/Actuadores (A-G)/A_MotorDC.svg";

export default {
  name: "DcMotor",
  url: A_MotorDC,
  type: "actuador",
  size: { x: "135px", y: "117px" },
  handles: [
    {
      id: "PWM",
      type: "target",
      position: "left",
      style: { left: ".25em", top: "3.55em" },
      isConnectable: true,
    },
  ],
};
