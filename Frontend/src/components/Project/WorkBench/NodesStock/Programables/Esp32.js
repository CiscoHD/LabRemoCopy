import ESP32 from "@/assets/media/Nodes/Programables/ESp32.png";

const defaultHandleSize = { width: 8, height: 8 };//el tamaño de los pines 
let handles = [];

const filaInferior = [
  { prefijo: "JA", cantidad: 14, top: "83%", inicio: 11, espacio: 5 },//pines de abajo
  { prefijo: "JD", cantidad: 14, top: "8%", inicio: 11, espacio: 5 },//pines de arriba
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
