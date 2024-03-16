import React from 'react'

export default function ImageCont({url,className}) {
  return (
    <img className={className?className+' img':'img'} src={url}></img>
  )
}
