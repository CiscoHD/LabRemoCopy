import React, {useState, useContext} from 'react'
import { MenuContext } from '../../../context/MenuContext';

export default function Console({ros}) {
    const [isMinConsole, setIsMinConsole] = useState(false);

    const menuContext = useContext(MenuContext);

    const toggleMinConsole = () => {
        setIsMinConsole(!isMinConsole);
        menuContext.setVidCon({...menuContext.vidCon, console: isMinConsole})
    };

    return(
        <div className={`${isMinConsole?'console-container-mini':'console-container'}`}>
        {!isMinConsole && (
            <div className='console-inner'>
                <div className="console-title-container">
                <div className="console-title">Console-LabRem</div>
                <div className="minimize-console"
                    onClick={toggleMinConsole}>
                    <div className="minimizar">Minimizar</div>
                </div>
                </div>
                <div className="console-content">
                    {ros.consoleLog.map((itm,i)=>{
                        return(
                            <div className="message">
                                L:{itm.lstnr} - Msg: {itm.mssg}
                            </div>
                        )
                    })
                    }
                </div>
            </div>
        )}
        {isMinConsole && (
            <div className='console-inner'>
                <div className="console-title-container">
                <div className='console-title'>Console-LabRem</div>
                    <div className="minimize-console"
                        onClick={toggleMinConsole}>
                        <div className="minimizar">Maximizar</div>
                    </div>
                
                    </div>
            </div>

        )}
        </div>
    )
}
