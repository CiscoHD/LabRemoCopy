import './styles.css'
import React, { useState, useContext } from 'react';

import Columna from './Columna';
import TitleCol from './TitleCol';
import SubTitleCol from './SubTitleCol';
import Selector from './Selector';
import { useStateValue } from '../../../context/StateContext';
import { actionTypes } from '../../reducer';


export default function PorMatetPract({handler}) {

    const [{university,
        school,
        career,
        subject,
        practica,
        base_url,
    },dispatch] = useStateValue();

    //console.log(university,school,career,base_url);


  return (
    <Columna>
            <TitleCol>Por materia y práctica.</TitleCol>       
            <SubTitleCol>Institución</SubTitleCol>
                <Selector url_api={base_url+'catUniversities/'} actionType={actionTypes.SET_UNIV} value={university} />
                <div className={'spacing'} />
            <SubTitleCol>Facultad o Escuela</SubTitleCol>
                <Selector url_api={base_url+'catSchools/'} disabled={university!='notSelected'?false:true} value={school} actionType={actionTypes.SET_SCHOOL} filter={university}/>
                <div className={'spacing'} />
            <SubTitleCol>Carrera</SubTitleCol>
                <Selector url_api={base_url+'catCareers/'} disabled={school!='notSelected'?false:true} value={career} actionType={actionTypes.SET_CAREER} filter={school}/>
                <div className={'spacing'} />
            <SubTitleCol>Materia</SubTitleCol>
                <Selector url_api={base_url+'catSubjects/'} disabled={career!='notSelected'?false:true} value={subject} actionType={actionTypes.SET_SUBJECT} filter={career} />
                <div className={'spacing'} />
            <SubTitleCol>Práctica</SubTitleCol>
                <Selector url_api={base_url+'activity/'} disabled={subject!='notSelected'?false:true} value={practica} actionType={actionTypes.SET_PRACTICA} filter={subject}/>
                <div className={'double-spacing'} />
                

  </Columna>
  )
}
