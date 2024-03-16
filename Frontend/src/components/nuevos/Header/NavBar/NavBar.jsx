import './navbar.css'
import React, { useEffect, useRef, useState } from 'react'
import { useStateValue } from '../../../../context/StateContext'

import MenuItem from './MenuItem'

import logoUNAM from '../../../../media/LogoUNAM.png'
import logoIIMAS from '../../../../media/LogoIIMAS_Color.png'
import logoLABREMO from '../../../../media/labremo.png'

export default function NavBar() {
  const [{user},dispatch] = useStateValue();
  const [sticky, setSticky]=useState(false)
  const [navHeight, setNavHeight] = useState(0);

  const navbar = useRef();

  const navMenu = [
    {
      'label':'Inicio',
      'url': ''
    },
    {
      'label':'Laboratorio',
      'url': 'selection'
    },
    /* {
      'label':'mesa de trabajo',
      'url': 'workspace'
    }, */
    {
      'label':'Nosotros',
      'url': 'team'
    },
    {
      'label':'Contacto',
      'url': 'contact'
    },
  ]

  useEffect(()=>{
    window.addEventListener('scroll',stickNavbar)

    return () => {
      window.removeEventListener('scroll',stickNavbar)
    };
  },[]);

  const stickNavbar = () =>{
    if(window != undefined){
      let windowHeight = window.scrollY;
      setNavHeight(navbar.current.clientHeight);
      console.log(windowHeight)
      //windowHeight > 500 ? setSticky('fixed top-0 left-0 z-50'): setSticky('relative');
      windowHeight > 5 ? setSticky(true): setSticky(false);
    };
  }

  return (
    <React.Fragment>
    <div ref={navbar} className={`navbar ${sticky&&' sticky'}`}>
      <div className='logos-cont'>
      <img className='logos' src={logoUNAM} alt="" />
      <img className='logos' src={logoIIMAS} alt="" />
      {/* <img className='logos' src={logoLABREMO} alt="" /> */}
      </div>
      <div className='navmenu'>
        {navMenu.map((item)=>{
          return(
          <MenuItem action={item.url}>{item.label}</MenuItem>
          );
        })}
        <div className={!user.token?'drop item-menu':'item-menu'}>
          <div className='dropcontent'>
          <div className='dropmenu-item'>Perfil</div>
          <div className='dropmenu-item'>Cerrar Sesión</div>
          </div>
          {user.token?`${user.username}`:'Login'}
          <span></span>
          </div>
      </div>
    </div>
    <div style={sticky ? ({ marginTop: navHeight }) : ({})}></div>
    </React.Fragment>
  )
}