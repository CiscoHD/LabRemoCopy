import { useCallback, useState } from "react";
import { useReactFlow } from "@xyflow/react";

import styles from "./styles.module.css";

export default function EdgeContextMenu({
  id,
  top,
  left,
  right,
  bottom,
  onClick,
  onDelete,
  currentColor,
}) {
  const { setEdges, getEdges } = useReactFlow();

  const [color, setColor] = useState(currentColor);

  const notShowMenu = () => {
    onClick(null);
  };

  // Función para borrar un nodo
  const deleteEdge = useCallback(() => {
    // Encuentra el edge que se va a eliminar
    const edgeToDelete = getEdges().find((edge) => edge.id === id);

    onDelete((connections) =>
      connections.filter(
        (connection) =>
          connection !==
          `${edgeToDelete.source}-${edgeToDelete.sourceHandle}-${edgeToDelete.targetHandle}-${edgeToDelete.target}`
      )
    );

    // Si el edge existe, obtenemos los nodos conectados
    if (edgeToDelete)
      setEdges((edges) => edges.filter((edge) => edge.id !== id));

    notShowMenu();
  }, [id, getEdges, setEdges]);

  const changeColor = useCallback(() => {
    setEdges((edges) =>
      edges.map((edge) =>
        edge.id === id
          ? { ...edge, style: { ...edge.style, stroke: color } } // Cambia el color del edge seleccionado
          : edge
      )
    );
    notShowMenu();
  }, [id, color]);

  return (
    <div style={{ top, left, right, bottom }} className={styles.contextMenu}>
      <p className={styles.name} onClick={notShowMenu}>
        {id.toUpperCase().split("_")[0]}
      </p>
      <div className={styles.row}>
        <button className={styles.button} onClick={changeColor}>
          Cambiar color
        </button>
        <input
          type="color"
          value={color}
          onChange={(e) => setColor(e.target.value)}
        />
      </div>
      <button className={styles.button} onClick={deleteEdge}>
        Delete
      </button>
    </div>
  );
}
