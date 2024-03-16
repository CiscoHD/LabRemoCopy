import React from "react";
import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar'
import {Container} from 'react-bootstrap';


function ContNavBar() {
    return (
      <div className='contnav'>
      <Navbar bg='primary' variant='dark'>
        <Container> 
          <Navbar.Brand>Laboratorio Remoto</Navbar.Brand>
          <Navbar className=''>
            <Nav.Link href="#home">Home </Nav.Link>
            <Nav.Link href="#link">Link</Nav.Link>
          </Navbar>
        </Container>
      </Navbar>
      </div>
    )
}

export default ContNavBar