import React from "react";
import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar'
import {Container} from 'react-bootstrap';
import { BrowserRouter, Route, Switch } from "react-router-dom/cjs/react-router-dom.min";
import { LinkContainer } from "react-router-bootstrap";


function ContNavBar() {
    return (
      <div className='contnav'>
      <BrowserRouter>
        <Navbar bg='primary' variant='dark'>
          <Container> 
            <Navbar.Brand>Laboratorio Remoto</Navbar.Brand>
            <Navbar>
              <LinkContainer to="/">
                <Nav.Link>Home </Nav.Link>
              </LinkContainer>
                <Nav.Link>Link</Nav.Link>
              <LinkContainer to="/RosTest">
                <Nav.Link>RosTest</Nav.Link>
              </LinkContainer>
            </Navbar>
          </Container>
        </Navbar>
      </BrowserRouter>
      </div>
    )
}

export default ContNavBar