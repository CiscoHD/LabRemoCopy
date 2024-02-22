import React from 'react';
import { useState, useEffect } from 'react';
import Col from 'react-bootstrap/Col';
import TitleCol from './TitleCol';
import ListGroup from 'react-bootstrap/ListGroup';
import ListGroupItem from 'react-bootstrap/ListGroupItem';
import SubTitleCol from './SubTitleCol';


export default function Activities({subject}) {

    const base_url = 'http://192.168.200.41:8000/api/'
    const url_api = base_url +'activity/'

    const [activities,setActivities] = useState([]);
    const [subjects,setSubjects] = useState([]);
  
    useEffect(() => {
        async function fetchData(){
            const data = await fetch(url_api);   
            const value  = await data.json();
            setActivities(value);
            console.log(activities);
        }
        fetchData();
    },[activities.length]);

    useEffect(() => {
        async function fetchData(){
            const data = await fetch(base_url+'catSubjects/');   
            const value  = await data.json();
            setSubjects(value);
            console.log(subjects);
        }
        fetchData();
    },[subjects.length]);


  return (
    <Col className='columna'>
        <TitleCol>Prácticas</TitleCol>
        <SubTitleCol>Asignatura: {subject!='notSelected' ? ' '+subjects[subject]['name'] : ' desconocida'}</SubTitleCol>
        {
            <ListGroup>
                {
                    activities.map((activity) =>{
                        if(activity.isAvailable == 1){
                            if(activity.subject == subject){
                                return (
                                    <ListGroupItem href={'#'+activity.id} className='secondary-text'>{activity.name}</ListGroupItem>
                                );
                            }
                        }
                    } )
                }
            </ListGroup>
        }
  </Col>
  )
}
