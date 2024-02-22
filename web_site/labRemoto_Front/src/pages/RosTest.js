import "./RosTest.css"
import React, { useEffect, useContext} from "react";
import ContNavBar from '../components/ContNavBar';
import {Container, Row, Col, Button, Alert} from 'react-bootstrap';
import { rosContext } from "../context/rosContext";

function RosTest() {
  const ros = useContext(rosContext);

  /**
   * Path del archivo .hex y el puerto 
   * Se deben obtener a partir de una petición a la base de datos
   * con la dirección en donde se guardó en el servidor.
   */
  const hex_path = "/media/abrahamrh/Universidad/Servicio_social/Web-test/arduino_test.ino.hex";
  const port = "/dev/ttyUSB0";

  const handleOnClick = () => {
    ros.pubMessage();
  }

  return (
    <>
    <ContNavBar />
    <Container >
      <Row className="title justify-content-md-center">
        <h3>Prueba de conexión con ROS</h3>
      </Row>
      <Row>
        <p>
          La prueba consiste en mandar un archivo .hex a la placa de arduino, el cual contiene un programa que hace que el led de la placa parpadee.
        </p>
      </Row>
      <Row className="justify-content-md-center">
        { ros.isConnected === false &&
          <Col xs lg="2">
          <Alert variant="secondary">
            Sin conexión.
          </Alert>
          </Col>
        }
        {
          ros.isConnected === true &&
          <Col xs lg="2">
          <Alert variant="success">
            Conexión activa.
          </Alert>
          </Col>
        }
      </Row>
      <Row>
        <Button onClick={handleOnClick}>
          Enviar programa a arduino
        </Button>
      </Row>
    </Container>
    </>
  );
}

export default RosTest;