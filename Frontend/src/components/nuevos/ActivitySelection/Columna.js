import React from 'react';
import Col from 'react-bootstrap/Col';

export default function Columna({children}) {
  return (
    <Col className='columna'>
        {children}
    </Col>
  )
}