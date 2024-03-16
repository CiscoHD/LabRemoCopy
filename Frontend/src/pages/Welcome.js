import React from 'react'
import { Facebook, Instagram, Twitter } from 'react-bootstrap-icons'

import { Link } from 'react-router-dom/cjs/react-router-dom.min';

import { useHistory } from "react-router-dom/cjs/react-router-dom.min";

import Icons from '../components/nuevos/Header/TopBar/Icons'


import '../components/nuevos/Welcome/welcome.css'

import Protector from './Protector'

export default function Welcome() {
    
    const history = useHistory();




  return (
    <Protector>
    <div className="welcome-page-container">
        <div className="welcome-firstline">
            Laboratorio
            <div className="welcome-secondline">
            Remoto
            <div className='icons-welcome-container'>
            {[Facebook,Instagram,Twitter].map((item,index)=>{
                const dic = {
                    0:'facebook',
                    1:'instagram',
                    2:'twitter',
                }
                return(
                    <Icons className={`welcome-page-icon${item?' '+dic[index]:''}`} Icon={item} url={'/#'} />
                );
            })}
            </div>
            </div>
        </div>
    </div>
    <div className='links-container' 
    >
        {
            ['Acceso a Laboratorio Remoto',
            'Guía de Usuario',
            'Registrarse',
            'Aula Virtual',
            ].map((itm,i)=>{
                const dict = {
                    0: ()=>{history.push('/selection')},
                    1: ()=>{window.location.replace('/descarga.pdf')},
                    2: ()=>{window.location.href="mailto:victor@aries.iimas.unam.mx";},
                    3: ()=>{window.location.replace('/moodle')}
                }
                return(
                <div
                className='element-links-cont'
                onClick={dict[i]}
                >{itm}</div>)
            })
        }

    </div>
    </Protector>
  )
}
