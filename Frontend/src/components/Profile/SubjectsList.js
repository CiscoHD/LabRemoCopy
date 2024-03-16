import { Button, Typography } from '@mui/material'
import React from 'react'

export default function SubjectsList() {
  return (
    <div>
        <Typography variant='h6'>Lista de asignaturas</Typography>
        <ul>
            {['Asignatura 1','Asignatura 2','Asignatura 3'].map((element)=>{
                return(
                <div>
                <li style={{
                    listStyle: 'none',
                    fontWeight: 'bold',
                }}>{element}</li>
                <div>
                <Button sx={{
                    margin: '4px',
                    background: '#4CAF50',
                    color: '#FFFFFF',
                    "&:hover": {
                        background: '#66BB6A',
                        color: '#333333'
                    }
                }}>Ver</Button>
                <Button sx={{
                    margin: '4px',
                    color: 'red',
                    background: 'yellow',
                    "&:hover": {
                        color: 'yellow',
                        background: 'red',
                    }
                }}>X</Button>
                </div>
                </div>
                )
            })}
    </ul>
    </div>
  )
}
