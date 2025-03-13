import { useNavigate } from "react-router-dom";
import styles from "./styles.module.css";

export default function Welcome() {
  const navigate = useNavigate();

  const welcomeMenu = [
    {
      label: "Acceso a Laboratorio Remoto",
      to: `/lab`,
      external: false,
    },
    { label: "Guía de Usuario", to: "/profile/user", external: false },
    {
      label: "Registrarse",
      to: "mailto:victor@aries.iimas.unam.mx",
      external: true,
    },
    { label: "Aula Virtual", external: true },
  ];

  const handleClick = (item) => {
    if (item.external) {
      location.href = item.to;
    } else {
      navigate(item.to);
    }
  };

  return (
    <div className={`${styles.container}`}>
      <div className={`${styles.welcome}`}>
        <div className={`${styles.lab}`} />
      </div>

      {/* Menu inicial */}
      <div className={`${styles.links}`}>
        {welcomeMenu.map((item, i) => (
          <div
            key={i}
            className={`${styles.element}`}
            onClick={() => handleClick(item)}
          >
            {item.label}
          </div>
        ))}
      </div>
    </div>
  );
}
