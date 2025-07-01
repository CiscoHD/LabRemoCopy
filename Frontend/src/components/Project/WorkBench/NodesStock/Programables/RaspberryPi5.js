import RaspberryPi5 from "@/assets/media/Nodes/Programables/RASPBERRYPI_5.png";

const defaultHandleSize = { width: 1, height: 1 };
const firstLeft = "58%"; // Más hacia la izquierda
const secondLeft = "64%"; // Cerca del borde derecho
const trueDimensions = { tamX: 440, tamY: 567 }; //Dimensiones reales de la imagen original 

// Bloques de pines y su posición vertical (top)
const filavertical = [
  { prefijo: "JA", top: ["40%","43%","46%","49%","52%", "55%","58%", "61%", "64%", "67%", "70%", "73%", "76%", "79%","82%","85%","88%","91%","94%","97%"]},

];

// Los Handles son los pines 
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

handles = handles.map((handle) => ({
  ...handle,
  style: {
    ...defaultHandleSize,
    ...handle.style,
  },
}));

export default {
  name: "RaspberryPi5",
  url: RaspberryPi5,
  type: "programable",
  //Escala la imagen multiplicando el tamaño real por el porcentaje deseado 
  size: { x: `${Math.ceil(trueDimensions.tamX*.45)}px`, 
          y: `${Math.ceil(trueDimensions.tamY*.45)}px` },
  handles,
};