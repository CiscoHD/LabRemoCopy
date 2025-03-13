export const ip_server = import.meta.env.VITE_LABREMOTO_SERV;

export const initialState = {
  //Datos del usuario
  user: {
    username: "",
    token: "",
  },

  // Valores iniciales al momento de escoger plantilla
  university: "notSelected",
  school: "notSelected",
  career: "notSelected",
  subject: "notSelected",
  practica: "notSelected",

  //
  url_url: `http://${ip_server}:8000`,

  base_url: `http://${ip_server}:8000/api/`,
};

export const actionTypes = {
  SET_USER: "SET_USER",
  SET_UNIV: "SET_UNIV",
  SET_SCHOOL: "SET_SCHOOL",
  SET_CAREER: "SET_CAREER",
  SET_SUBJECT: "SET_SUBJECT",
  SET_PRACTICA: "SET_PRACTICA",
};

const reducer = (state, action) => {
  switch (action.type) {
    case actionTypes.SET_USER:
      return {
        ...state,
        user: {
          ...state.user,
          username: action.name,
          token: action.token,
        },
      };
    case actionTypes.SET_UNIV:
      return {
        ...state,
        university: action.v,
      };
    case actionTypes.SET_SCHOOL:
      return {
        ...state,
        school: action.v,
      };
    case actionTypes.SET_CAREER:
      return {
        ...state,
        career: action.v,
      };
    case actionTypes.SET_SUBJECT:
      return {
        ...state,
        subject: action.v,
      };
    case actionTypes.SET_PRACTICA:
      return {
        ...state,
        practica: action.v,
      };
    default:
      return state;
  }
};

export default reducer;
