import './App.css';
import React from 'react';
import { useState } from 'react';
import { Switch,Route,Link } from 'react-router-dom';

import {Container} from 'react-bootstrap';
import Row from 'react-bootstrap/Row';
import Col from 'react-bootstrap/Col';

import ContNavBar from './components/ContNavBar';
import ContTitle from './components/ContTitle';

import PorMatetPract from './components/PorMatetPract';
import TitleCol from './components/TitleCol';

import ListGroup from 'react-bootstrap/ListGroup';
import ListGroupItem from 'react-bootstrap/ListGroupItem';
import SubTitleCol from './components/SubTitleCol';
import Activities from './components/Activities';
import Button from 'react-bootstrap/Button';


function App() {

  const [subject, setSubject] = useState('notSelected');

  const handlerSubject = (val) => {
    setSubject(val);
  }

  return (
  <div className="App">
    <ContNavBar />
    <p></p>
    <ContTitle className="contenedor"/>

    <Container className='columns' fluid="md">
      <Row>
        <PorMatetPract handler={handlerSubject}/>
        
        <Activities subject={subject}/>


        <Col className='columna'>
          <Container>
            <Row>
              <Col>
                <TitleCol>Contenido</TitleCol>
              </Col>

            </Row>

          </Container>
          <SubTitleCol>Titulo de la practica</SubTitleCol>
          <h6 className='secondary-text'>Este es un resumen del contenido de la practica... "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."</h6>
          <div className="d-flex justify-content-center">
          <Button variant="success">Ver </Button>{' '}
          <Button variant="warning">Editar</Button>{' '}
          <Button variant="danger">Eliminar</Button>{' '}
          </div>
          
        </Col>
      </Row>
      
    </Container>

    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>
    <p/>
    <p>.</p>

  </div>
  );
}

export default App;