import React from 'react';

import './typeboard.css'

import { useHistory } from 'react-router-dom/cjs/react-router-dom';

import CardBoard from './CardBoard';
import ImageCont from './ImageCont';

import Arduino from '../../../media/Boards/Arduino.png';
import ArduinoMega from '../../../media/Boards/ArduinoMEGA.png';
import ESP32 from '../../../media/Boards/Esp32nodemcubis_2.png';
import ZYBO from '../../../media/Boards/ZYBO2.png';


export default function TypeBoard({setBoard,boardactive}) {

  const history = useHistory();

  const boards = [
    { 'board': 'arduino',
      'title':'Arduino MEGA',
      'url': ArduinoMega,
    },
    { 'board':'esp8226',
      'title':'ESP32',
      'url': ESP32,
    },
    { 'board':'zybo',
      'title':'Zedboard',
      'url': ZYBO,
    }
  ]

  return (
    <div>
    <div  className='cardboard-container'> 
    {boards.map((board)=>{
      return(
        <CardBoard board={board} setBoard={setBoard} bactive={boardactive} />
      )
    })}

    {/*<CardBoard title={'Arduino MEGA'} content={<ImageCont className={`${board=='arduino'?'active ':''} arduino`} url={ArduinoMega} board={'arduino'} setBoard={setBoard} />}/>
    <CardBoard title={'ESP8226'} content={<ImageCont className={`${board=='esp32'?'active ':''} esp32`} url={ESP32} board={'esp8226'} setBoard={setBoard}  />}/>
    <CardBoard title={'ZYBO'} content={<ImageCont className={`${board=='zybo'?'active ':''} zybo`} url={ZYBO} board={'zybo'} setBoard={setBoard}  />}/>
    */}
    </div>

    </div>
  )
}
