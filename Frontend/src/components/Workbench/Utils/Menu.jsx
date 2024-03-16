import React from 'react'

import MenuItem from './MenuItem';

export default function Menu ({ menu, className, functions }){
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
