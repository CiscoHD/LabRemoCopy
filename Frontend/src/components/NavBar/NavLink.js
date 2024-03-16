import React from 'react'
import { Link } from 'react-router-dom'

import { useTheme } from '@emotion/react'
//import { Link } from '@mui/material'
import theme from '../Theme'
import { Box } from '@mui/material'
import { hover } from '@testing-library/user-event/dist/hover'

export default function NavLink({url,children}) {
    const mytheme = useTheme(theme)
  return (
    <Box  sx={mytheme.navbar.link}>
        <Link to={url}>{children}</Link>
    </Box>
  )
}
