import React from 'react'
import ImageLoader from './ImageLoader'



export default function BoardInfo({label,url}) {

    const border = 'dashed'

  return (
    <div style={{
        float:'center',
        width: '80%',
        margin:'auto',
        
    }}>
        <div style={{
            display: 'flex',
            margin: 'auto',
            justifyContent:'center'
    }}>
        <div style={{
            padding: 10,
            border: border,
            borderRight: 'none'
        }}><ImageLoader url={url} width={180} /></div>
        <div style={{
            border: border,
        }}>DESCRIPCIÓN: {label} 
        <div>
        Lorem Ipsum is simply dummy text of the printing and typesetting industry. 
        Lorem Ipsum has been the industry's standard dummy text ever since the 1500s
         </div>
        </div>
        </div>
    </div>
  )
}
