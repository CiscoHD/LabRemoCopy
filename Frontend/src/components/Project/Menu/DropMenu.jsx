import { useContext, useRef, useState } from "react";
import { MenuContext } from "@/context/MenuContext";
import styles from "./styles.module.css";

import Sidebar from "../Sidebar";
import UploadFile from "./Modals/UploadFile";
import SaveProject from "./Modals/SaveProject";

const DropMenu = () => {
  const [sidebarActive, setSidebarActive] = useState(false);
  const [dropped, setDropped] = useState(false);
  const { saveSession, coding, setCoding } = useContext(MenuContext);
  const uploadRef = useRef(null);

  const handleToolsClick = () => {
    setSidebarActive(!sidebarActive);
  };

  return (
    <>
      <div className={`${styles.container} ${dropped ? styles.dropped : ""}`}>
        <div className={styles.arrow}>
          <i
            className={`bi ${styles.mainIcon} ${
              dropped ? "bi-caret-right-fill" : "bi-caret-left-fill"
            }`}
            title="Herramientas"
            onClick={() => {
              setDropped(!dropped);
            }}
          />
        </div>
        <div className={`${styles.mainIcons} `}>
          <UploadFile
            ref={uploadRef}
            button={
              <i
                className={`bi bi-file-earmark-arrow-up ${styles.icon}`}
                title="Subir código"
              />
            }
          />
          <SaveProject
            ref={uploadRef}
            button={
              <i
                className={`bi bi-cloud-upload ${styles.icon}`}
                title="Guardar proyecto"
                onClick={saveSession}
              />
            }
          />
          <i
            className={`bi bi-code-square ${styles.icon} ${coding ? styles.active : ""}`}
            title="Programar"
            onClick={() => setCoding(!coding)}
          />
          <i
            className={`${styles.icon} ${
              !sidebarActive ? "bi bi-nut" : "bi bi-nut-fill"
            } ${!sidebarActive ? "" : styles.active}`}
            title="Componentes"
            onClick={handleToolsClick}
          />
        </div>
      </div>
      {sidebarActive && <Sidebar />}
    </>
  );
};

export default DropMenu;
