import React, {useState} from 'react'
import { useStateValue } from '../../context/StateContext';

import { actionTypes } from '../reducer';

import { Box, Select, Typography } from '@mui/material'
import { Button } from 'react-bootstrap';

import Selection from './Selection';
import Selector from '../Selector';
import SubTitleCol from '../SubTitleCol';



export default function Practicas() {

  const [{career,
          subject,
          practica,
          base_url,
        },dispatch] = useStateValue();

  //const [practica,setPractica]=useState('')

  return (
    <Box sx={{
        float: 'center',
        marginTop: '10px',
        paddingTop: '10px',
    }}>
        <Box sx={{
            width: '80%',
            margin: 'auto',
            borderBottom: 'groove',
            justifyContent: 'center',
        }}>
        <Typography variant='h7' sx={{
          fontWeight: 'bold',
        }}>
            Selección de parámetros necesarios
        </Typography>
        </Box>

        {/*<Selector url_api={base_url+'catCareers/'} disabled={school!='notSelected'?false:true} value={career} actionType={actionTypes.SET_CAREER} filter={school}/>*/}

        <Box sx={{
        paddingTop: '4%',
        width: '50%',
        margin: 'auto',
        borderBottom: 'groove',
        justifyContent: 'center',
        }}>
          <Box sx={{
            paddingBottom: 2,
          }}>
          <SubTitleCol>ID</SubTitleCol>
          <Selector url_api={base_url+'activity/'} disabled={subject!='notSelected'?false:true} value={practica} actionType={actionTypes.SET_PRACTICA} filter={subject}/>
          
          <SubTitleCol>Nombre</SubTitleCol>
          <Selector url_api={base_url+'activity/'} disabled={subject!='notSelected'?false:true} value={practica} actionType={actionTypes.SET_PRACTICA} filter={subject}/>

          <SubTitleCol>Asignatura</SubTitleCol>
          <Selector url_api={base_url+'catSubjects/'} disabled={career!='notSelected'?false:true} value={subject} actionType={actionTypes.SET_SUBJECT} filter={career} />
          </Box>
        </Box> 

        {/*
        <Selection label={'ID'} url={base_url+'catSubjects/'}/>
        <Selection label={'Nombre'}/>
        <Selection label={'Materia'}/>*/}

        <Button onClick={() => {
           document.getElementById('tab:rd:1').click();
        }} >Continuar</Button>



    </Box>
  );
};
