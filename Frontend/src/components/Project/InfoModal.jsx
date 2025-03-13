import styles from "./CSS/sidebar.module.css";

export default function Info({ label }) {
  return (
    <div className={styles.overlay}>
      <div className={styles.info_card}>
        <div className={styles.info_title}>{label}</div>
        <div className={styles.info_text}>
          Lorem Ipsum is simply dummy text of the printing and typesetting
          industry. Lorem Ipsum has been the industry&apos;s standard dummy text
          ever since the 1500s
        </div>
      </div>
    </div>
  );
}
