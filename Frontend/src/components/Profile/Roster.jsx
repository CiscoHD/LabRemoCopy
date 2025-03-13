import styles from "./CSS/profile.module.css";

export default function Roster() {
  const students = [
    "Alumno 1",
    "Alumno 2",
    "Alumno 3",
    "Alumno 4",
    "Alumno 5",
    "Alumno 6",
    "Alumno 7",
  ];
  return (
    <div>
      <div className={styles.title}>Lista de estudiantes</div>
      {students.map((student) => {
        return (
          <div key={student} className={styles.practice}>
            <div className={styles.name}>{student}</div>
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
