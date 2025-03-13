import { createContext, useContext, useReducer } from "react";

// Crear el contexto
export const StateContext = createContext();

// Proveedor del contexto
export const StateProvider = ({ reducer, initialState, children }) => (
  <StateContext.Provider value={useReducer(reducer, initialState)}>
    {children}
  </StateContext.Provider>
);

// Hook para usar el contexto
export function useStateValue() {
    return useContext(StateContext);
}
