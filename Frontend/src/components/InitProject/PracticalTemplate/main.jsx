import { useEffect, useState } from "react";
import styles from "./styles.module.css";
import axios from "axios";
import { useStateValue } from "@/context/StateContext";
import Loader from "@/utils/Modal/Loader";

export default function PorMatetPract() {
  const [{ base_url }, dispatch] = useStateValue();
  const [data, setData] = useState([]);
  const [isloading, setLoading] = useState(true);

  // Bases de datos disponibles
  const dataBases = [
    ["Institución", "catUniversities/"],
    ["Facultad", "catSchools/"],
    ["Carrera", "catCareers/"],
    ["Materia", "catSubjects/"],
    ["Práctica", "activity/"],
  ];

  // Función para obtener los datos
  async function fetchData(url) {
    const response = await axios(url);
    return response.data; // Devuelve los datos
  }

  //Hook para reealizar las busquedas
  useEffect(() => {
    // Función para buscar la base de datos
    const loadData = async () => {
      try {
        const allData = await Promise.all(
          dataBases.map((dataBase) => fetchData(base_url + dataBase[1])), // Buscamos por cada endPoint que tengamos
        );
        setData(allData); // Guarda todos los datos obtenidos
        setLoading(false);
      } catch (error) {
        console.error("Error al cargar los datos", error);
      }
    };

    loadData(); // Ejecutamos la busqueda de datos
  }, [base_url]); //Se actualizan las opciones cada que la url cambie

  // Mientras carga...
  if (isloading) {
    return <Loader />;
  }

  return (
    <div className={styles.card}>
      <div className={styles.container}>
        <h1>Por materia y práctica.</h1>

        {dataBases.map((select, index) => {
          const value = select[0];
          return (
            <div className={styles.content} key={value}>
              <label htmlFor={value} className={styles.label}>
                {value}
              </label>
              <select
                name={value}
                id={value.substring(0, 3)}
                className={`${styles.select}`}
              >
                {data[index]?.map((response) => {
                  return (
                    <option key={response.id} value={response.id}>
                      {response.name}
                    </option>
                  );
                })}
              </select>
            </div>
          );
        })}
      </div>
    </div>
  );
}
