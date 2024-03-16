import './contextual.css'
import React, { useEffect, useState } from 'react'

import ArchitectureIcon from '@mui/icons-material/Architecture';

export default function FloatingMenu({toggle,handler}) {
    //const [toggle, setToggle] = useState(false);

    const [menuItems,setMenuItems] = useState([]);

    const menu = [
      {
        color: "#6571ac",
        icon: <ArchitectureIcon  className='innerIcon' />,
      },{
        color: "#6165c2",
        icon: <ArchitectureIcon  className='innerIcon'  />,
      },      {
        color: "#5d58d7",
        icon: <ArchitectureIcon  className='innerIcon' />,
      },{
        color: "#aa77c3",
        icon: <ArchitectureIcon  className='innerIcon'  />,
      },      {
        color: "#f696af",
        icon: <ArchitectureIcon  className='innerIcon' />,
      }
    ]

    const makeMenu = (menu) =>{
      const angle = 360/menu.length;
      let rotation = 0;
      let items = [];

      menu.forEach(({
        color,
        icon,
      })=>{
        items.push({
          color,icon,rotation,angle,show: false
        });
        rotation += angle;
      });
      
      setMenuItems(items);
      console.log(menu,items);
    }

    const animateButtons = () =>{
      const length = menuItems.length;

      const stagger= (i) =>{
        if(i<length){
          setTimeout(()=>{
            let items = menuItems;
            let showing = menuItems[i].show;

            setMenuItems(
              [
                ...items.slice(0,i),
                Object.assign({}, items[i],{
                  show: !showing
                }),
                ...items.slice(i+1)
              ]);
            stagger(i+1)
          },60);
        }
      };

      stagger(0);
    }

    const MenuItems = ({
      size,
      items,
      open,
    }) => {
      const buttons = items.map((item) => {
        const styling = {
          transform:
            `rotate(${item.rotation}deg)
            translate(${size/2}em)
            rotate(${-(item.rotation)}deg)`,
          backgroundColor: item.color,
        };

        return (
          <div 
          className={'menu-item'}
          style={styling}
          onClick={handler}
          >
            
            {item.icon}
            
          </div>
        );
      });

      return (
        <div className={open
                ?'button-bg animate-menu'
                : "button-bg"}>
          {buttons}
        </div>
      )
    }

    const Menu = ({
      size,
      items,
      toggle,
      open,
    }) => {
      return(
      <div className={open
              ? "menu-wrapper-open"
              : "menu-wrapper-closed"}
              >
        <div className={"menu-background"}>
          <MenuItems
            size={size}
            items={items}
            open={open}
          />
        </div>
      </div>
      )
    }

    useEffect(()=>{
      makeMenu(menu);
    },[]);

  return (
    <div >
          <Menu 
            size={12}
            items={menuItems}
            open={toggle}
          />
    </div>
  )
}
