import { useNavigate } from "react-router-dom";
import { useStateValue } from "@/context/StateContext";

import styles from "./CSS/profile.module.css";
import buttons from "@/utils/Buttons/buttons.module.css";

export default function Profile() {
  const [{ user }, dispatch] = useStateValue();
  const navigate = useNavigate();

  return (
    <div className={styles.content}>
      <div className={styles.title}>Bienvenido a tu perfil {user.username}</div>
      <div className={styles.welcome}>
        En tu perfil puedes editar tus datos de usuario, administrar tus
        asignaturas, ver tus prácticas realizadas, avances y las notas asignadas
        a tus trabajos.
      </div>
      <br />
      {/* Mostrar botones solo si no se ha iniciado sesión */}
      {!user.username && (
        <div className={styles.buttons}>
          <div
            className={` ${buttons.main}`}
            style={{ margin: "5px" }}
            onClick={() => navigate("/login")}
          >
            Iniciar sesión
          </div>
          <div
            className={`${buttons.main}`}
            style={{ margin: "5px" }}
            onClick={() =>
              (window.location.href = "mailto:victor@aries.iimas.unam.mx")
            }
          >
            Registrarse
          </div>
        </div>
      )}
    </div>
  );
}
