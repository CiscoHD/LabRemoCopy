import React, {useState, useEffect} from 'react'
import { menuData } from './utils';

export default function MenuWrapper() {

    const [menuOpen,setMenuOpen] = useState(false);
    const [menuItems,setMenuItems] = useState([]);

    const makeMenu = (menuConfig) => {
      const angle = 360 / menuConfig.length;
      let rotation = 0;
      let menuItemsl = [];
      
      menuConfig.forEach(({
        color, 
        icon, 
        click
      }) => {
        menuItemsl.push({
          color,
          icon,
          click,
          rotation,
          angle,
          show: false
        });
        rotation += angle;
      }); 
      
      setMenuItems(menuItemsl);
    };
    
    // calculate angles and distance between menu items
    // then set position on menu-item objects
    const toggleMenu = () => {
      setMenuOpen(!menuOpen);
    }
    
    // staggerd fade menu items in
    const animateButtons = () => {
      const length = menuItems.length;
      
      const stagger = (i) => {
        if (i < length) {
            setTimeout(() => {
            let items = menuItems;
            let showing = menuItems[i].show;
            
            setMenuItems(
              [
                ...items.slice(0, i),
                Object.assign({}, items[i], {
                  show: !showing
                }),
                ...items.slice(i + 1)
              ]);
            
            stagger(i + 1);
            
          },60);
        }
      };
      
      stagger(0); 
    }

    const MenuItems = ({
      size, 
      items, 
      open
    }) => {
      const buttons = items.map((item) => {
        const styling = {
          transform:
            `rotate(${item.rotation}deg) 
            translate(${size/2}em) 
            rotate(${-(item.rotation)}deg)`,
          backgroundColor: item.color
        };
        
        return (
          <div 
            className={item.show 
              ? "menu-item item-show" 
              : "menu-item item-hide"}
            style={styling}
            onClick={item.click}
          >
            <i className={"fa " + item.icon}
              aria-hidden="true"
            ></i>
          </div>
        );
      });
      
      return (
        <div 
          className={open 
            ? "button-bg animate-menu" 
            : "button-bg"}
        > {buttons}
        </div>
      ); 
    }

    const MenuToggle = ({
      toggle, 
      open, 
      animateButtons
    }) => (
      <button 
        className={open 
          ? "menu-toggle toggle-open" 
          : "menu-toggle toggle-closed"}
        onClick={() => {
          toggle(); 
          setTimeout(
            animateButtons, 
            120
          );
        }}
      > <i className={open 
            ? "fa fa-times"
            : "fa fa-bars"}
          aria-hidden="true"
        ></i>
      </button>
    );

    const Menu = ({
      size, 
      items, 
      toggle, 
      open
    }) => (
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
    );

    
    
    

  return (
      <div onLoad={()=>makeMenu(menuData)}>
        <MenuToggle
          toggle={toggleMenu}
          open={menuOpen}
          animateButtons={animateButtons}
        />
        <Menu
          size={24}
          items={menuItems} 
          open={menuOpen}
        />
      </div>
    );
}
