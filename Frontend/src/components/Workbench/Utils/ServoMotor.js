import { Handle, Position } from 'reactflow';
import React, { memo } from "react";

export default memo(({ data, isConnectable }) => {
    return (
      <>
        {/* Contenido de tu nodo personalizado */}
        <img src={data.image.url} alt={data.image.alt} />
        <Handle
          type="target"
          position={Position.Left}
          id="a" // Aquí puedes asignar un ID único a este handle
          isConnectable={isConnectable}
        />
        <Handle
          type="source"
          position={Position.Top}
          id="b   " // Aquí puedes asignar un ID único a este handle
          isConnectable={isConnectable}
        />
      </>
    );
  });