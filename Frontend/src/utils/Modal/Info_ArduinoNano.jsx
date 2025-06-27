import styles from "@/components/InitProject/BoardType/index.module.css";

export default function BoardInfo({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
         Es una pequeña placa que permite un rápido prototipado sobre una protoboard,
         no solo se conecta mediante Bluetooth® de bajo consumo , sino que también 
         incluye sensores para detectar color, proximidad, movimiento, temperatura,
          humedad, audio y más. 
        </div>
      </div>
    </div>
  );
}
