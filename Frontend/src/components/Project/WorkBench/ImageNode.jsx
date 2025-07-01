import { Handle } from "@xyflow/react";

const ImageNode = ({ data }) => {
  const { image, size, handles, rotation = 0, scale = 1 } = data;

  const outerStyle = {
    width: size.x * scale,
    height: size.y * scale,
    position: "relative",
  };

  const innerStyle = {
    width: size.x,
    height: size.y,
    transform: `scale(${scale}) rotate(${rotation}deg)`,
    transformOrigin: "top left",
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
              key={index}
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
