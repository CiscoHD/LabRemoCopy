import Arduino from "@/assets/media/Nodes/Programables/ARDUINO_NANO33_1.png";

const defaultHandleSize = { width: 7, height: 7};
const trueDimensions = { tamX: 507, tamY: 209 }; //Dimensiones reales de la imagen original 

const filaInferior = [
  { prefijo: "JA", cantidad: 15, top: "6%", inicio: 7.5 },// pines de arriba 
  { prefijo: "JB", cantidad: 15, top: "80%", inicio: 7.5 },//pines de abajo 
];

const haciaArriba = new Set(["JA"]);// pines que se conectan por arriba 
const pinesInactivos = new Set(["JA4", "JB9"]);// los pines que el usario no puede usar (esto solo es un ejmplo)
const espacio = 6; //espacio que hay de pin a pin 

const handles = filaInferior.flatMap(({ prefijo, cantidad, top, inicio }) =>
  Array.from({ length: cantidad }, (_, i) => {
    const id = `${prefijo}${i + 1}`;
    const esInactivo = pinesInactivos.has(id);
    const posicion = haciaArriba.has(prefijo) ? "top" : "bottom";
    return {
      id,
      type: "source",
      position: posicion,
      isActive: !esInactivo,
      style: {
        ...defaultHandleSize,
        top,
        left: `${inicio + i * espacio}%`,
        zIndex: 10,
        backgroundColor: esInactivo ? "#FF0000" : "#00BFFF",
        pointerEvents: esInactivo ? "none" : "auto",
        opacity: esInactivo ? 0.5 : 1,
        cursor: esInactivo ? "default" : "pointer",
      },
    };
  })
);

export default {
  name: "Arduino",
  url: Arduino,
  type: "programable",
   //Escala la imagen multiplicando el tamaño real por el porcentaje deseado
  size: { x: `${Math.ceil(trueDimensions.tamX*.45)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.45)}px` },
  handles,
};
