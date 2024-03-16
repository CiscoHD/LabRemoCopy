import React from 'react'

import SubMenu from './SubMenu';

const MenuItem = ({ itemMenu,functions }) => {
    return (
        <div className="ws-item-menu ws-drop" onClick={() => {
            itemMenu.action && console.log(itemMenu.action)
        }} >
            {itemMenu.menuItem}
            {itemMenu.submenuItems
                ? <SubMenu subMenuItems={itemMenu.submenuItems} functions={functions} />
                : <></>
            }
        </div>
    );
}

export default MenuItem