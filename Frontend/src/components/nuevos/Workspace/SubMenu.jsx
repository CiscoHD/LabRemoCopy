import React from 'react'

import SubMenuItem from './SubMenuItem';


const SubMenu = ({ subMenuItems, className, functions }) => {
    return (
        <div className="ws-dropcontent">
            {subMenuItems.map((item) => {
                return (
                    <SubMenuItem subMenuItem={item} className={className} 
                    functions={functions} />
                )
            })}
        </div>
    );
}


export default SubMenu