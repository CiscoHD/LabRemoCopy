import React from 'react'

export default function Icons({Icon, className,url}) {
  return (
    <a href={url}>
            <Icon className={className} />
    </a>
  )
}
