import { useState } from "react";
import styles from "./styles.module.css";
import button from "@/utils/Buttons/buttons.module.css";
import ModalWindow from "@/utils/Modal/Message";

export default function Contact() {
  const [dataForm, setDataForm] = useState({
    name: "",
    email: "",
    message: "",
  });

  const onResetInputs = () => {
    setDataForm({
      name: "",
      email: "",
      message: "",
    });
  };

  const { name, email, message } = dataForm;

  const [sendingData, setSendingData] = useState(false);

  const onInputChange = ({ target }) => {
    const { id, value } = target;
    setDataForm({
      ...dataForm,
      [id]: value.trim(),
    });
  };

  const sendingDataMessage = () => {
    setSendingData(true);
    setTimeout(() => {
      setSendingData(false);
      onResetInputs();
    }, 2000);
  };
  const handleSubmit = async (e) => {
    e.preventDefault();
    sendingDataMessage();
  };

  return (
    <>
      <div className={`${styles.contactPage}`}>
        <div className={`${styles.contactUs}`}>
          <div className={`${styles.mainText}`}>CONTACTANOS</div>
          <div className={`${styles.subTitle}`}>Dejanos un mensaje</div>
          <form className={`${styles.form}`} onSubmit={handleSubmit}>
            <input
              type="text"
              placeholder="Nombre"
              name="name"
              id="name"
              className={`${styles.input}`}
              value={name}
              onChange={onInputChange}
            />
            <input
              type="email"
              placeholder="Email*"
              name="email"
              id="email"
              className={`${styles.input}`}
              value={email}
              onChange={onInputChange}
              required
            />
            <label htmlFor="message" className={`${styles.message}`}>
              Mensaje
            </label>
            <textarea
              placeholder="Escribe tu mensaje aquí..."
              name="message"
              id="message"
              className={`${styles.textArea}`}
              value={message}
              onChange={onInputChange}
            ></textarea>
            <div
              type="submit"
              className={`${button.main}`}
              style={{ width: "10%" }}
            >
              Enviar
            </div>
          </form>
        </div>
        <div className={`${styles.sideBar}`}>
          <div>
            <div className={styles.title}> Direccion</div>
            <div className={styles.infoText}>
              porro tempore pariatur dolorem at suscipit molestiae, totam ab
              eligendi, tempora commodi dolores illum doloribus nemo nesciunt
              facilis blanditiis atque sint! Lorem ipsum dolor sit, amet
              consectetur adipisicing elit. A,
            </div>
          </div>
          <div>
            <div className={styles.title}>Redes Sociales </div>
            <div className={styles.icons}>
              <a
                href="https://www.facebook.com/"
                target="_blank"
                rel="noopener noreferrer"
              >
                <i
                  className={`bi bi-facebook ${styles.icon} ${styles.facebook}`}
                />
              </a>
              <a
                href="https://www.instagram.com/"
                target="_blank"
                rel="noopener noreferrer"
              >
                <i
                  className={`bi bi-instagram ${styles.icon} ${styles.instagram}`}
                />
              </a>
              <a
                href="https://www.x.com/"
                target="_blank"
                rel="noopener noreferrer"
              >
                <i
                  className={`bi bi-twitter-x ${styles.icon} ${styles.twitter}`}
                />
              </a>
              <a
                href="https://www.youtube.com/"
                target="_blank"
                rel="noopener noreferrer"
              >
                <i
                  className={`bi bi-youtube ${styles.icon} ${styles.youtube}`}
                />
              </a>
            </div>
          </div>
          <div>
            <div className={styles.title}>Email</div>
            <div className={styles.infoText}>
              Lorem ipsum dolor sit, amet consectetur adipisicing elit. Quisquam
              temporibus aliquam quos cumque, nisi amet voluptatum
              <p />
              itaque nobis enim magni quidem porro labore, quam sed recusandae
              fugiat consequatur officiis aspernatur.
            </div>
          </div>
        </div>
      </div>
      {sendingData && <ModalWindow>Gracias por su mensaje</ModalWindow>}
    </>
  );
}
