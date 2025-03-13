import { Routes, Route, Navigate } from "react-router-dom";
import { MenuProvider } from "@/context/MenuContext";
import { RosProvider } from "@/context/RosContext";

import "@/App.css";

import NavBar from "./pages/NavBar/NavBar.jsx";

import Home from "@/pages/Home/Home";

import InitProyect from "@/pages/initProject/InitProject";
import PracticalTemplate from "@/components/InitProject/PracticalTemplate/main";
import TipoTarjeta from "@/components/InitProject/BoardType/main";
import SavedSession from "@/components/InitProject/SavedSession/main";

import UsPage from "@/pages/UsPage/UsPage";
import Contact from "@/pages/ReachUs/Contact";
import MainProfile from "@/pages/Profile/main";

import MainWorkSpace from "@/components/Project/MainWorkSpace";
import { LogIn } from "@/components/Profile/LogIn/logIn";

const App = () => {
  return (
    <RosProvider>
      <MenuProvider>
        <NavBar />
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/lab" element={<InitProyect />}>
            <Route index element={<Navigate to="nuevo" />} />
            <Route path="nuevo" element={<TipoTarjeta />} />
            <Route path="sesion" element={<SavedSession />} />
            <Route
              path="plantilla"
              element={<PracticalTemplate handler={undefined} />}
            />
          </Route>
          <Route path="/lab/workbench" element={<MainWorkSpace />} />
          <Route path="/us" element={<UsPage />} />
          <Route path="/contact" element={<Contact />} />
          <Route path="/profile" element={<MainProfile />} />

          <Route path="/login" element={<LogIn />} />

          <Route path="/*" element={<Navigate to="/" />} />
        </Routes>
      </MenuProvider>
    </RosProvider>
  );
};

export default App;
