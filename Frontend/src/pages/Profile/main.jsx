import { useState } from "react";
import labRemo from "@/assets/labRemo.png";
import Protector from "@/components/Protector";

import LandingPage from "@/utils/LandingPage/LandingPage";
import Profile from "@/components/Profile/Profile";

import PersonalData from "@/components/Profile/PersonalData";
import SubjectsList from "@/components/Profile/SubjectsList";
import ActivityList from "@/components/Profile/ActivityList";
import Grades from "@/components/Profile/Grades";
import Roster from "@/components/Profile/Roster";
import CRUD from "@/components/Profile/CRUD";

import styles from "./styles.module.css";

export default function MainProfile() {
  const [colContent, setColContent] = useState(null);
  const [isSelected, setIsSelected] = useState("");

  const consultar = [
    "Datos personales[A/P/E]",
    "Asignaturas[A/P/E]",
    "Practicas[A/P/E]",
    "Notas[A/E]",
    "Lista[A/P]",
    "Calificar[A/P]",
    "Agregar/Editar practicas[A/P]",
  ];

  const Col2 = () => {
    switch (colContent) {
      case "dato":
        return (
          <Protector>
            <PersonalData />
          </Protector>
        );
      case "asig":
        return (
          <Protector>
            <SubjectsList />
          </Protector>
        );
      case "prac":
        return (
          <Protector>
            <ActivityList />
          </Protector>
        );
      case "nota":
        return (
          <Protector>
            <Grades />
          </Protector>
        );
      case "cali":
        return (
          <Protector>
            <LandingPage />
          </Protector>
        );
      case "list":
        return (
          <Protector>
            <Roster />
          </Protector>
        );
      case "agre":
        return (
          <Protector>
            <CRUD />
          </Protector>
        );
      default:
        return <Profile />;
    }
  };

  return (
    <div className={`${styles.main}`}>
      <div className={`${styles.menu_list}`}>
        <img
          src={labRemo}
          alt="Logo"
          className={`${styles.image}`}
          onClick={() => {
            setColContent("");
            setIsSelected(null);
          }}
        />
        {consultar.map((element) => {
          return (
            <div key={element}>
              <div
                className={`${styles.option} ${
                  isSelected === element && styles.selected
                }`}
                onClick={() => {
                  setColContent(element.substring(0, 4).toLowerCase());
                  setIsSelected(element);
                }}
              >
                {element}
              </div>
            </div>
          );
        })}
      </div>
      <div className={`${styles.content}`}>{<Col2 />}</div>
    </div>
  );
}
