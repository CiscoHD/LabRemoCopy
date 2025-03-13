import styles from "./styles.module.css";

export default function ModalWindow({ children }) {
  return (
    <div className={styles.overlay_modal}>
      <div className={styles.info_card}>{children}</div>
    </div>
  );
}
