import React, { useContext } from 'react'
import SubMenu from './SubMenu';
import { MenuContext } from '../../../context/MenuContext';

export default function MenuItem({ itemMenu,functions }){

    const menuCntx = useContext(MenuContext)

    return (
        <div className="ws-item-menu ws-drop" onClick={() => {
            itemMenu.action && console.log(itemMenu.action)
            if(itemMenu.action=='load'){
                menuCntx.setLoading(true);
                console.log(menuCntx.loading)
            }
        }} >
            {itemMenu.menuItem}
            {itemMenu.submenuItems
                ? <SubMenu subMenuItems={itemMenu.submenuItems} functions={functions} />
                : <></>
            }
        </div>
    );
}