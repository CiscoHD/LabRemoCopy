import styles from "@/components/InitProject/BoardType/index.module.css";

export default function BoardInfo({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
          Lorem Ipsum is simply dummy text of the printing and typesetting
          industry. Lorem Ipsum has been the industrys standard dummy text ever
          since the 1500s
        </div>
      </div>
    </div>
  );
}
