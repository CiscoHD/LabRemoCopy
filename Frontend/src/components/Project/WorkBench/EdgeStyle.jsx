import { BaseEdge, getSmoothStepPath } from "@xyflow/react";

export default function EdgeStyle({
  id,
  sourceX,
  sourceY,
  targetX,
  targetY,
  sourcePosition,
  targetPosition,
  style,
}) {
  const { stroke, strokeWidth } = style;

  const [edgePath] = getSmoothStepPath({
    sourceX,
    sourceY,
    sourcePosition,
    targetX,
    targetY,
    targetPosition,
  });

  return (
    <>
      <BaseEdge id={id} path={edgePath} style={{ stroke, strokeWidth }} />
      <circle r="4" fill={stroke} stroke="black" strokeWidth="1">
        <animateMotion dur="3s" repeatCount="indefinite" path={edgePath} />
      </circle>
    </>
  );
}
