import React from 'react'

export default function ImageLoader({url, width}) {
  return (
    <img src={url} width={width} style={{
      transform: 'rotate(90deg) translate(35%,-10%)',
    }} />
  )
}
