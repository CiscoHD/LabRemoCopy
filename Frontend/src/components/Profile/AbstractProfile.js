import { Box, Typography } from '@mui/material'
import { hover } from '@testing-library/user-event/dist/hover'
import React, { useState } from 'react'
import { Link } from 'react-router-dom/cjs/react-router-dom.min'
import PersonalData from './PersonalData'
import { useHistory } from 'react-router-dom/cjs/react-router-dom'
import { Col } from 'react-bootstrap'
import SubjectsList from './SubjectsList'
import ActivityList from './ActivityList'
import Grades from './Grades'
import CRUD from '../ActivitiesCRUD/CRUD'
import Roster from './Roster'

export default function AbstractProfile() {
  const [colContent,setColContent] = useState(null);

  const history = useHistory();

  const Col2 = () => {
    switch(colContent){
      case "dato":
        return(
          <PersonalData />
        );
      case "asig":
        return(
          <SubjectsList />
        );
      case "prac":
        return(
          <ActivityList />
        );
      case "nota":
        return (
          <Grades />
        );
      case "list":
        return(
          <Roster />
        )
      case "agre":
        return (
          <CRUD />
        )
      default:
        return(
          <></>
        );
    }
  }

  return (
    <Box className='pt-2'>
      <Box className='pt-4'  sx={{
      display: 'flex',
      width: '70%',
      margin: 'auto',
      boxShadow: '0 0 10px rgba(0, 0, 0, 0.2)',
    }}>
      <Box sx={{
          flex: '20%',
          border: 'dashed',
          borderRadius: '5px',
          margin: '10px',
      }}>
        <ul style={{
          listStyle: 'none',
        }}>
        {
          ['Datos personales[A/P/E]','Asignaturas[A/P/E]','Practicas[A/P/E]','Notas[A/E]','Lista[A/P]','Calificar[A/P]','Agregar/Editar practicas[A/P]'].map((element) => {
            return(
              <li>
              <Typography variant='h8'
              onClick={()=>{
                setColContent(element.substring(0,4).toLowerCase());
              }}
              sx={{
              "&:hover": {
                  margin: '8px',
                  fontWeight: 'bold',
                  cursor: 'pointer'
                },
              }}
            >{element}</Typography>
            </li>   
            )
          })
        }
        </ul>
      </Box>
      <Box sx={{
          flex: '60%',
          border: 'dashed',
          borderRadius: '5px',
          margin: '10px',
      }}>
      
      {colContent && <Col2 />}

      </Box>
      </Box>
    </Box>
  )
}