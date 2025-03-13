import styles from "./styles.module.css";

export default function SavedSession() {
  //cONTENIDO DE LA TABLA
  const Rows = ({ datarow, number }) => {
    return (
      <tr>
        <td>{datarow ? datarow.name : `Nombre de Practica #${number}`}</td>
        <td>{datarow ? datarow.subject : `Asignatura #${number}`}</td>
        <td>{datarow ? datarow.lastdatemod : `DD/MM/AAAA:HH:MM:SS`}</td>
        <td className={styles.actions}>
          <i
            className={`bi bi-trash2 ${styles.trash}`}
            onClick={() => {
              console.log("trash");
            }}
          />
          <i
            className={`bi bi-share ${styles.share}`}
            onClick={() => {
              console.log("share");
            }}
          />
          <i
            className={`bi bi-pencil-square ${styles.edit}`}
            onClick={() => {
              console.log("edit");
            }}
          />
        </td>
      </tr>
    );
  };

  return (
    <div className={`${styles.container}`}>
      <div className={`${styles.content}`}>
        <table>
          <thead>
            <tr>
              <th>Nombre</th>
              <th>Asignatura</th>
              <th>Última modificacion</th>
              <th>Acciones</th>
            </tr>
          </thead>
          <tbody>
            {[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14].map((i) => {
              return <Rows key={i} number={i} />;
            })}
          </tbody>
        </table>
      </div>
    </div>
  );
}
