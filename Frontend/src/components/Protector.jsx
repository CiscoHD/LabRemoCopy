import { useStateValue } from "@/context/StateContext";
import { Navigate } from "react-router-dom";

export default function Protector({ children }) {
  const [{ base_url, user }, dispatch] = useStateValue();

  return <>{!user.token ? children : <Navigate to={"/login"} />}</>;
}
