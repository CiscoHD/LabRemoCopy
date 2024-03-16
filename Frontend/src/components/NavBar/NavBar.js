import React from 'react'

import { useStateValue } from '../../context/StateContext';

import { Box } from '@mui/material'

import NavLink from './NavLink'

export default function NavBar() {

  const [{user},dispatch] = useStateValue();

  console.log("user",user);

  return (
    <Box sx={{ 
      display: 'flex',
      alignContent: 'center',
      justifyContent: 'center',
       }}>
      <NavLink url={'/'}>Inicio</NavLink>
      <NavLink url={'/content'}>Practicas</NavLink>
      <NavLink url={'/workbench'}>Workbench</NavLink>
      <NavLink url={!
        user.token
        ?'/login'
        :'/profile'
      }>
      {
        !user.token
        ?'Login'
        :`Bienvenido ${user.username}`
        
      }
      </NavLink>
    </Box>
  )
}
