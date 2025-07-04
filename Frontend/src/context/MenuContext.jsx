import { createContext, useState, useEffect } from "react";
import navMenu from "@/pages/NavBar/navMenu";

export const MenuContext = createContext();

export function MenuProvider({ children }) {
  // Nos indica en que ventana estamos
  const [currentWindow, setCurrentWindow] = useState(0);

  // Para veeridficar si el Workbench se cargo
  const [reactFlowInstance, setReactFlowInstance] = useState(null);

  // Para ver cuando algo carga
  const [loading, setLoading] = useState(false);

  // Mientras programas
  const [coding, setCoding] = useState(false);

  // Acrhivo cargado
  const [loadedFile, setLoadFile] = useState(false);

  // Para ver cuando
  const [boardChoosen, setBoardChoosen] = useState(null);

  // Cargar el último programable guardado al inicializar
  useEffect(() => {
    const lastProgramable = localStorage.getItem('lastProgramable');
    if (lastProgramable) {
      setBoardChoosen(lastProgramable);
    }
  }, []);

  const urlToInt = (currentUrl) => {
    return [...new Set(navMenu.map((item) => item.url))].indexOf(
      currentUrl.replace(/^\//, "").split("/")[0] || "",
    );
  };

  return (
    <MenuContext.Provider
      value={{
        //Variables
        currentWindow,
        reactFlowInstance,
        loading,
        boardChoosen,
        coding,
        loadedFile,
        //Functions
        setCurrentWindow,
        setReactFlowInstance,
        setLoading,
        setBoardChoosen,
        urlToInt,
        setCoding,
        setLoadFile,
      }}
    >
      {children}
    </MenuContext.Provider>
  );
}
