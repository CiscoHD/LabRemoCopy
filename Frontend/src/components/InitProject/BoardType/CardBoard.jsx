import  { useContext } from "react";
import styles from "./index.module.css";
import "bootstrap-icons/font/bootstrap-icons.css";

import { MenuContext } from "@/context/MenuContext";

import { ShowBoardInfo } from "./main";

export default function CardBoard({ board }) {
  const Content = () => {
    return <img className={styles.image} src={board.url} />;
  };

  const { setBoardChoosen, boardChoosen } = useContext(MenuContext);

  return (
    //Reaccionar conforme la tarjeta seleccionada
    <div
      className={`${styles.card} ${
        board.board === boardChoosen && styles.active
      }`}
      onClick={() => {
        setBoardChoosen(board.board);
      }}
    >
      <div className={styles.title}> {board ? board.title : "Card Title"} </div>
      {board ? <Content /> : "Imagen no disponible"}
      <div className={`bi bi-info-circle ${styles.info}`}>
        <ShowBoardInfo board={board.board} />
      </div>
    </div>
  );
}
