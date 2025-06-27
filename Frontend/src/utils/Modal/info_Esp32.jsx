import styles from "@/components/InitProject/BoardType/index.module.css";

export default function BoardInfo({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
      Es una plataforma versátil que permite la creación de proyectos innovadores
       en el campo del Internet de las Cosas (IoT), ofreciendo capacidades 
       de comunicación inalámbrica y procesamiento eficiente en un solo dispositivo
        </div>
      </div>
    </div>
  );
}