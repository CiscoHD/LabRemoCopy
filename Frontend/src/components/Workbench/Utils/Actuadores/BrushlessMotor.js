//1 target
//id= F
import React, { memo } from 'react';
import { Handle, Position } from 'reactflow';

const DEFAULT_HANDLE_STYLE = {
  width: 7,
  height: 7,
  bottom: -7,
  position: 'absolute', // Ensure handles are positioned absolutely
};

export default memo(({ data, isConnectable }) => {
  const imageStyle = {
    position: 'relative', // Ensure the image container has a relative position
    width: '250px',
    height: '250px',
  };

  return (
    <div style={{ position: 'relative', width: '150px', height: '150px', display: 'inline-block' }}>
      <div style={imageStyle}>
        <img style={{ width: '100%', height: '100%' }} src={data.image.url} alt={data.image.alt} />
        <Handle
          type="target"
          id="red"
          position={Position.Bottom}
          style={{ ...DEFAULT_HANDLE_STYLE, left: '15%', transform: 'translateX(-50%)', background: 'red' }}
          onConnect={(params) => console.log('handle onConnect', params)}
          isConnectable={isConnectable}
        />
        
      </div>
    </div>
  );
});
