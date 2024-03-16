import React from 'react'
import { Button, Form } from 'react-bootstrap';

export default function SelectTarjeta({label,grupo,board,handler}) {
  return (
    <Form.Check
    reverse
    onClick={(e) =>{
      handler(e.target.id);
    }}
    label={label}
    name={grupo?grupo:"group1"}
    type={'radio'}
    id={`board-${board?board:label}`}
    style={{
      width: '150px',
      margin: 'auto',
    }}
  />
  )
}
