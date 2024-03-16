import React from 'react'


import { useHistory } from "react-router-dom/cjs/react-router-dom.min";
import { useStateValue } from '../context/StateContext'


import { Box,Button,Typography } from '@mui/material'

export default function Profile() {
    const [{user},dispatch] = useStateValue();
    const history = useHistory();

    const Perfil = () => {
      return (
      <Box>
      <Typography variant='h5' className='pt-4'>Bienvenido a tu perfil {user.username}</Typography>
      <Box sx={{
        width: '500px',
        margin: 'auto',
        //border: '3px solid #73AD21',
      }}>
          <Typography variant='h8'>En tu perfil puedes editar tus datos de usuario, administrar tus asignaturas, 
          ver tus prácticas realizadas, avances y las notas asignadas a tus trabajos.  </Typography>
          
        <Button className='bg-dark' onClick={() => history.push('/abstractProfile/')}>GO</Button>
      </Box>
  </Box>
  )}

    const Perfilnt = () =>{
      history.push('/login')
    }


  return (
    user.username
    ? <Perfil />
    : <Perfilnt />    
  )
}
