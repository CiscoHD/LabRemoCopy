import { useContext, useRef, useEffect, useState } from "react";
import "./CSS/mesa.css";

import { RosContext } from "@/context/RosContext";
import { MenuContext } from "@/context/MenuContext";

import WorkBench from "./WorkBench/WorkBench";
import ConsoleOrVideo from "./ConsoleOrVideo";
import { ReactFlowProvider } from "@xyflow/react";
import { Editor } from "@monaco-editor/react";

export default function MainWorkSpace() {
  const ros = useContext(RosContext);
  const { coding, loading, loadedFile, setLoadFile } = useContext(MenuContext);
  const [editorContent, setEditorContent] = useState(
    "# En este espacio puedes escribir o modificar el código :)",
  );

  const editorRef = useRef(null);

  // Sincronizar `loadedFile` con el contenido del editor
  useEffect(() => {
    if (loadedFile) {
      setEditorContent(loadedFile);
    }
  }, [loadedFile]);

  // Mover el foco al editor cuando `coding` cambia
  useEffect(() => {
    if (coding && editorRef.current) {
      editorRef.current.scrollIntoView({ behavior: "smooth", block: "center" });

      setTimeout(() => {
        editorRef.current.querySelector("textarea")?.focus();
      }, 300);
    }
  }, [coding]);

  return (
    <div className="mesa">
      <ReactFlowProvider>
        <WorkBench />
      </ReactFlowProvider>

      <div className="consoleAndVideo">
        <ConsoleOrVideo title="Visualizar" icon="bi bi-power" video={true} />
        <ConsoleOrVideo title="Consola ~ LaboratorioRemoto" console={ros} />
      </div>
      {coding && (
        <div ref={editorRef}>
          <Editor
            height="40vh"
            theme="vs-dark"
            defaultLanguage="html"
            value={editorContent} 
            onChange={(value) => {
              setEditorContent(value);
              setLoadFile(value); 
            }}
          />
        </div>
      )}
      {loading && <div className="uploader-modal" />}
    </div>
  );
}
