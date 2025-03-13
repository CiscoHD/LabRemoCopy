import styles from "./CSS/profile.module.css";

export default function ActivityList() {
  const practices = [
    "Práctica 1",
    "Práctica 2",
    "Práctica 3",
    "Práctica 4",
    "Práctica 5",
    "Práctica 6",
    "Práctica 7",
  ];

  return (
    <div>
      <div className={styles.title}>Lista de Prácticas</div>
      {practices.map((element) => {
        return (
          <div key={element} className={styles.practice}>
            <div className={styles.name}>{element}</div>
            <div className={styles.actions}>
              <i className={`bi bi-eye-fill ${styles.view}`} />
              <i className={`bi bi-trash2 ${styles.trash}`} />
            </div>
          </div>
        );
      })}
    </div>
  );
}
