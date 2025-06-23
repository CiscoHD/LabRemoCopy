import Arduino from "@/assets/media/Nodes/Programables/ARDUINO_NANO33.png";

const defaultHandleSize = { width: 7.5, height: 8 };
let handles = [];

const filaInferior = [
  { prefijo: "JA", cantidad: 5, top: "78%", inicio: 9, espacio: 6 },
  { prefijo: "JB", cantidad: 5, top: "78%", inicio: 38, espacio: 6 },
  { prefijo: "Jc", cantidad: 5, top: "79%", inicio: 67.5, espacio: 6 },
  { prefijo: "JD", cantidad: 5, top: "6%", inicio: 8.5, espacio: 6 },
  { prefijo: "JE", cantidad: 5, top: "6%", inicio: 38, espacio: 6 },
  { prefijo: "JF", cantidad: 5, top: "6%", inicio: 67.5, espacio: 6 },
];

// Prefijos que se conectan hacia arriba
const haciaArriba = ["JD", "JE", "JF"];

filaInferior.forEach(({ prefijo, cantidad, top, inicio, espacio }) => {
  const posicion = haciaArriba.includes(prefijo) ? "top" : "bottom";

  for (let i = 1; i <= cantidad; i++) {
    handles.push({
      id: `${prefijo}${i}`,
      type: "source",
      position: posicion,
      style: {
        top,
        left: `${inicio + (i - 1) * espacio}%`,
        zIndex: 10,
        ...defaultHandleSize,
      },
    });
  }
});

handles = handles.map((handle) => ({
  ...handle,
  style: {
    ...defaultHandleSize,
    ...handle.style,
  },
}));

export default {
  name: "Arduino",
  url: Arduino,
  type: "programable",
  size: { x: "45%", y: "45%" },
  handles,
};

