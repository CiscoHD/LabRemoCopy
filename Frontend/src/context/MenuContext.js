import { createContext, useState, useEffect } from "react";

export const MenuContext = createContext();

export function MenuProvider(props){
    const [functions,setFunctions]=useState({});

    const [vidCon, setVidCon] = useState({video: false,
        console: true})


    const [reactFlowInstance, setReactFlowInstance] = useState(null);

    const [loading, setLoading] = useState(false);


    const saveStatus = (reactFlowInstance) => {

    }

    return(
        <MenuContext.Provider value={{
            //Variables
            functions,
            vidCon,
            reactFlowInstance,
            loading,
            //Functions
            setFunctions,
            setVidCon,
            setReactFlowInstance,
            setLoading,
            }} >
            {props.children}
        </MenuContext.Provider>
    )
}