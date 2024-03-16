import React from 'react';
import ReactDOM from "react-dom/client";
import { BrowserRouter } from 'react-router-dom';
import 'bootstrap/dist/css/bootstrap.min.css';
import './index.css';
import App from './App';

import reportWebVitals from './reportWebVitals';
import { StateProvider } from './context/StateContext';
import reducer, { initialState } from './components/reducer';
import { RosProvider } from './context/RosContext';



const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <StateProvider initialState={initialState} reducer={reducer}>
      {/* <RosProvider> */}
        <BrowserRouter>
          <App />
        </BrowserRouter>
      {/* </RosProvider> */}
    </StateProvider>
  </React.StrictMode>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
