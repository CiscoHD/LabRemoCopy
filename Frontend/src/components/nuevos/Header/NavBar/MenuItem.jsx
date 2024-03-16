import React from 'react'
import { Link } from 'react-router-dom/cjs/react-router-dom.min';

import { useHistory } from "react-router-dom/cjs/react-router-dom.min";

export default function MenuItem({children,classes,action}) {

    const history = useHistory();
  return (
        <Link to={'/'+action} className={'item-menu'}>
        {children}
        <span></span>
        </Link>
        
  )
}
