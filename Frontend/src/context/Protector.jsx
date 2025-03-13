import { useStateValue } from "./StateContext";
import { useNavigate } from "react-router-dom";

export default function Protector({ children }) {
  const { user } = useStateValue();
  const navigate = useNavigate();
  //verifica si el ususario tiene un token, de no tenerlo, tiene que iniciar sesión
  return <>{!user.token ? children : navigate("/profile")}</>;
}
