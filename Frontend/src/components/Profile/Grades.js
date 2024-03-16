import React from 'react'

import { Button, Typography } from '@mui/material'

export default function Grades() {
    return (
        <div>
            <Typography variant='h6'>Lista de Prácticas</Typography>
            <ul>
                {['Práctica 1',
                'Práctica 2',
                'Práctica 3',
                'Práctica 4',
                'Práctica 5',
                'Práctica 6',
                'Práctica 7',
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
