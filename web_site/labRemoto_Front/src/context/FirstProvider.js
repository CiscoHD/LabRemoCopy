import { createContext, useState } from "react";

export const FirstContext = createContext();

const FirstProvider = (props) => {
    const [university,setUniversity] = useState(false);
    const [school,setSchool] = useState(false);
    const [career,setCareer] = useState(false);

    const enableSchool = () =>{
        setUniversity(true);
    };

    const enableCareer = () => {
        setCareer(true);
    };

    return(
        <FirstContext.Provider value={{university,school,career,
        enableSchool,enableCareer}}>
            {props.children}
        </FirstContext.Provider>
    );
};

export default FirstProvider;