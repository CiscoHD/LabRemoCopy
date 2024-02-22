import React, { useState, useContext } from 'react';

import Columna from './Columna';
import TitleCol from './TitleCol';
import SubTitleCol from './SubTitleCol';
import Selector from './Selector';
import FirstProvider from '../context/FirstProvider';



const base_url = 'http://192.168.200.41:8000/api/'


export default function PorMatetPract({handler}) {

    const [Schenable,setSchenable] = useState(true);
    const [Carenable,setCarenable] = useState(true);
    const [Subenable,setSubenable] = useState(true);
    const [univ,setUniv] = useState('notSelected');
    const [school,setSchool] = useState('notSelected');
    const [career,setCareer] = useState('notSelected');
    const [subject, setSubject] = useState('notSelected');
    const [activity, setActivity] = useState('notSelected');


    const handleSchool = (v,v2) => {
        setSchenable(v);
        setUniv(v2);
        setSchool('notSelected');
        setSubject('notSelected');
    }
    const handleCareer = (v,v2) => {
        setCarenable(v);
        //setCareer(v2);
        setSchool(v2);
        setSubject('notSelected');

    }
    const handleSubject = (v,v2) =>{
        setSubenable(v);
        setCareer(v2);
    }
    const handleSelectSubject = (v,v2) => {
        //setSubenable(v);
        setSubject(v2);
        handler(v2);
    }

  return (
    <Columna>
        <FirstProvider>
            <TitleCol>Por materia y práctica.</TitleCol>       
            <SubTitleCol>Institución</SubTitleCol>
                <Selector url_api={base_url+'catUniversities/'} handler={handleSchool} />
            <SubTitleCol>Facultad o Escuela</SubTitleCol>
                <Selector url_api={base_url+'catSchools/'} disabled={Schenable} handler={handleCareer} filter={univ}/>
            <SubTitleCol>Carrera</SubTitleCol>
                <Selector url_api={base_url+'catCareers/'} disabled={Carenable} handler={handleSubject} filter={school}/>
            <SubTitleCol>Materia</SubTitleCol>
                <Selector url_api={base_url+'catSubjects/'} disabled={Subenable} handler={handleSelectSubject} />
        </FirstProvider>
  </Columna>
  )
}
