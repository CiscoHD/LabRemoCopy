import React from 'react'

import SubMenu from './SubMenu';

import {
    actuadores, luces, sensores, programables,
    menu, menu2
} from './localdata'

const SubMenuItem = ({subMenuItem,className, functions}) => {
    console.log(subMenuItem.submenuItem,className)
    return(
        <div className={`${className?className+' ':''}ws-dropmenu-item`} 
        onClick={()=>{
            subMenuItem.action&&console.log(subMenuItem)
            var actions = []

            actuadores.concat(luces).concat(sensores).concat(programables).forEach(element => {
                actions.push(element.action)
            });

            console.log(actions)
            
            if(subMenuItem.action == 'save'){
                functions[subMenuItem.action]()
            }
            subMenuItem.action&&console.log(subMenuItem.action)
            if(actions.includes(subMenuItem.action)){
                console.log(functions)
                functions['add'](subMenuItem.action)
            }
            //subMenuItem.action&&console.log(functions[subMenuItem.action])
            //submenuItem.action&&setFunctions['save']()
        }} >
            <span></span>
            {subMenuItem.submenuItem}
            {subMenuItem.submenuItems ? <SubMenu subMenuItems={subMenuItem.submenuItems} className={'subsubmenu'} /> : ''}
        </div>
    );
}

export default SubMenuItem