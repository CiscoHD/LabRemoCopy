import { Padding } from "@mui/icons-material";
import { createTheme } from "@mui/material";
import { orange } from "@mui/material/colors";


const theme = createTheme({
    palette:{
        primary:{
            main: '#DFE0DC',
            paper: '#FFFFFF',
        }
    },
    img:{
        display: 'flex',
        height: '150px',
        width : '150px',
        margin: 'auto',
    },
    navbar:{
        link: {
            margin: '5px',
            "&:hover": {
                margin: '8px',
                fontWeight: 'bold' 
              },
        }
    },
    estilo1:{
            display: 'flex',
            justifyContent: 'center',
            margin: 'auto',
            width: '50%',
            borderRadius: '10px',
            boxShadow: '0 0 10px rgba(0, 0, 0, 0.2)',
    },
  });


  export default theme;