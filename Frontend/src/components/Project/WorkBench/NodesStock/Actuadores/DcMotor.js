import A_MotorDC from "@/assets/media/Nodes/Actuadores (A-G)/A_MotorDC.svg";

const defaultHandleSize = {width: 12, height: 12};

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
  ].map((handle) => ({
    ...handle,
    style: {
      ...defaultHandleSize,
      ...handle.style,
    },
  })),
};