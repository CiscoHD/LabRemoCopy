import { menu } from "./localdata";


export const workspaceState = {
    Savestatus: null,
    AddNodes: null,
}

export const menuActions = {
    ASIGN_SAVE: "ASIGN_SAVE",
    ASIGN_ADDN: "ASSIGN_ADDN",
    SAVE_STATUS: "SAVE_STATUS",
    SHARE_STATE: "SHARE_STATE",
    CLOSE: "CLOSE",
    ADD_NODE: "ADD_NODE",   
}

const menuReducer = (arg,action) => {
    switch(action){
        case menuActions.SAVE_STATUS:
            console.log('Saving status... wait please!')
            
        case menuActions.SHARE_STATE:
            console.log(menuActions.SHARE_STATE)
        case menuActions.ADD_NODE:
            console.log(menuActions.ASIGN_SAVE)

        default:
            console.log('defalut')
    }
}

export default menuReducer