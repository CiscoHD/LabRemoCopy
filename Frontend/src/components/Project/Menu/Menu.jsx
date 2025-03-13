import MenuItem from "./MenuItem";

export default function Menu({ menu }) {
  return (
    <div className="menu-workspace">
      {menu.map((item) => {
        return <MenuItem key={item.menuItem} itemMenu={item} />;
      })}
    </div>
  );
}
