import React from 'react'
import { Box, Typography} from '@mui/material'
import Form from 'react-bootstrap/Form';

export default function Selection({label, url}) {
  return (
    <Box sx={{
        paddingTop: '4%',
        width: '50%',
        margin: 'auto',
        borderBottom: 'groove',
        justifyContent: 'center',
    }}>
      <Typography variant='h6'>{label}</Typography>
      <Form.Select className='innerCol secondary-text' 
        aria-label="Default select example"
        sx={{
          margin: 'auto',
          width: '40%',
        }}
        >
        <option value='notSelected' >Open this select menu</option>
        </Form.Select>
    </Box>
  )
}
