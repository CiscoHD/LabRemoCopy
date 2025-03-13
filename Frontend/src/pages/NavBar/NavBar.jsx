import styles from "./navbar.module.css";
import { useRef, useEffect, useContext } from "react";
import { NavLink } from "react-router-dom";
import { MenuContext } from "@/context/MenuContext";

import navMenu from "./navMenu";
import logoUNAM from "@/assets/media/Logos/LogoUNAM.png";
import logoIIMAS from "@/assets/media/Logos/LogoIIMAS_Color.png";

export default function NavBar() {
  const current = useRef();
  const { currentWindow, setCurrentWindow, urlToInt, setCoding } =
    useContext(MenuContext);

  useEffect(() => {
    const handlePopState = () => {
      setCurrentWindow(urlToInt(location.pathname));
    };

    //Cada que regresemos o avancemos en la pag se actualiza la posición
    window.addEventListener("popstate", handlePopState);

    return () => {
      window.removeEventListener("popstate", handlePopState);
    };
  }, [setCurrentWindow, urlToInt]);

  useEffect(() => {
    setCurrentWindow(urlToInt(location.pathname));
  }, [location, setCurrentWindow, urlToInt]);

  return (
    <div ref={current} className={`${styles.navbar}`}>
      <div className={`${styles.logos}`}>
        <NavLink to={"https://www.unam.mx/"} className={`${styles.logoLink}`}>
          <img className={`${styles.logo}`} src={logoUNAM} alt="Logo Unam" />
        </NavLink>
        <NavLink to={"https://www.iimas.unam.mx/"} className={`${styles.logo}`}>
          <img className={`${styles.logo}`} src={logoIIMAS} alt="Logo IIMAS" />
        </NavLink>
      </div>
      <div className={`${styles.navmenu}`}>
        {navMenu.map((item, index) => {
          return (
            <NavLink
              key={item.label}
              to={"/" + item.url}
              onClick={() => {
                setCurrentWindow(index);
                setCoding(false);
              }}
              className={`${styles.item_menu} ${
                currentWindow === index && styles.selected
              } `}
            >
              {item.label}
            </NavLink>
          );
        })}
      </div>
    </div>
  );
}
