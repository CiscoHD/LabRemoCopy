import { useEffect, useState } from "react";
import user from "@/assets/media/user.png";
import styles from "./styles.module.css";
import Loader from "@/utils/Modal/Loader";

export default function UsPage() {
  const [staffs, setStaff] = useState([]);
  const [isloading, setIsLoading] = useState(true);

  const fetchData = async () => {
    try {
      const fetchStaff = await fetch(
        "https://jsonplaceholder.typicode.com/users",
      );
      const data = await fetchStaff.json();
      setStaff(data);
      setIsLoading(false);
    } catch (error) {
      console.log(error);
    }
  };

  useEffect(() => {
    fetchData();
  }, []);

  if (isloading) {
    return <Loader />;
  }
  return (
    <div className={`${styles.container} `}>
      {staffs.map((staff) => (
        <div key={staff.id} className={styles.card}>
          <img src={user} alt="Miembro del equipo" className={styles.image} />
          <div className={`${styles.info} `}>
            <i className={`bi bi-person-fill ${styles.icon}`} />
            <div className={styles.text}>{staff.name}</div>
            <i className={`bi bi-envelope-fill ${styles.icon}`} />
            <div className={styles.text}>{staff.email}</div>
          </div>
        </div>
      ))}
    </div>
  );
}
