import React from 'react'

import { useStateValue } from '../context/StateContext'

import { useHistory } from "react-router-dom/cjs/react-router-dom.min";
;

export default function Protector({children}) {
    const [{base_url,user},dispatch] = useStateValue();
    const history = useHistory();
    console.log(user.token)

  return (
    <>
        {!user.token?children:history.push('/login')}   
    </>
  )
}
