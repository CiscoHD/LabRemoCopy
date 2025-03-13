import { useContext } from "react";

import SubMenu from "./SubMenu";

import { actuadores, luces, sensores, programables } from "./localdata";
import { MenuContext } from "@/context/MenuContext";

export default function SubMenuItem({ subMenuItem, className }) {
  const menuContext = useContext(MenuContext);

  return (
    <div
      className={`${className ? className + " " : ""}ws-dropmenu-item`}
      onClick={() => {
        subMenuItem.action && console.log(subMenuItem);
        var actions = [];

        actuadores
          .concat(luces)
          .concat(sensores)
          .concat(programables)
          .forEach((element) => {
            actions.push(element.action);
          });

        if (subMenuItem.action == "save") {
          menuContext.functions[subMenuItem.action]();
        }
        if (actions.includes(subMenuItem.action)) {
          menuContext.functions["add"](subMenuItem.action);
        }
        subMenuItem.action &&
          console.log(menuContext.functions[subMenuItem.action]);
        //submenuItem.action&&setFunctions['save']()
      }}
    >
      <span></span>
      {subMenuItem.submenuItem}
      {subMenuItem.submenuItems && (
        <SubMenu
          subMenuItems={subMenuItem.submenuItems}
          className={"subsubmenu"}
        />
      )}
    </div>
  );
}
