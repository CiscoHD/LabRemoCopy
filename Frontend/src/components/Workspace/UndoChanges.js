import React from 'react';
import './Button.css'; // Archivo CSS para los estilos del botón

const UndoChanges = ({ handleUndo }) => {
  return (
    <div>
      {/* Botón de deshacer */}
      <button className="undo-button" onClick={handleUndo}>
        Deshacer cambios
      </button>
      {/* Otros componentes relacionados con deshacer cambios */}
    </div>
  );
};

export default UndoChanges;
