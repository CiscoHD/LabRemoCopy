import './topBar.css'
import React from 'react'
import { Facebook, Instagram, Link, Twitter } from 'react-bootstrap-icons'
import Icons from './Icons'



export default function TopBar({className}) {
  return (
    <div className={className} hidden={true}>
        <div className='social-networks'>
          <Icons className='icon' Icon={Facebook} url={'/#'} />
          <Icons className='icon' Icon={Instagram} url={'/#'} />
          <Icons className='icon' Icon={Twitter} url={'/#'} />
        </div>
    </div>
  )
}
