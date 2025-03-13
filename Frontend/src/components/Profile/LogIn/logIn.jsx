import { useState } from "react";
import styles from "./styles.module.css";
import buttons from "@/utils/Buttons/buttons.module.css";

import axios from "axios";
// import queryString from "query-string";

import { useStateValue } from "@/context/StateContext";
import { actionTypes } from "@/context/Reducer/reducer";

import logoLABREMO from "@/assets/labRemo.png";
import ModalWindow from "@/utils/Modal/Message";

export const LogIn = () => {
  const [{ url_url, base_url, user }, dispatch] = useStateValue();

  const [dataForm, setDataForm] = useState({
    username: "",
    password: "",
  });

  const { username, password } = dataForm;

  const onInputChange = ({ target }) => {
    const { id, value } = target;
    setDataForm({
      ...dataForm,
      [id]: value.trim(),
    });
    id == "username" ? setErrorUsername("") : setErrorPassword("");
  };

  const onResetInputs = () => {
    setDataForm({
      username: "",
      password: "",
    });
    setErrorPassword(false);
    setErrorUsername(false);
  };

  const [sendingData, setSendingData] = useState(false);

  const [errorUsername, setErrorUsername] = useState(false);
  const [errorPassword, setErrorPassword] = useState(false);

  const sendingDataMessage = () => {
    setSendingData(true);
    setTimeout(() => {
      setSendingData(false);
      onResetInputs();
    }, 2000);
  };

  const handleSubmit = async (e) => {
    e.preventDefault();

    setErrorUsername(false);
    setErrorPassword(false);

    let valid = true;
    if (!username) {
      setErrorUsername(true);
      valid = false;
    }
    if (password.length <= 4) {
      setErrorPassword(true);
      valid = false;
    }

    if (!valid) return;

    sendingDataMessage();

    await handleLoginFormValidation(username, password);
  };

  const handleLoginFormValidation = async (user, password) => {
    const url = `${url_url}/o/token/`;
    const client_id = "BdrMvIejh8f9CmkRTnuf76A5oKY5eELw7TERgrrH";
    const pass_client =
      "a4kqJnDxjRGpuT5lCqK8FAbOmgK2skiWellmnJqphgfefpxFbzapWoNzGAaFaFmNCQfRGKtI9YM33tn5L8GxM8Vi41tCYG9u7m7h5togJHIxniwtb1n7ajgzgjQYjIqG";

    const user_token = 0;

    const data = {
      grant_type: "password",
      username: user,
      password: password,
    };

    const auth = {
      username: client_id,
      password: pass_client,
    };

    const options = {
      method: "post",
      headers: {
        "Content-Type": "application/x-www-form-urlencoded",
      },
      data: queryString.stringify(data),
      auth: auth,
      url,
    };

    const response = await axios(options)
      .then((res) => {
        console.log(res);

        console.log(user);

        dispatch({
          type: actionTypes.SET_USER,
          name: user,
          token: res.data.access_token,
        });
      })
      .catch((err) => {
        if (err.response.status === 400) {
          window.alert(err.response.data.error_description);
          return;
        }
        return console.log(err);
      });

    {
      const { res } = await axios.post(
        url,
        queryString.stringify({
          grant_type: "password",
          //'grant_type':'client_credentials',
          username: user,
          password: password,
          "Content-Type": "application/x-www-form-urlencoded",
          Authorization: "Basic " + client_id + ":" + pass_client,
        }),
      );
    }
    console.log(url, data);
  };

  return (
    <div className={styles.container}>
      <div className={styles.card}>
        <img
          className={styles.logo}
          src={logoLABREMO}
          alt="Laboratorio Remoto"
        />
        <form className={styles.formStyle} onSubmit={handleSubmit}>
          <div className={styles.section}>
            <div className={styles.title}>Inicio de sesión</div>
          </div>
          <div className={styles.section}>
            <label className={styles.label} htmlFor="username">
              Nombre de usuario:
            </label>
            <input
              id="username"
              type="text"
              placeholder="Usuario"
              value={username}
              onChange={onInputChange}
              className={styles.input}
            />
            {errorUsername && (
              <div className={styles.error}>Introduzca su nombre</div>
            )}
          </div>

          <div className={styles.section}>
            <label className={styles.label} htmlFor="password">
              Contraseña:
            </label>
            <input
              id="password"
              type="password"
              placeholder="Contraseña"
              value={password}
              onChange={onInputChange}
              className={styles.input}
            />
            {errorPassword && (
              <div className={styles.error}>
                La contraseña debe ser mayor a 4 carácteres
              </div>
            )}
          </div>
          <div className={styles.section}>
            <div className={styles.buttons}>
              <button
                className={`${buttons.main} ${buttons.green}`}
                type="submit"
              >
                Iniciar sesión
              </button>
              <button
                type="reset"
                className={`${buttons.main} ${buttons.return}`}
                onClick={onResetInputs}
              >
                Limpiar datos
              </button>
            </div>
          </div>
        </form>
        {sendingData && <ModalWindow>Guardando...</ModalWindow>}
      </div>
    </div>
  );
};
