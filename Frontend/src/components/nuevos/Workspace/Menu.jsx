import React from 'react'

import MenuItem from './MenuItem';

const Menu = ({ menu, className, functions }) => {
    return (
        <div className={`${className ? className + ' ' : ''}menu-workspace`}>
            {menu.map((item) => {
                return (
                    <MenuItem itemMenu={item} functions={functions} />
                );
            })}
        </div>
    );
}

export default Menu