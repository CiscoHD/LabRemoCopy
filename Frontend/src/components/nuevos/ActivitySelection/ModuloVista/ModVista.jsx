import React from 'react'
import './modulovista.css'
 import { Trash, PencilSquare, Share } from 'react-bootstrap-icons'



export default function ModVista() {

    const Action = ({action,actionICon}) => {
        return(
            <div className="action" onClick={()=>[console.log(`im busy doing an action #${1+action}`)]}>{actionICon}</div>
        )
    }

    const Actions = () => {
        return(
            <div className="actions">
                {[<Trash />,<PencilSquare />,<Share />].map((item,i) => {
                    return(
                        <Action action={i} actionICon={item} />
                    )
                })}
                </div>
        );
    }

    const Row = ({datarow,number}) => {
        return(
        <tr>
            <td>{datarow?datarow.name:`Nombre de Practica #${number}`}</td>
            <td>{datarow?datarow.subject:`Asignatura #${number}`}</td>
            <td onClick={()=>{
                console.log(`going to Activity #${number}`)
            }}>{datarow?datarow.lastdatemod:`DD/MM/AAAA:HH:MM:SS`}</td>
            <td>{datarow?datarow.actions:<Actions />}</td>
        </tr>
        );
    }


  return (
    <div className={'vista-container'}>
        <div className="vista-title">
            Contenido de practicas
        </div>
        <div className="spacing"></div>
        <div className="vista-content">
            <table>
                <thead>
                    <tr>
                        <th>Nombre</th>
                        <th>Asignatura</th>
                        <th>Ultima modificacion</th>
                        <th>Acciones</th>
                    </tr>
                </thead>
                <tbody>
                {[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,1,2,3,4,5,6,7,8,9,10,11,12,13,14].map((i) => {
                    return(
                        <Row number={i}/>
                    );
                })}
                </tbody>
                

            </table>
            <div className="spacing"></div>
        </div>
    </div>
  )
}