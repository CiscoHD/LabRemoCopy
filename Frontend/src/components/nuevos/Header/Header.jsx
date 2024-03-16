import React from 'react'
import NavBar from './NavBar/NavBar'
import TopBar from './TopBar/TopBar'

export default function Header() {
  return (
    <div>
    <TopBar className='topbar' />
    <NavBar  />
    </div>
  )
}
