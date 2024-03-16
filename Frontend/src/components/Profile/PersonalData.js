import React from 'react'
import { Box } from '@mui/material'


import FormGroup from '../Login/FormGroup'


export default function PersonalData() {
  return (
    <Box sx={{
        alignContent: 'center',
        width: '50%',
        margin: 'auto',
    }} >
        Datos personales

        <FormGroup
        label={'Nombre de usuario'}
        type={'username'}
        placeholder={'Introduce nombre de usuario'}
        value={'sdev01'}
        disabled={true}
        />

        <FormGroup
        label={'Correo Electrónico'}
        type={'email'}
        value={'a@a.com'}
        disabled={true}
        />

        <FormGroup
        label={'Tipo de usuario'}
        type={'userType'}
        value={'admin[A]'}
        disabled={true}
        />
      
      
      
      
      </Box>
  )
}
