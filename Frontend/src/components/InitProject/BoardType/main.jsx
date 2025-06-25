import styles from "./index.module.css";

import Info from "@/utils/Modal/Info";

import Arduino from "@/assets/media/Nodes/Programables/ARDUINO_NANO33.png";
import ESP8226 from "@/assets/media/Nodes/Programables/ESP32.png";
import ZYBO from "@/assets/media/Nodes/Programables/ZEDBOARD2.png";
import RaspberryPi5 from "@/assets/media/Nodes/Programables/RASPBERRYPI5_2.png"

import TypeBoardInfo from "./TypeBoardInfo";

const loadFileModal = () => {
  /*
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
    
  <Button onClick={() => { board ? setLoadFileModal(true) : window.alert('Selecciona una tarjeta!!')}} >Aceptar</Button>

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
  
  */
};

export const ShowBoardInfo = ({ board }) => {
  switch (board.toUpperCase()) {
    case "ESP32":
      return <Info label={"Esp326"} url={ESP8226} />;
    case "ZEDBOARD":
      return <Info label={"Zedboard"} url={ZYBO} />;
    case "ARDUINO":
      return <Info label={"Arduino"} url={Arduino} />;
    case "RASPBERRYPI5":
      return <Info label={"RaspberryPi5"} url={RaspberryPi5} />;
    default:
      return <></>;
  }
};

export default function TipoTarjeta() {
  return (
    <>
      <div className={styles.panel_title}>
        Seleccione la tarjeta con la que se trabajará.
      </div>

      <div className={styles.main}>
        <TypeBoardInfo />
      </div>
    </>
  );
}
