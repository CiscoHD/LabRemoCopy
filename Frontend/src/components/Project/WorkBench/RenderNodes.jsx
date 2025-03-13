const RenderNodes = ({ id, name, position, url, nodeType, size, handles }) => {
  return {
    id,
    nodeType,
    type: "imageNode",
    data: {
      image: { url: url, alt: name },
      size,
      handles,
    },
    position,
  };
};

export default RenderNodes;
