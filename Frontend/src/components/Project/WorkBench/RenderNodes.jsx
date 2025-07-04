const RenderNodes = ({ id, name, position, url, nodeType, size, handles, onRotationChange }) => {
  return {
    id,
    nodeType,
    type: "imageNode",
    data: {
      image: { url: url, alt: name },
      size,
      handles,
      onRotationChange: onRotationChange ? (rotation) => onRotationChange(id, rotation) : undefined,
    },
    position,
  };
};

export default RenderNodes;
