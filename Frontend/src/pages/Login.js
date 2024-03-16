import "../components/Login/login.css";
import React, { useState } from 'react'
import axios from "axios";
import queryString from "query-string";


import { useStateValue } from '../context/StateContext';
import { actionTypes } from "../components/reducer";


import { Box, Button, Typography } from '@mui/material'
import { Link } from "react-router-dom/cjs/react-router-dom.min";
import { useHistory } from "react-router-dom/cjs/react-router-dom.min";

import Modal from "../components/Login/Modal";




export default function Login() {

    const [{base_url,user},dispatch] = useStateValue();
    const history = useHistory();

    const [name,setName] = useState('');
    const [password, setPassword] = useState('');
    const [isNew, setIsNew] = useState(true);


    const handleLoginFormValidation = async (user,password) =>{

        const url='http://localhost:8000/o/token/'
        const client_id = 'Z2WLwCHokMdJmIDyxfssyUoyrcTOHZSs5HTjEDaC'
        //const pass_client = 'fdsiCxbawLYF2nTM4WleTyvYt08UEJwzha5mmL2Ca5FZ2HGWDxGHiNpS5E7pMN10mHOlQygX2NdQhnJtkKAITaxXMTZHAIWwerzdcDQ8ovgsDZg3jEwgfm5mhItcU0mf'
        const pass_client = 'hWVz7r5finSL8LSSo2kBrsIQQYgITQxWCyshKz7m8uBZavbJO2cNIuIEuu2dEzpB6mgjOcoWfWBBLyd4V5pCGaHB9RfKMNQXSrDj3gx6aImxa5gWvmio7bxMFD7TjxJA'

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
            history.push("/#");
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
        console.log("lalalala",response);

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

    const handleName = (value) => {
        console.log(value)
        setName(value)
    }

    const Looogin = ({label}) => {

        return(

            !isNew &&
            <Box className='login-t2'>
                <Modal title={'Login'}
                text={'Introduce tus datos de usuario'}
                cancelEvent={() => {
                        setIsNew(!isNew);
                    }
                }
                logedIn={handleLoginFormValidation}
                />
            </Box>
        );
    }

    const Registro = ({label}) =>{
        return(<Box>
            <Typography variant="h5" sx={{color: '#ff0000'}}>Aún no tenemos un sistema de registro abierto, por favor ponte en contacto con el Administrador</Typography>
        </Box>
        )
    }

  return (
    <div>
        <Box className='login-title'>
            <Typography variant="h6">Login</Typography>
        </Box>
        <Box>
            <Box>
                <Typography variant="h7">Soy usuario nuevo,<span> </span>
                <Link onClick={() => {
                        setIsNew(true)
                        alert('Por el momento no contamos con un sistema de registro activo, contacta al administrador')
                    }} 
                    to='/login'
                    >Registrate</Link></Typography>
            </Box>
            <Box>
                <Typography variant="h7">Ya tengo cuenta,<span> </span>
                <Link 
                    to='/login'
                    onClick={() => {
                        setIsNew(false)
                    }}
                    >Iniciar Sesión</Link> </Typography>
            </Box>
            
        </Box>

        <Box>
            { isNew ? <Registro />: <Looogin label="Iniciar Sesión"/>}
        </Box>
    </div>
  )
}
