import React, { useState } from 'react'
import './card.css'


import ImageCont from './ImageCont'
import { Info } from 'react-bootstrap-icons'



export default function CardBoard({board,setBoard,bactive}) {

  /* const [isActive, setIsActive] = useState(false); */

  const Content = () =>{
    return(
    <ImageCont className={board.board} url={board.url} />
    );
  }

  return (
    <div className={`cardboard ${board.board==bactive?'boardactive':''}`} onClick={()=>{setBoard(board.board);
      /* setIsActive(!isActive); */
    console.log(board.board)}}>
        <div className='card-title'>{board?board.title:'Card Title'}</div>
        <div className='card-content'>{board?<Content />:'Card Content'}</div>
        <div className="double-spacing"></div>
        <div className='card-info' onClick={() => {
          console.log(board?`Info about ${board.board}`:'Board Info')
        }}><Info /></div>        
    </div>
  )
}
