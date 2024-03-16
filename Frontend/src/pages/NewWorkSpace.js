import React, { useContext, useEffect, useState } from 'react'
import '../components/nuevos/Workspace/mesa.css'

import {
    actuadores, luces, sensores, programables,
    menu, menu2
} from '../components/nuevos/Workspace/localdata'

//import menuReducer, { menuActions } from '../components/nuevos/Workspace/menuActions'

import Mesa from './AuxiliarWorkbench'
import Sidebar from "../components/Workbench/Utils/Sidebar"
import Console from "../components/Workbench/Utils/Console"
import Video from '../components/Workbench/Utils/Video'
import UndoChanges from '../components/Workspace/UndoChanges'
import Delete from "../components/Workspace/Delete"
// import Menu from '../components/nuevos/Workspace/Menu'
import Menu from '../components/Workbench/Utils/Menu'
import UploaderFile from '../components/UploaderFile'
import { RosContext } from '../context/RosContext'
import { MenuContext, MenuProvider } from '../context/MenuContext'


export default function NewWorkSpace({children}) {

    // const [functions, setFunctions] = useState({});

    const ros = useContext(RosContext);
    const menuCntx = useContext(MenuContext);


    // console.log(status)



    

                //  const UndoChanges = ({ handleUndo }) => {
                //     const [isHovered, setIsHovered] = useState(false);
                
                //     return (
                //       <button
                //         className="undo-button"
                //         onClick={handleUndo}
                //         onMouseEnter={() => setIsHovered(true)}
                //         onMouseLeave={() => setIsHovered(false)}
                //         style={{ animation: isHovered ? 'someAnimation 0.3s linear infinite' : 'none' }}
                //       >
                //         Deshacer cambios
                //       </button>
                //     );
                //   };
                
                //   const DeleteSelection = ({ handleDelete }) => {
                //     const [isHovered, setIsHovered] = useState(false);
                
                //     return (
                //       <button
                //         className="delete-button"
                //         onClick={handleDelete}
                //         onMouseEnter={() => setIsHovered(true)}
                //         onMouseLeave={() => setIsHovered(false)}
                //         style={{ animation: isHovered ? 'someAnimation 0.3s linear infinite' : 'none' }}
                //       >
                //         Borrar selección
                //       </button>
                //     );
                //   };


    return (
        
        <div className='mesa'>
            <div className="menu-workspace-main">
                <Menu menu={menu}/>
                <Menu menu={menu2} />
            </div>
            {children}

            <Mesa></Mesa>
            <Video ></Video>
            <Sidebar></Sidebar>
            <Console ros={ros}></Console>

            {menuCntx.loading&&<div className="uploader-modal">            
            <UploaderFile
                title={'Zedboard'} 
                board={'Zedboard'} 
                ext={'.v'}>
            </UploaderFile>
            </div>}



        </div>
        
    )
}
