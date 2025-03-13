import {
  forwardRef,
  useContext,
  useImperativeHandle,
  useRef,
  useState,
} from "react";
import buttons from "@/utils/Buttons/buttons.module.css";
import Modal from "@/utils/Modal/Modal";
import { MenuContext } from "@/context/MenuContext";

const UploadFile = forwardRef(function UploadFile({ button }, ref) {
  const upLoadFile = useRef(null);
  const loadFile = useRef(null);
  const [fileUploaded, setFileUploaded] = useState(null);
  const { setCoding, setLoadFile } = useContext(MenuContext);

  useImperativeHandle(
    ref,
    () => ({
      openModal() {
        loadFile.current.openModal();
      },
    }),
    [],
  );

  function handleUpLoad() {
    upLoadFile.current.click();
    setCoding(false);
  }

  function onLoad(e) {
    setFileUploaded(e.target.files[0]);
  }

  function handleFileLoad() {
    if (!fileUploaded) {
      alert("Por favor, selecciona un archivo antes de cargarlo.");
      return;
    }
    const reader = new FileReader();
    reader.onload = (e) => {
      const content = e.target.result;
      setLoadFile(content);
    };
    reader.readAsText(fileUploaded);
    setCoding(true);
    loadFile.current.closeModal();
  }

  return (
    <Modal button={button} ref={loadFile}>
      <h1>Sube tu código aquí</h1>
      <center style={{ display: "inline-flex", margin: "auto" }}>
        <input
          type="file"
          style={{ display: "none" }}
          onChange={onLoad}
          ref={upLoadFile}
        />
        <button
          onClick={handleUpLoad}
          className={`${buttons.main} ${fileUploaded ? buttons.green : ""}`}
        >
          {!fileUploaded ? (
            <i className="bi bi-file-arrow-up-fill" />
          ) : (
            <>
              <i
                className="bi bi-check-circle-fill"
                style={{ marginRight: "1em" }}
              />{" "}
              {fileUploaded.name}
            </>
          )}
        </button>
        <button className={buttons.main} onClick={handleFileLoad}>
          Cargar
        </button>
      </center>
    </Modal>
  );
});
export default UploadFile;
