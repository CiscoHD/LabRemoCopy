import axios from "axios";
import { useState, useContext } from "react";
import { Row, Col, Container, Button } from "react-bootstrap";

import { useStateValue } from "../context/StateContext";
import { RosContext } from "../context/RosContext";
import { MenuContext } from "../context/MenuContext";

export default function UploaderFile({ title, board, ext }) {
  const [{ base_url }] = useStateValue();

  const [file, setFile] = useState(null);

  const ros = useContext(RosContext);
  const mnCntx = useContext(MenuContext);
  // const [ros,setRos] = useState(false);
  const [isFileLoaded, setIsFileLoaded] = useState(false);

  const handleConect = () => {
    // console.log("Received message on " + listener.name + ": " + message.file);
    // listener.unsubscribe();
  };

  const handleProgram = () => {
    console.log(ros);
    ros.pubMessage();
  };

  const handlerChangeFile = (e) => {
    if (e.target.files) {
      setFile(e.target.files[0]);
    }
    // console.log(file)
  };

  const handlerClick = async () => {
    const user_data = [1, 1, 1];

    if (file) {
      console.log("Uploading file...", file.name);

      const formData = new FormData();

      formData.append("file", file);
      formData.append("id_estudiante", user_data[0]);
      formData.append("id_practica", user_data[1]);
      formData.append("id_session", user_data[2]);

      try {
        const result = await axios
          .post(`${base_url}upload2`, formData, {
            headers: {
              "Content-Type": "multipart/form-data",
            },
          })
          .then(function(response) {
            console.log("Sucess!!", response);
            setIsFileLoaded(true);
          })
          .catch(function(error) {
            // console.log(formData);
            console.log("Failure! :(", error.response.data);
            setIsFileLoaded(true);
          });

        const data = await result.json();

        console.log("result", result);
      } catch (error) {
        console.log(error);
      }
    }
    return;
  };

  return (
    <Container
      style={{
        display: "flex",
        width: "70%",
        margin: "auto",
        borderRadius: "5px",
        boxShadow: "0px 0px 10px blue",
        background: "white",
      }}
    >
      <Row className="justify-content-md-center">
        <Col>
          <h2> {board}</h2>
        </Col>
        <Row className="justify-content-md-center">
          <label htmlFor="loadFile"> Selecciona un archivo para subir</label>
        </Row>
        <Col>
          <form id={`uploadFile-${board}`} role="form">
            <Row>
              <Row
                style={{
                  margin: "10px",
                }}
              >
                <input
                  type="file"
                  id={`loadFile`}
                  name={`file-${title.toLowerCase()}`}
                  accept={`${ext.toLowerCase()}`}
                  onChange={handlerChangeFile}
                  style={{
                    display: "flex",
                    justifyContent: "center",
                    marginInline: "auto",
                    width: "auto",
                  }}
                />
              </Row>
              <Row
                style={{
                  display: "flex",
                  justifyContent: "center",
                }}
              >
                <Button
                  id={`file-${title.toLowerCase()}`}
                  onClick={handlerClick}
                  style={{
                    width: "auto",
                  }}
                >
                  Upload {title}(*{ext}) file.
                </Button>
              </Row>
              <Row>
                <Col>
                  <Button
                    id={`file-${title.toLowerCase()}`}
                    onClick={handleProgram}
                    style={{
                      width: "auto",
                      // backgroundColor: ros?'gray':'',
                    }}
                  >
                    {ros.IsConnected ? "Conectar" : "Desconectar"}
                  </Button>
                </Col>
                <Col>
                  {[
                    "Cargar",
                    // 'Transformar','CargaBit'
                  ].map((itm) => {
                    // const cargador = 'Carga'==itm?ros.CargaHexpubMessage:'Transformar'==itm?ros.TransformBitTopicpubMessage:ros.CargaBitTopicpubMessage;
                    return (
                      <Button
                        id={`file-${title.toLowerCase()}`}
                        // onClick={handleProgram}
                        onClick={() => {
                          if (itm == "Cargar") {
                            mnCntx.setLoading(false);
                            // ros.CargaHexpubMessage();
                            // ros.setConsoleLog([...ros.consoleLog,
                            //     {lstnr: 'Listener #1',
                            //     mssg: `Cargando archivo Bitstream`}
                            // ])
                            // ros.setConsoleLog([...ros.consoleLog,
                            //     {lstnr: 'Listener #1',
                            //     mssg: `Bitstream cargado en la tarjeta de trabajo`},
                            //     {lstnr: 'Listener #1',
                            //     mssg: `Matriz de interconexión lista.`}
                            // ]);
                          } else {
                            if ((itm = "Transformar")) {
                              ros.TransformBitTopicpubMessage();
                            } else {
                              ros.CargaBitTopicpubMessage();
                            }
                          }
                        }}
                        style={{
                          width: "auto",
                          // backgroundColor: ros?'gray':'',
                        }}
                      // disabled={(isFileLoaded)}
                      >
                        {itm}
                      </Button>
                    );
                  })}
                </Col>
              </Row>
            </Row>
          </form>
        </Col>
      </Row>
    </Container>
  );
}
