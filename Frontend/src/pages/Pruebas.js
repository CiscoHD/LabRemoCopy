import React, { useContext } from 'react'

import { RosContext } from '../context/RosContext'
import { Col, Container, Row } from 'react-bootstrap';
import UploaderFile from '../components/UploaderFile';


export default function Pruebas() {

  // const ros = useContext(RosContext);
  const a = ['Android','Zybo','ESP32','FPGA']
  const ext = {
    'Android': '.hex',
    'Zybo': '.v',
    'ESP32':'.bin',
    'FPGA':'.vhdl' 
  }

  const handlerUploadClick = (i) => {
    console.log(i)
  }


  return (
    <div>
      <Container style={
        {
          display: 'flex',
          justifyContent: 'center',
          fontSize: 24,
          // color: 'red',
        }
      }>
        <Row>
       Pagina para pruebas
       <Row>
        {a.map((i) =>{
          return(
            <UploaderFile title={i} board={i} ext={ext[i]}/>
            // <Row className='justify-content-md-center'>
            // <Col>{i}
            // <Row className='justify-content-md-center'>Selecciona un archivo para subir
            // <form id='uploadFile' role='form'>
            //   <input type='file' id={`file-${i.toLowerCase()}`} name={`file-${i.toLowerCase()}`} accept={`${ext[i].toLowerCase()}`} />
            //   <button id={`file-${i.toLowerCase()}`} onClick={handlerUploadClick}>Upload {i}({ext[i]}) file</button>
            // </form>
            // </Row>
            // </Col>
            // </Row>
          )
        })}
       </Row>



       <Row>
       </Row>
       </Row>
       </Container>
    </div>
  )
}
