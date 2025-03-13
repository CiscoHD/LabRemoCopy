import styles from "./index.module.css";

import CardBoard from "./CardBoard";

import ArduinoMega from "@/assets/media/Nodes/Programables/Arduino.png";
import ESP32 from "@/assets/media/Nodes/Programables/Esp32.png";
import ZYBO from "@/assets/media/Nodes/Programables/ZYBO2.png";

export default function TypeBoard() {
  //Opciones de incio
  const boards = [
    { board: "Arduino", title: "Arduino MEGA", url: ArduinoMega },
    { board: "Esp32", title: "ESP32", url: ESP32 },
    { board: "ZedBoard", title: "ZedBoard", url: ZYBO },
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
