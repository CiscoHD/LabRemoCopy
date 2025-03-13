import { useState, useEffect } from "react";
import styles from "./CSS/sidebar.module.css";

import Stock from "./WorkBench/NodesStock/Stock";

const Sidebar = () => {
  const onDragStart = (event, node) => {
    event.dataTransfer.setData("application/reactflow", JSON.stringify(node));
    event.dataTransfer.effectAllowed = "move";
  };

  return (
    <div className={`${styles.sidebar}`}>
      <p className={`${styles.sidebar_title}`}>Lista de Componentes</p>
      <span className={`${styles.sidebar_type_separator}`} />
      <Catalog onDragStart={onDragStart} />
    </div>
  );
};

const Catalog = ({ onDragStart }) => {
  const [types, setTypes] = useState([]);
  const newStock = Object.values(Stock);

  useEffect(() => {
    const uniqueTypes = [...new Set(newStock.map((item) => item.type))].filter(
      (type) => type !== "programable",
    );
    setTypes(uniqueTypes);
  }, []);

  return (
    <>
      {types.map((type) => {
        return (
          <div className={`${styles.sidebar_title}`} key={type}>
            {type.toUpperCase()}
            {newStock.map((item, index) => {
              return (
                item.type === type && (
                  <div key={index}>
                    <div className={styles.label}>{item.name}</div>
                    <img
                      className={`${styles.image}`}
                      src={item.url}
                      alt={item.name}
                      onDragStart={(event) => onDragStart(event, item)}
                      draggable
                    />
                  </div>
                )
              );
            })}
            <span className={`${styles.sidebar_type_separator}`} />
          </div>
        );
      })}
    </>
  );
};
export default Sidebar;
