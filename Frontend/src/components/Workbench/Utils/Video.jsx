import React, {useState, useContext} from 'react'
import { MenuContext } from '../../../context/MenuContext';

export default function Video() {

        const [isMinimized, setIsMinimized] = useState(false);
        const [isPlaying, setIsPlaying] = useState(false);

        const menuContext = useContext(MenuContext)

        const toggleMinimize = () => {
            setIsMinimized(!isMinimized);
            menuContext.setVidCon({...menuContext.vidCon, video: isMinimized})
        };

        const togglePlay = () => {
            setIsPlaying(!isPlaying);
        };

        return (
            <div className={`${menuContext.vidCon.console?'video-container':'video-container-console-minimized'}`}>
                {!isMinimized && (
                    <>
                        <video
                            src="URL_CAMARA"
                            controls={isPlaying}
                            autoPlay={isPlaying}
                            // style={{ width: '100%' }}
                            className={'video-player'}
                        />
                        <button onClick={togglePlay}>
                            {isPlaying ? 'Apagar' : 'Encender'}
                        </button>
                        <button onClick={toggleMinimize}>
                            {isMinimized ? 'Maximizar' : 'Minimizar'}
                        </button>
                    </>
                )}
                {isMinimized && (
                    <button onClick={toggleMinimize}>
                        Maximizar
                    </button>
                )}
            </div>
        );
}
