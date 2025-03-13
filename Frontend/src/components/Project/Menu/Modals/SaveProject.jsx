import { forwardRef, useImperativeHandle, useRef, useEffect } from "react";
import Modal from "@/utils/Modal/Modal";
import styles from "@/utils/input.module.css";
import buttons from "@/utils/Buttons/buttons.module.css";

const SaveProject = forwardRef(function SaveProject({ button }, ref) {
  const inputRef = useRef(null);
  const modalRef = useRef(null);

  useImperativeHandle(
    ref,
    () => ({
      openModal() {
        if (modalRef.current) {
          modalRef.current.openModal();
        }
      },
    }),
    [],
  );

  useEffect(() => {
    if (inputRef.current) {
      inputRef.current.focus();
    }
  }, []);

  return (
    <Modal button={button} ref={modalRef}>
      <h1>Nombre del proyecto</h1>
      <center style={{ display: "inline-flex", margin: "auto" }}>
        <input
          type="text"
          ref={inputRef}
          placeholder="Ingrese el nombre del proyecto"
          aria-label="Nombre del proyecto"
          className={styles.input}
        />
        <button className={buttons.main}>Guardar</button>
      </center>
    </Modal>
  );
});

export default SaveProject;
