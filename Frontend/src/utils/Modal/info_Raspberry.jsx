import styles from "@/components/InitProject/BoardType/index.module.css";

export default function BoardInfo({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
      Es una excelente opción para crear un sistema de seguridad doméstico. 
      Puedes usarla para detectar movimiento, controlar puertas y ventanas
       o incluso grabar el video de las cámaras de vigilancia.
        </div>
      </div>
    </div>
  );
}