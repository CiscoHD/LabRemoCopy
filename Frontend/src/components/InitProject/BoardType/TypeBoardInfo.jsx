import styles from "./index.module.css";

import CardBoard from "./CardBoard";

import ArduinoMega from "@/assets/media/Nodes/Programables/ARDUINO_NANO33.png";
import ESP32 from "@/assets/media/Nodes/Programables/ESP32.png";
import ZYBO from "@/assets/media/Nodes/Programables/ZEDBOARD2.png";
import RaspberryPi5 from "@/assets/media/Nodes/Programables/RASPBERRYPI5_2.png";

export default function TypeBoard() {
  //Opciones de incio
  const boards = [
    { board: "Arduino", title: "Arduino Nano 33", url: ArduinoMega },
    { board: "Esp32", title: "ESP32", url: ESP32 },
    { board: "ZedBoard", title: "ZedBoard", url: ZYBO },
    { board: "RaspberryPi5", title: "RaspberryPi5", url: RaspberryPi5 },
  ];

  /*Mostrar tarjetas */
  return (
    <div className={styles.container}>
      {boards.map((board) => {
        return <CardBoard key={board.board} board={board} />;
      })}
    </div>
  );
}

