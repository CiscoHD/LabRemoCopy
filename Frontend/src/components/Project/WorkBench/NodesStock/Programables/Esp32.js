import ESP32 from "@/assets/media/Nodes/Programables/ESp32.png";

const defaultHandleSize = { width: 8, height: 8 };
let handles = [];

const filaInferior = [
  { prefijo: "JA", cantidad: 14, top: "83%", inicio: 11, espacio: 5 },
 // { prefijo: "JB", cantidad: 5, top: "78%", inicio: 38, espacio: 6 },
 //{ prefijo: "Jc", cantidad: 5, top: "79%", inicio: 67.5, espacio: 6 },
  { prefijo: "JD", cantidad: 14, top: "8%", inicio: 11, espacio: 5 },
  //{ prefijo: "JE", cantidad: 5, top: "8%", inicio: 38, espacio: 6 },
  //{ prefijo: "JF", cantidad: 5, top: "8%", inicio: 67.5, espacio: 6 },
];

// Prefijos que se conectan hacia arriba
const haciaArriba = ["JD"];

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
  name: "ESP32",
  url: ESP32,
  type: "programable",
  size: { x: "45%", y: "45%" },
  handles,
};
