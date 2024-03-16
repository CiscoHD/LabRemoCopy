import React , {useState, useRef, useEffect} from 'react'
import '../components/nuevos/Login/newloginpage.css'
import { Form } from 'react-bootstrap'

import axios from "axios";
import queryString from "query-string";

import { useStateValue } from '../context/StateContext';
import { actionTypes } from "../components/reducer";


import { useHistory } from "react-router-dom/cjs/react-router-dom.min";

import logoLABREMO from '../media/labremfondo.png'


export default function NewLoginPage() {

  const LeftContainer = () => {

    const [{url_url,base_url,user},dispatch] = useStateValue();
    const history = useHistory();


    const [username, setUsername] = useState("");
    const [password, setPassword] = useState("");
  
    let usernameRef = useRef();
    let passwordRef = useRef();
    
    const userChange = (e) =>{
      setUsername(e.target.value);
    }
    const passChange = (e) =>{
      setPassword(e.target.value);
    }

    const changeInputs = (e) =>{
      usernameRef.current.focus() && setUsername(e.target.value);
      passwordRef.current.focus() && setPassword(e.target.value);
    }

    const handleSubmit = (e) =>{
      e.preventDefault();
      const event = {
        username: username,
        password: password,
        id: Math.floor(Math.random()*1000)
      };
      console.log(event);
      validateLoginForm(); 
    }

    const resetForm = () =>{
      setUsername("");
      setPassword("");
    }

    const handleLoginFormValidation = async (user,password) =>{

      const url=`${url_url}/o/token/`
      const client_id = 'BdrMvIejh8f9CmkRTnuf76A5oKY5eELw7TERgrrH'
      //const pass_client = 'fdsiCxbawLYF2nTM4WleTyvYt08UEJwzha5mmL2Ca5FZ2HGWDxGHiNpS5E7pMN10mHOlQygX2NdQhnJtkKAITaxXMTZHAIWwerzdcDQ8ovgsDZg3jEwgfm5mhItcU0mf'
      const pass_client = 'a4kqJnDxjRGpuT5lCqK8FAbOmgK2skiWellmnJqphgfefpxFbzapWoNzGAaFaFmNCQfRGKtI9YM33tn5L8GxM8Vi41tCYG9u7m7h5togJHIxniwtb1n7ajgzgjQYjIqG'

      const user_token = 0;

      const data = {
          grant_type: 'password',
          username: user,
          password: password,
      };

      const auth = {
          username: client_id,
          password: pass_client,
      };

      const options = {
          method: 'post',
          headers: {
              "Content-Type": "application/x-www-form-urlencoded",
          },
          data: queryString.stringify(data),
          auth: auth,
          url,

      }
      
      const response = await axios(options)
      .then(res => {
          console.log("lelelelele",res)

          console.log(user)

          dispatch({
              type: actionTypes.SET_USER,
              name: user,
              token: res.data.access_token
          })
          //setIsNew(true)
          //history.push("/profile");
          history.push("/welcome");
      })
      .catch(err => {
        if (err.response.status === 400) {
          //Auth failed
          //Call reentry function
          //console.log("lalala");
          //console.log(err.response.data);
          window.alert(err.response.data.error_description)
          //console.log("lalala");
          return;
        }
        return console.log(err)
      });

      {/*
      const {res} = await axios.post(url,
          queryString.stringify(
              {
                  'grant_type':'password',
                  //'grant_type':'client_credentials',
                  'username': user,
                  'password': password,
                  'Content-Type':'application/x-www-form-urlencoded',
                  'Authorization': 'Basic '+client_id+':'+pass_client,
              })
          )
          */}
      console.log(url,data)
  }

    const validateLoginForm = () => {
      username === "" && window.alert("Introduce tu usuario");
      password === "" ||   password.length <= 4
        ? window.alert("Introduce tu contraseña ")
        : handleLoginFormValidation(username,password);
    }
  
    useEffect(() => {
      usernameRef.current.focus();
    },[])


    return(
    <div className="login-left-container">
      <div>
      <div className="login-text">
        Login
      </div>
      <div className="login-subtitle">
        Introduce tus datos de usuario
      </div>

      <form onSubmit={handleSubmit}>
      <div className="datalog">
        <input type="text" placeholder='Usuario' onChange={userChange} ref={usernameRef}/>
        <input type="password" placeholder='Contraseña' onChange={passChange} ref={passwordRef} />
      </div>
      <button className="boton-login" type={'submit'}>Entrar</button>
      </form>
      </div>
    </div>
    )
  }

  const RightContainer = () => {
      return(
        <div className="welcome-right-container">
        <div>
        <img className='welcome-logo' src={logoLABREMO} alt="" />
        <div className="welcome-title">
          ¡Bienvenido!
        </div>
        
        </div>
        </div>
      )
  }

  return (
    <div>
      <div className="double-spacing"></div>
      <div className="login-container">

        <LeftContainer />
        <RightContainer />

      </div>
    </div>
  )
}
