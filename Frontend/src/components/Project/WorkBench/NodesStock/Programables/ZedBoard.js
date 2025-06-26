import ZedBoard from "@/assets/media/Nodes/Programables/Zedboard1.png";

const defaultHandleSize = { width: 4, height: 5};
const firstLeft = "4%"; // Más hacia la izquierda
const secondLeft = "5%"; // Cerca del borde derecho

const filaInferior = [
   
  { prefijo: "J20", cantidad: 23, top: "69%", inicio: 85.5, espacio: 2 },// pines de lado vertical de la FMC
  { prefijo: "J16", cantidad: 26, top: "68%", inicio: 48, espacio: 1.5},// pines de abajo de la FMC
  { prefijo: "J1", cantidad: 26, top: "24%", inicio: 48, espacio: 1.5 },// pines de la parte de arriba FMC 
  { prefijo: "Jl", cantidad: 4, top: "86%", inicio: 8, espacio: 1.5},
  { prefijo: "JE", cantidad: 4, top: "83%", inicio: 8, espacio: 1.5 },
  { prefijo: "JF", cantidad: 4, top: "86%", inicio: 16.5, espacio: 1.5},
  { prefijo: "JG", cantidad: 4, top: "83%", inicio: 16.5, espacio: 1.5 },
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
  size: { x: "55%", y: "60%" },
  handles,
};
