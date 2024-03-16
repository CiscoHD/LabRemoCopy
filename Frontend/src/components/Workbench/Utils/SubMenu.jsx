import React from 'react'

import SubMenuItem from './SubMenuItem';

export default function SubMenu({ subMenuItems, className,functions }){
    return (
        <div className="ws-dropcontent">
            {subMenuItems.map((item) => {
                return (
                    <SubMenuItem subMenuItem={item} className={className} functions={functions} />
                )
            })}
        </div>
    );
}