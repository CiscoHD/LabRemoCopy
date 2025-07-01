import ZedBoard from "@/assets/media/Nodes/Programables/Zedboard1.png";

const defaultHandleSize = { width: 5, height: 5};
const firstLeft = "4%"; // Más hacia la izquierda
const secondLeft = "5%"; // Cerca del borde derecho
const trueDimensions = { tamX: 931, tamY: 445 }; //Dimensiones reales de la imagen original 

const filaInferior = [
   
  { prefijo: "J20", cantidad: 23, top: "82%", inicio: 97.5, espacio: 3.1 },// pines de lado vertical de la FMC
  { prefijo: "J16", cantidad: 26, top: "78.5%", inicio: 54, espacio: 1.7},// pines de abajo de la FMC
  { prefijo: "J1", cantidad: 26, top: "13.5%", inicio: 54, espacio: 1.7 },// pines de la parte de arriba FMC 
];
// lOS Handles son los pines 
// Generar todos los handles dinámicamente
const haciaArriba = ["J1"];
let handles = [];

filaInferior.forEach(({ prefijo, cantidad, top, inicio, espacio }) => {
  const esJD = prefijo === "J20";
  const posicion = esJD
    ? "right" // Conexión hacia la derecha
    : haciaArriba.includes(prefijo)
    ? "top"
    : "bottom";

  for (let i = 1; i <= cantidad; i++) {
    const style = esJD
      ? {
          top: `${parseFloat(top) - (i - 1) * espacio}%`,
          left: `${inicio}%`,
        }
      : {
          top,
          left: `${inicio + (i - 1) * espacio}%`,
        };
// Agregar estilo base a todos los handles
    handles.push({
      id: `${prefijo}${i}`,
      type: "source",
      position: posicion,
      style: {
        ...defaultHandleSize,
        ...style,
        zIndex: 10,
      },
    });
  }
});
// Exportar el nodo completo
export default {
  name: "ZedBoard",
  url: ZedBoard,
  type: "programable",
  size: { x: `${Math.ceil(trueDimensions.tamX*.55)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.55)}px` },
  handles,
};
