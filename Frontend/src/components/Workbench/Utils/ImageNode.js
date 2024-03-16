import React, { memo } from 'react';
import { Handle, Position} from 'reactflow';
  
export default memo(({ data, isConnectable }) => {

  const DEFAULT_HANDLE_STYLE = {
    width: 20,
    height: 20,
    border: "blue"
  };
 
  const handles_array = data.handles?data.handles:[
      {
        type:'source',
        id:'red',
        position: Position.Bottom,
        style: { ...DEFAULT_HANDLE_STYLE, left: '15%', background: 'red' },
        isConnectable: {isConnectable}
      },
      {
       type:'source',
        id:'blue',
        position: Position.Bottom,
        style: { ...DEFAULT_HANDLE_STYLE, left: '50%', background: 'blue' },
        isConnectable: {isConnectable}
      },
      {
        type:'source',
        id:'orange',
        position: Position.Bottom,
        style: { ...DEFAULT_HANDLE_STYLE, left: '85%', background: 'orange', },
        isConnectable: {isConnectable}
      },
      {
        type:'target',
        id:'pink',
        position: Position.Top,
        style: { ...DEFAULT_HANDLE_STYLE, left: '25%', background: 'pink', },
        isConnectable: {isConnectable}
      },
      {
        type:'target',
        id:'pink2',
        position: Position.Top,
        style: { ...DEFAULT_HANDLE_STYLE, left: '75%', background: 'pink', },
        isConnectable: {isConnectable}
      },
    ];

   return (
       <div
         style={{
          //  mixBlendMode: 'multiply',
          //  background: 'white',
         }}
       >
         {/* <div>Node</div> */}
         <img style={{
          // background: 'transparent',
          mixBlendMode:'multiply',
          width: '100px',
          height: '100px',
          // border: '1px solid black',
          width: data.size?data.size.x:'120px',
          height: data.size?data.size.y:'120px',
          }} src={data.image.url} alt={data.image.alt} />



        {handles_array.map((handle) => {
          return(
            <Handle
              type={handle.type}
              id={handle.id}
              position={handle.position}
              style={{...handle.style, background:`${handle.type=='target'?'#FF0000':'#0000FF'}`}}
              /* onConnect={(params) => console.log('handle onConnect', params)} */
              isConnectable={handle.isConnectable}
            />
          );
        })}
       </div>
   );
});