import "./App.css";
import React from "react";
import { useState } from "react";
import { BrowserRouter as Router, Switch, Route, Link } from "react-router-dom";

import { Box, ThemeProvider, useTheme } from "@mui/material";
import theme from "./components/Theme";

import SessionTypeSelection from "./pages/SessionTypeSelection";
//import Header from "./components/Header/Header";
//import NavBar from "./components/NavBar/NavBar";
import Header from "./components/nuevos/Header/Header";

import ActivitySelection from "./pages/ActivitySelection";
import Workbench from "./pages/Workbench";
import Profile from "./pages/Profile";
import AbstractProfile from "./components/Profile/AbstractProfile"


import Protector from "./pages/Protector";
import Login from "./pages/Login";
import Workspace from "./pages/Workspace";
import NewLoginPage from "./pages/NewLoginPage";

import NewWorkSpace from "./pages/NewWorkSpace";
import LandingPage from "./pages/LandingPage";
import UsPage from "./pages/UsPage";
import Contact from "./pages/Contact";
import Welcome from "./pages/Welcome";

import Pruebas from "./pages/Pruebas";
import { RosProvider } from "./context/RosContext";
import { MenuProvider } from "./context/MenuContext";



function App() {
  return (
    <ThemeProvider theme={theme}>
      <RosProvider>
      <MenuProvider>
      <Router>
        <div className="App">
          <Header />
          {/*true ? <NavBar /> : <></>*/}
          <div className="main-container">
        <div className="separador1" ></div>
            <Switch>
              <Route exact path="/" component={Welcome}/>
              <Route exact path="/welcome" component={Welcome}/>
              <Route path="/selection" component={ActivitySelection} />
              <Route path="/workspace" component={NewWorkSpace} />
              <Route path="/team" component={UsPage} />
              <Route path="/contact" component={Contact} />
              <Route path="/login" component={NewLoginPage} />

              <Route path='/pruebas' component={Pruebas} />



              <Route path="/workbench2" component={Workbench} />
              <Route path="/login" component={Login} />
              <Route path="/profile" component={Profile} />

              <Route path="/Workspace2" component={Workspace} />
              
              <Route path="/abstractProfile/" component={AbstractProfile} />
            </Switch>
          </div>
        </div>
      </Router>
      </MenuProvider>
      </RosProvider>
    </ThemeProvider>
    
  );
}

export default App;
