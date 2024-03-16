import React, {createContext, useContext, useReducer} from 'react'

export const WorkspaceContext = createContext()

export const WorkspaceProvider = ({reducer, initialState, children}) => (
    <WorkspaceContext.Provider value={useReducer(reducer,initialState)}>
        {children}
    </WorkspaceContext.Provider>
)

export const useWorkspaceValue = () => useContext(WorkspaceContext)