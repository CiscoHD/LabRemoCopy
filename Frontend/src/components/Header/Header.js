import * as React from 'react';
import AppBar from '@mui/material/AppBar';
import {Link} from '@mui/material';
import Box from '@mui/material/Box';
import Typography from '@mui/material/Typography';

import { ThemeProvider, useTheme } from '@mui/material';
import theme from '../Theme';


import LogoUNAM from '../../media/LogoUNAM.png'
import LogoIIMAS from '../../media/LogoIIMAS_Color.png'
import LogoCont from './LogoCont';




export default function Header() {
    //const mytheme = useTheme(theme)

  return (
    <ThemeProvider theme={theme}>
    <Box
        sx={{
          display: 'flex',
          justifyContent: 'space-evenly',
          backgroundColor: 'primary.main',
          borderRadius: 1,
        }}
      >

      <LogoCont src={LogoUNAM} url={'https://www.unam.mx/'}/>
      <div><Link href='https://www.iimas.unam.mx/'>
      <Typography variant='h5' sx={{
        marginTop: '10%',
        color: '#000000'
      }}>
        Instituto de Investigaciones en Matemáticas
      </Typography>
      <Typography variant='h5' 
        sx={{color: '#000000'}}>
        Aplicadas y en Sistemas
      </Typography>
      </Link>
      </div>
      <LogoCont src={LogoIIMAS} url={'https://www.iimas.unam.mx/'} />
    </Box>
    </ThemeProvider>
  );
}