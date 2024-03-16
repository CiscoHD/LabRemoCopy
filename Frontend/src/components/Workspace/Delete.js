import React from 'react';
import './Button.css'; // Archivo CSS para los estilos del botón

const DeleteButton = ({ onClick }) => {
  return (
    <button className="delete-button" onClick={onClick}>
      Borrar seleccionado
    </button>
  );
};

export default DeleteButton;
