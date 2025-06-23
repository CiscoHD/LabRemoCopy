import ZedBoard from "@/assets/media/Nodes/Programables/ZEDBOARD.png";

const defaultHandleSize = { width: 3, height: 3 };
const firstLeft = "4%"; // Más hacia la izquierda
const secondLeft = "5%"; // Cerca del borde derecho

// Bloques de pines y su posición vertical (top)
const filavertical = [
  { prefijo: "JA", top: ["46%", "48.2%", "50.5%", "52.5%"]},
  { prefijo: "JB", top: ["59%", "61.3%", "63.5%", "65.5%"] },
  { prefijo: "JC", top: ["72%", "74%", "76%", "78.5%"] },
];

// lOS Handles son los pines 
// Generar todos los handles dinámicamente
let handles = [];

filavertical.forEach(({ prefijo, top}) => {
  top.forEach((t, i) => {
    const pinNumber = 4 - i;
    handles.push({
      id: `${prefijo}${pinNumber}`,
      type: "source",
      position: "left", // Conexión hacia la izquierda
      style: { left: firstLeft, top: t },
    });
    handles.push({
      id: `${prefijo}${pinNumber}_1`,
      type: "source",
      position: "right", // Conexión hacia la derecha
      style: { left: secondLeft, top: t },
      zIndex: 10,
    });
  });
});
// Pines horizontales en la parte inferior

const filaInferior = [
  { prefijo: "JD", cantidad: 4, top: "86%", inicio: 8, espacio: 1.5},
  { prefijo: "JE", cantidad: 4, top: "83%", inicio: 8, espacio: 1.5 },
  { prefijo: "JF", cantidad: 4, top: "86%", inicio: 16.5, espacio: 1.5},
  { prefijo: "JG", cantidad: 4, top: "83%", inicio: 16.5, espacio: 1.5 },
  
];

filaInferior.forEach(({ prefijo, cantidad, top, inicio, espacio }) => {
  for (let i = 1; i <= cantidad; i++) {
    handles.push({
      id: `${prefijo}${i}`,
      type: "source",
      position: "bottom",
      style: {
        top,
        left: `${inicio + (i - 1) * espacio}%`,
        zIndex: 10,
        ...defaultHandleSize,
      },
    });
  }
});


// Agregar estilo base a todos los handles
handles = handles.map((handle) => ({
  ...handle,
  style: {
    ...defaultHandleSize,
    ...handle.style,
  },
}));

// Exportar el nodo completo
export default {
  name: "ZedBoard",
  url: ZedBoard,
  type: "programable",
  size: { x: "45%", y: "45%" },
  handles,
};
