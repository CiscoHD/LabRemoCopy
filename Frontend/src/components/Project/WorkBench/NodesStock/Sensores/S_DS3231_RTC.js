import S_DS3231_RTC from "@/assets/media/Nodes/Sensores (L-O)/S_DS3231_RTC.png";
const defaultHandleStyle = (left) => ({
  left,
  bottom: "1em",
  background: "orange",
});
const createHandle = (id, left) => ({
  id,
  type: "target",
  position: "bottom",
  style: defaultHandleStyle(left),
  isConnectable: true,
});
export default {
  name: "S_DS3231_RTC",
  url: S_DS3231_RTC,
  type: "sensor",
  size: { x: "20%", y: "20%" },
  handles: [
    createHandle("32K", "22%"),
    createHandle("SQW", "34%"),
    createHandle("SCL", "46%"),
    createHandle("SDA", "58%"),
    createHandle("VCC", "70%"),
    createHandle("GND", "82%"),

  ],
};