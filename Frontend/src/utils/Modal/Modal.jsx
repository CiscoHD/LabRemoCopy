import { forwardRef, useImperativeHandle, useRef, useState } from "react";
import styles from "./styles.module.css";
import buttons from "@/utils/Buttons/buttons.module.css";

const Modal = forwardRef(function Modal({ children, button = null }, ref) {
  const dialogRef = useRef(null);
  const [isOpen, setIsOpen] = useState(false);

  useImperativeHandle(ref, () => ({
    openModal: openDialog,
  }));

  const openDialog = () => {
    setIsOpen(true);
    dialogRef.current.showModal();
  };

  const closeDialog = () => {
    setIsOpen(false);

    setTimeout(() => {
      dialogRef.current.close();
    }, 300);
  };

  const handleDialogClick = (e) => {
    // Verifica si el clic ocurre fuera del contenido del modal
    if (e.target === dialogRef.current) {
      closeDialog();
    }
  };

  return (
    <>
      <dialog
        ref={dialogRef}
        className={`${styles.dialog} ${isOpen ? styles.open : styles.hidden}`}
        onClick={handleDialogClick}
      >
        <button
          onClick={closeDialog}
          className={` ${buttons.main} ${buttons.return}`}
          style={{ width: "10px", borderRadius: "15px", padding: "1em" }}
        >
          <i className="bi bi-x-circle" />
        </button>
        {children}
      </dialog>
      {button && (
        <button
          style={{
            border: "none",
            backgroundColor: "#fff0",
            borderRadius: "15px",
            padding: "0",
          }}
          onClick={openDialog}
        >
          {button}
        </button>
      )}
    </>
  );
});

export default Modal;
