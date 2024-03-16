import React from 'react';
import { useEffect,useState, useContext } from 'react';
import axios from 'axios';
import Form from 'react-bootstrap/Form';
import { useStateValue } from '../../../context/StateContext';
import { actionTypes } from '../../reducer';


export default function Selector({url_api,disabled,filter,actionType,value}) {

  const [{}, dispatch] = useStateValue();

  const [universities, setUniversities] = useState([]);

  /*useEffect(() => {
      async function fetchData(){
          const data = await fetch(url_api);   
          const value  = await data.json();
          setUniversities(value);
          //console.log(universities);
      }
      fetchData();
  },[universities.length]);*/

  useEffect(() => {
      async function fetchData(){
          const response = await axios(url_api)
          console.log(response.data);
          const value = response.data;
          setUniversities(value);
          //console.log(universities);
      }
      fetchData();
  },[universities.length]);

  return (
    <Form.Select className='innerCol secondary-text' 
    aria-label="Default select example"
    disabled={disabled}
    value={value}
    onChange={(e) => {
      if(e.target.value == 'notSelected'){
        if(actionType != actionTypes.SET_UNIV){
          if(actionType != actionTypes.SET_SCHOOL){
            dispatch({
              type: actionType,
              v: e.target.value,
            })
          }
          dispatch({
            type: actionTypes.SET_CAREER,
            v: e.target.value,
          })
          dispatch({
            type: actionType,
            v: e.target.value,
          })
        }
        dispatch({
          type: actionTypes.SET_CAREER,
          v: e.target.value,
        })
        dispatch({
          type: actionTypes.SET_SCHOOL,
          v: e.target.value,
        })
        dispatch({
          type: actionType,
          v: e.target.value,
        })
      }
      else{
        dispatch({
          type: actionType,
          v: e.target.value
        })
      }
      //console.log(Valor);
    }}>
    <option value='notSelected' >Open this select menu</option>
    {universities.map((x) => {
      if(x.isAvailable==1){
        if(filter == undefined){
          return(
            <option value={x.id}>{x.name}</option>
          );
        }
        else{
          //console.log("Filter:",filter,x)
          if(x.university==undefined){
            //console.log('notUniv',x);
            if(x.schools == undefined){
              //console.log('notSchool',filter);
              if(x.career == undefined){
                //console.log('notCareer',filter,x.career);
                ///////////////////////////////////////////
                // ESTA PARTE ES PARA PODER VER ALGO CUANDO LOS
                // ID DE CARRERA DE LAS MATERIAS ES NULL
                ///////////////////////////////////////////
                return(
                  <option value={x.id}>{x.name}</option>
                );
              }
              else{
                if(x.career == filter){
                  return(
                    <option value={x.id}>{x.name}</option>
                  );
                }
              }
            }
            else{
              //console.log('lalalalafilter',filter)
              if(x.schools==filter){
                return(
                  <option value={x.id}>{x.name}</option>
                );
              }
          }
          }
          else{
            if(x.university == filter){
              return(
                <option value={x.id}>{x.name}</option>
              );
            }
          }
        }
        
      }
    })
    }
  </Form.Select>
  )
}
