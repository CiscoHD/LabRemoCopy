import React from 'react';
import { useEffect,useState, useContext } from 'react';
import Form from 'react-bootstrap/Form';
import { FirstContext } from '../context/FirstProvider';


export default function Selector({url_api,disabled,handler,filter}) {

  const [universities, setUniversities] = useState([]);
  const {university,school,career, enableSchool,enableCareer} = useContext(FirstContext)

  useEffect(() => {
      async function fetchData(){
          const data = await fetch(url_api);   
          const value  = await data.json();
          setUniversities(value);
          //console.log(universities);
      }
      fetchData();
  },[universities.length]);


  return (
    <Form.Select className='innerCol secondary-text' 
    aria-label="Default select example"
    disabled={disabled}
    onChange={(e) => {
      //console.log(e.target.value);
      //console.log(e.target.value);
      if(e.target.value == 'notSelected'){
        handler(true,e.target.value);
      }
      else{
        handler(false,e.target.value);
      }

      //console.log(Valor);
    }}>
    <option value='notSelected'>Open this select menu</option>
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
                //console.log('notCareer',filter);
              }
              else{
                if(x.career == filter || x.career == null){
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
