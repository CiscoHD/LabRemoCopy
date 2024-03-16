import React, { useEffect, useRef, useState } from 'react'
import { Button } from '@mui/material'
import FormGroup from './FormGroup'

export default function LoginForm({loginEvent, cancelEvent, logedIn}) {

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

  const validateLoginForm = () => {
    username === "" && window.alert("Introduce tu usuario");
    password === "" ||   password.length <= 4
      ? window.alert("Introduce tu contraseña ")
      : logedIn(username,password);
  }

  useEffect(() => {
    usernameRef.current.focus();
  },[])


  return (
    <form onSubmit={handleSubmit} >
      {/*  */}
      <FormGroup
        label={'Nombre de usuario'}
        type={'username'}
        placeholder={'Introduce nombre de usuario'}
        value={username}
        onChange={userChange}
        reference={usernameRef}
      />
     <FormGroup
        label={'Contraseña'}
        type={'password'}
        placeholder={'Introduce la contraseña'}
        value={password}
        onChange={passChange}
        reference={passwordRef}
      />

      <div className="d-flex space-evenly mt-4">
                <Button className='bg-primary' type={'submit'}>Login</Button>
                <Button className='bg-dark' onClick={cancelEvent}>Cancel</Button>      
            </div>
    </form>
  )
}
