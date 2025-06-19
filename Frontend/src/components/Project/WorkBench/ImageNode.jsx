import { Handle } from "@xyflow/react";

const ImageNode = ({ data }) => {
  const { image, size, handles } = data;

  return (
    <div style={{ position: "relative", width: size.x, height: size.y }}>
      <img
        src={image.url}
        alt={image.alt}
        style={{ width: "100%", height: "100%" }}
      />
      {handles.map((handle, index) => {
        const backgroundColor =
          handle.style.background ||
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
  );
};

export default ImageNode;
