import SubMenuItem from "./SubMenuItem";

export default function SubMenu({ subMenuItems, className }) {
  return (
    <div className="ws-dropcontent">
      {subMenuItems.map((item) => {
        return (
          <SubMenuItem
            key={item.submenuItem}
            subMenuItem={item}
            className={className}
          />
        );
      })}
    </div>
  );
}
