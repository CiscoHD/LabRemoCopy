import React from 'react'

import { Button, Typography } from '@mui/material'

export default function Roster() {
    return (
        <div>
            <Typography variant='h6'>Lista de Prácticas</Typography>
            <ul>
                {['Alumno 1',
                'Alumno 2',
                'Alumno 3',
                'Alumno 4',
                'Alumno 5',
                'Alumno 6',
                'Alumno 7',
                ].map((element)=>{
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
