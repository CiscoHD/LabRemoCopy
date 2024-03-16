import React from 'react'
import { Box, Typography, Button, useTheme } from '@mui/material'

import PorMatetPract from '../components/PorMatetPract'

import { actionTypes } from '../components/reducer'
import { useStateValue } from '../context/StateContext'
import { Link } from 'react-router-dom'
import theme from '../components/Theme'




export default function SessionTypeSelection() {


  const mytheme = useTheme(theme)

  const [{},dispatch] = useStateValue();
  
  return (
    <Box sx={mytheme.estilo1}>
      <Box>
      <Typography variant='h4'>
        Escoja tipo de sesión
      </Typography>
      
      <PorMatetPract />


      <Link to="/content">
      <Button sx={{
        backgroundColor: '#3C887E',
        color: '#FFFFFF',
      }}>Entrar</Button>
        </Link>
      </Box>
      
    </Box>
  )
}
