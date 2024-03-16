import React from 'react';
import { Box, Link } from '@mui/material';
import theme from '../Theme';
import { useTheme } from '@emotion/react';

export default function LogoCont({src,url}) {
    const mytheme = useTheme(theme);
  return (
    <Link href={url}>
    <Box sx={{
        display: mytheme.img.display,
        height: mytheme.img.height,
        width: mytheme.img.width,
        justifyContent: 'center',
      }}>
        
        <img src={src} />
        
      </Box>
      </Link>
  )
}
