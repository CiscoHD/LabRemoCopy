import "../components/ActivitySelection/style.css";
/* import '../components/nuevos/ActivitySelection/styles.css' */
import './activityselection.css'

import React, { useState } from 'react';
import ContNavBar from '../components/ContNavBar';
import { Link } from 'react-router-dom/cjs/react-router-dom.min';

//import { useStateValue } from '../context/StateContext';
import { useStateValue } from '../context/StateContext';


import { Tab, Tabs, TabList, TabPanel } from 'react-tabs';

import PorMatetPract from '../components/nuevos/ActivitySelection/PorMatetPract'
import Practicas from "../components/ActivitySelection/Practicas";
import TipoTarjeta from "../components/ActivitySelection/TipoTarjeta";
import ModuloVista from "../components/ActivitySelection/ModuloVista";
import { Box } from "@mui/material";
import { FileX, Triangle } from "react-bootstrap-icons";
import Protector from "./Protector";
//import 'react-tabs/style/react-tabs.css';


export default function ActivitySelection() {

  const [{university}, dispatch] = useStateValue()
  console.log(university);

  const [active,setActive]=useState(0);
  const [isSaving,setIsSaving]=useState(false);

  
  const Flag = ({size,gap,color}) => {
    return(
      <div className="svg-container">
        <svg viewBox={`0 0 ${size} ${size}`} width="100%" height={size} >
          <rect width={(size-gap)/2.} height={(size-gap)/2.} fill={color?color[0]?color[0]:'black':'black'} />
          <rect width={(size-gap)/2.} height={(size-gap)/2.} fill={color?color[1]?color[1]:'black':'black'} x={size-(size-gap)/2.} />
          <rect width={(size-gap)/2.} height={(size-gap)/2.} fill={color?color[2]?color[2]:'black':'black'} y={size-(size-gap)/2.} />
          <rect width={(size-gap)/2.} height={(size-gap)/2.} fill={color?color[3]?color[3]:'black':'black'} x={size-(size-gap)/2.} y={size-(size-gap)/2.} />
      </svg>
    </div>
    )
  };

  return (
    <Protector>
      <div className="activity-selection-container"> 

      <div className="seleccione">Seleccione: </div>
      <div className="tab-container">

        <div className="menutab">
            {['Tipo de Tarjeta','Módulo de vista','Practicas'].map((item,index)=>{
              
              const size = 40;
              const gap = 2;

              const color = null; /* ['pink','violet','green','red']; */
              const arreglo = {
                0: 'Por tarjeta de trabajo',
                1: 'Por sesión almacenada',
                2: 'Por plantilla de práctica',
              }

              return(
                <div className={`tab-item${(active==index)?' tab-active':''}`} onClick={()=>{setActive(index)}}>
                  {/* <Flag size={size} gap={gap} color={color} /> */}
                  {arreglo[index]}
                </div>
              )
            })}

        </div>
      </div>

      <div className="tab-content-container">
      {(active==2)
      ?<>
      <Box className={'panel-container'} >
        <PorMatetPract />

      </Box>
      <div className="boton-actsel-guardar" onClick={()=>{
        setIsSaving(true);
        setTimeout(()=>{setIsSaving(false)},3000);
        }}>{'Guardar'}</div>
        </>

      :(active==0)
        ?<TipoTarjeta />
        :(active==1)
          ?<ModuloVista />
          :'Default tab'
      }
      
      </div>

      {isSaving&&<div className="saving-action-modal">
        <div>Los datos se han guardado correctamente.</div>
      </div>}


{/*       <Tabs>
      <TabList className='tab-list'>
        <Tab className='tab'>Prácticas</Tab>
        <Tab className='tab'>Tipo de Tarjeta</Tab>
        <Tab className='tab'>Módulo de vista</Tab>
      </TabList>
      <div className="selector-container"></div>

      <TabPanel>
        <Box className={'panel-container'} >
        <PorMatetPract />

        </Box>
        {/*<Practicas />*/}
      {/* </TabPanel>
      <TabPanel>
        <TipoTarjeta />
      </TabPanel>
      <TabPanel>
        <ModuloVista />
      </TabPanel>
    </Tabs> */} 

    

      <Link to='/'>Volver</Link>
      </div>
    </Protector>
  )
}