import React, { useState } from 'react'
import { useHistory } from 'react-router-dom/cjs/react-router-dom';
import './tipotarjeta.css'

import { Box, Typography } from '@mui/material'
import { Button, Form } from 'react-bootstrap';
import SelectTarjeta from './SelectTarjeta';
import BoardInfo from './BoardInfo';


import Arduino from '../../media/Workbench/Arduino.png'
import ESP8226 from '../../media/Workbench/Arduino.png'
import ZYBO from '../../media/Workbench/Arduino.png'
import TypeBoard from '../nuevos/SelectTypeBoard/TypeBoard';

export default function TipoTarjeta({}) {
  const [board,setBoard]=useState(null);
  const [loadFileModal, setLoadFileModal]=useState(false);

  const history = useHistory();

  const handleBoard = (v) =>{
    setBoard(v);
    console.log(board)
  }

  const ShowBoard = ({}) => {
    switch(board){
      case 'board-ESP8226':
        return(
          <BoardInfo label={'ESP8226'} url={ESP8226}/>
        )
        case 'board-ZYBO':
        return(
          <BoardInfo label={'ZYBO'} url={ZYBO}/>
        )
        case 'board-Arduino':
        return(
          <BoardInfo label={'Arduino'} url={Arduino}/>
        )
      default:
        return(
          <></>
        );
    }
  }

  const SwitchBoard = ({}) => {
    switch(board){
      case 'esp8226':
        return(  
          setBoard('esp8226')
        )
        case 'zybo':
        return(
          setBoard('zybo')
        )
        case 'arduino':
        return(
          setBoard('arduino')
        )
      default:
        return(
          console.log(board)
        );
    }
  }

  return (
    <div>
      <div className='select-board-panel'>
        <div className='title-board-panel'>
          Seleccione la tarjeta con la que se trabajará.
        </div>

      </div>
      <div className="double-spacing"></div>
    
    <TypeBoard setBoard={setBoard} boardactive={board}/>

    <div className="boton-actsel-guardar" onClick={()=>{
      console.log(board);
      history.push('/workspace')
      }}>Continuar</div>

    {/*
    <Form>
    <div key={`select-${'board'}`}>
      <SelectTarjeta label={'ESP8226'} handler={handleBoard}/>
      {board=='board-ESP8226'?<ShowBoard />:<></>}
      <SelectTarjeta label={'ZYBO'} handler={handleBoard} />
      {board=='board-ZYBO'?<ShowBoard />:<></>}
      <SelectTarjeta label={'Arduino'} handler={handleBoard} />
      {board=='board-Arduino'?<ShowBoard />:<></>}
    </div>
     
    </Form>
      
    <Button onClick={() => {board?setLoadFileModal(true):window.alert('Selecciona una tarjeta!!')}} >Aceptar</Button>

    {loadFileModal && 
    <div style={{
      position: 'fixed',
      top: 0,
      left: 0,
      width: '100%',
      height: '100%',
      background: 'rgba(0,0,0,0.5)',
      display: 'block'
    }}>
      <div style={{
        position: 'absolute',
        top: '50%',
        left: '50%',
        width: '60%',

        transform: 'translate(-50%,-50%)',
        background: '#FFFFFF',
        padding: '40px',
        boxShadow: '0px 0px 10px rgba(0,0,0,0.5)',
        borderRadius: '10px',
      }}>
      <div>
        <h5>Cargar archivo</h5>
      </div>
      <div style={{
        width: '80%',
        margin: 'auto',
      }}>
      <Form.Group controlId="formFile" className="mb-3">
        <Form.Label>Cargar archivo</Form.Label>
        <Form.Control type="file" />
      </Form.Group>
      <Button>Cargar</Button>
      <Button variant='secondary'
      onClick={() => setLoadFileModal(false)}
      >Cancelar</Button>
      </div>
    </div>
    
    </div>}

    */}
    

  </div>
  )
}
