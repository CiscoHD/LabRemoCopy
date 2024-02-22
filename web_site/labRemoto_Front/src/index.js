import React from 'react';
import ReactDOM from 'react-dom/client';
import 'bootstrap/dist/css/bootstrap.min.css';
import './index.css';
import App from './App';
import RosTest from "./pages/RosTest";

import reportWebVitals from './reportWebVitals';
import { BrowserRouter, Route } from 'react-router-dom/cjs/react-router-dom.min';
import { RosProvider } from './context/rosContext';



const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <RosProvider>
      <BrowserRouter>
      <Route exact path="/" component={App}/>
      <Route exact path="/RosTest" component={RosTest} />
      </BrowserRouter>
    </RosProvider>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
