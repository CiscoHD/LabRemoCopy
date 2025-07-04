import { useCallback, useState } from "react";
import { useReactFlow } from "@xyflow/react";

import styles from "./styles.module.css";

export default function NodeContextMenu({
  id,
  top,
  left,
  right,
  bottom,
  type,
  onClick,
  onDelete,
}) {
  const { getNode, setNodes, addNodes, setEdges } = useReactFlow();

  const [distances, setDistance] = useState(50);
  const [show, setShow] = useState();

  const notShowMenu = () => {
    onClick(null);
  };
  // Función para duplicar nodos
  const duplicateNode = useCallback(() => {
    const node = getNode(id);
    const newDistances = distances + 10;
    const position = {
      x: node.position.x + distances,
      y: node.position.y + distances,
    };

    addNodes({
      ...node,
      selected: false,
      dragging: false,
      id: `${node.id}_${+new Date()}`,
      position,
    });
    setDistance(newDistances);
    notShowMenu();
  }, [id, distances]);

  // Función para borrar un nodo
  const deleteNode = useCallback(() => {
    setNodes((nodes) => nodes.filter((node) => node.id !== id));
    setEdges((edges) => edges.filter((edge) => edge.source !== id));

    // Usamos onDelete para eliminar todas las conexiones que contengan el sourceHandle
    onDelete((connections) =>
      connections.filter((connection) => !connection.endsWith(`-${id}`))
    );
    notShowMenu();
  }, [id]);

  //Función para rotar un nodo
  const rotateNode = useCallback(() => {
    setNodes((nodes) =>
    nodes.map((node) =>{
      if (node.id == id){
        const currentRotation = node.data?.rotation ||0;
        const newRotation = (currentRotation + 90) % 360;
        
        return {
          ...node,
          data: {
            ...node.data,
            rotation: newRotation,
          },
        };
      }
      return node;

    })
    );
    
    notShowMenu();
  }, [id]);

  const showInfo = useCallback(() => {
    setShow(!show);
  });
  return (
    <div style={{ top, left, right, bottom }} className={styles.contextMenu}>
      <p className={styles.name} onClick={notShowMenu}>
        {id.toUpperCase().split("_")[0]}
      </p>
      {type != "programable" && (
        <>
          <button className={styles.button} onClick={duplicateNode}>
            Duplicate
          </button>
          <button className={styles.button} onClick={deleteNode}>
            Delete
            <div className={styles.key}>Del</div>
          </button>
          <button className={styles.button} onClick={rotateNode}>
            Rotate
            <div className={styles.key}>R</div>
          </button>
        </>
      )}
      <button className={styles.button} onClick={showInfo}>
        Información
      </button>
      {show &&
        "Lorem ipsum dolor sit, amet consectetur adipisicing elit. Ullam nisi fugit explicabo quibusdam commodi consectetur rem id culpa eum deserunt? Aut dolore numquam fugiat esse minus tempora modi dolor odio."}
    </div>
  );
}
