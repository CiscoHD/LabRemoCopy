import { useContext } from "react";
import SubMenu from "./SubMenu";
import { MenuContext } from "@/context/MenuContext";

export default function MenuItem({ itemMenu }) {
  const menuCntx = useContext(MenuContext);

  return (
    <div
      className="ws-item-menu ws-drop"
      onClick={() => {
        if (itemMenu.action == "load") {
          menuCntx.setLoading(true);
        }
      }}
    >
      {itemMenu.menuItem}
      {itemMenu.submenuItems && (
        <SubMenu subMenuItems={itemMenu.submenuItems} />
      )}
    </div>
  );
}
