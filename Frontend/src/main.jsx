import ReactDOM from "react-dom/client";
import App from "@/App.jsx";
import { BrowserRouter } from "react-router-dom";

import { StateProvider } from "@/context/StateContext";
import reducer, { initialState } from "@/context/Reducer/reducer";

// @ts-ignore
ReactDOM.createRoot(document.getElementById("root")).render(
  <BrowserRouter>
    {/* <React.StrictMode> */}
    <StateProvider reducer={reducer} initialState={initialState}>
      <App />
    </StateProvider>
    {/* </React.StrictMode> */}
  </BrowserRouter>
);
