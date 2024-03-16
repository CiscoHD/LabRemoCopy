import ArchitectureIcon from '@mui/icons-material/Architecture';

// example click handler for menu items
export const itemClick = (e) => {
    console.log("clicked");
  }

  // config for menu
export const menuData = [
    {
      color: "#b3462f",
      icon: < ArchitectureIcon />,
      click: itemClick
    },{
      color: "#e78b38",
      icon: "fa-pencil",
      click: itemClick
    },{
      color: "#353535",
      icon: "fa-trash",
      click: itemClick
    },{
      color: "#303c54",
      icon: "fa-tags",
      click: itemClick
    },{
      color: "#3a384e",
      icon: "fa-search",
      click: itemClick
    },{
      color: "#78332c",
      icon: "fa-users",
      click: itemClick
    },{
      color: "#78332c",
      icon: "fa-users",
      click: itemClick
    }
  ];