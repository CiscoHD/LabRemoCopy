import { Handle, useUpdateNodeInternals } from "@xyflow/react";
import { useEffect, useState } from "react";

const ImageNode = ({ data, id }) => {
  const { image, size, handles, rotation = 0, scale = 1 } = data;
  const updateNodeInternals = useUpdateNodeInternals();
  const [currentRotation, setCurrentRotation] = useState(rotation);

  // Actualizar las posiciones de los handles cuando cambia la rotación
  useEffect(() => {
    updateNodeInternals(id);
  }, [currentRotation, id, updateNodeInternals]);

  // Sincronizar con la rotación externa
  useEffect(() => {
    setCurrentRotation(rotation);
  }, [rotation]);

  const outerStyle = {
    width: size.x * scale,
    height: size.y * scale,
    position: "relative",
  };

  const innerStyle = {
    width: size.x,
    height: size.y,
    transform: `scale(${scale}) rotate(${currentRotation}deg)`,
    transformOrigin: "center center",
  };

  return (
    <div style={outerStyle}>
      <div style={innerStyle}>
        <img
          src={image.url}
          alt={image.alt}
          style={{
            width: "100%",
            height: "100%",
          }}
        />
        {handles.map((handle, index) => {
          const backgroundColor =
            handle.style?.background ||
            (handle.type === "target" ? "red" : "blue");

          return (
            <Handle
              key={`${handle.id}-${currentRotation}`}
              id={handle.id}
              type={handle.type}
              position={handle.position}
              style={{
                ...handle.style,
                background: backgroundColor,
              }}
              isConnectable={handle.isConnectable}
            />
          );
        })}
      </div>
    </div>
  );
};

export default ImageNode;
