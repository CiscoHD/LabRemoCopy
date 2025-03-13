import { useState } from "react";
import { Outlet, useNavigate } from "react-router-dom";

import styles from "./styles.module.css";
import buttons from "@/utils/Buttons/buttons.module.css";

import Protector from "@/components/Protector";

export const ContinueButton = () => {
  const navigate = useNavigate();

  return (
    <div
      className={`${buttons.green} ${buttons.main}`}
      onClick={() => {
        navigate("/lab/workbench");
      }}
    >
      Continuar
    </div>
  );
};

export const ModalWindow = ({ children }) => {
  return (
    <div className={styles.overlay_modal}>
      <div className={styles.info_card}>{children}</div>
    </div>
  );
};

export const SavingButton = ({ message }) => {
  const [isSaving, setIsSaving] = useState(false);

  const handleSaveClick = () => {
    setIsSaving(true);
    setTimeout(() => {
      setIsSaving(false);
    }, 2000);
  };

  return (
    <div>
      <div
        className={`${buttons.green} ${buttons.main}`}
        onClick={handleSaveClick}
      >
        {isSaving ? "Guardando..." : "Guardar"}
      </div>
      {isSaving && <ModalWindow>{message}</ModalWindow>}
    </div>
  );
};

export default function InitProyect() {
  const [optionSelected, setOptionSelected] = useState(0);
  const navigate = useNavigate();

  return (
    <Protector>
      <div className={styles.container}>
        <div className={styles.selection}> Seleccione: </div>
        <div className={styles.menutab}>
          {["nuevo", "sesion", "plantilla"].map((item, index) => {
            const arreglo = {
              0: "Por tarjeta de trabajo",
              1: "Por sesión almacenada",
              2: "Por plantilla de práctica",
            };

            return (
              <div
                key={index}
                className={`${buttons.main} ${optionSelected === index ? buttons.active : buttons.normal
                  }`}
                onClick={() => {
                  setOptionSelected(index);
                  navigate(item);
                }}
              >
                {arreglo[index]}
              </div>
            );
          })}
        </div>
        <Outlet />

        <div className={buttons.default_buttons}>
          {optionSelected === 2 && (
            <SavingButton
              message={"Los datos se han guardado correctamente."}
            />
          )}
          {optionSelected === 0 && <ContinueButton />}
          <div
            className={`${buttons.return} ${buttons.main}`}
            onClick={() => {
              navigate(`/`);
            }}
          >
            Volver
          </div>
        </div>
      </div>
    </Protector>
  );
}
