import styles from "@/components/InitProject/BoardType/index.module.css";

export default function BoardInfo({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
       Es un kit de desarrollo completo para diseñadores interesados 
       ​en explorar diseños con el SoC totalmente programable AMD 
       Xilinx Zynq®-7000 . La placa contiene todas las interfaces y 
       funciones de soporte necesarias para una amplia gama de aplicaciones.
        </div>
      </div>
    </div>
  );
}