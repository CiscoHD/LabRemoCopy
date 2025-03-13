import { useState } from "react";
import styles from "./CSS/console.module.css";

export default function ConsoleOrVideo({
  title = "Sin título",
  icon = "bi bi-circle-fill",
  console = false,
  video = false,
}) {
  const [isMinimized, setIsMinimized] = useState(true);
  const [isPlaying, setIsPlaying] = useState(false);

  const toggleMinimize = () => {
    setIsMinimized(!isMinimized);
  };
  const togglePlaying = () => {
    setIsPlaying(!isPlaying);
  };

  const guideWordConsole = "Status";
  const guideWordVideo = video ? (
    <i className={`bi bi-fullscreen${isMinimized ? "" : "-exit"}`} />
  ) : null;

  return (
    <div className={`${styles.content}`}>
      <div
        className={`${styles.title} ${isMinimized ? styles.minimized_title : ""} ${styles.fullScreenTitle}`}
      >
        {title}
        <div className={`${styles.status_info}`}>
          <div className={`${styles.guideWord}`} onClick={toggleMinimize}>
            {console ? guideWordConsole : guideWordVideo}
          </div>
          <i
            className={`${icon} ${
              console ? styles.done : isPlaying ? styles.wrong : styles.doing
            }`}
            onClick={console ? toggleMinimize : togglePlaying}
          />
        </div>
      </div>
      {console && (
        <div
          className={`${styles.output} ${!isMinimized ? styles.open_output : styles.close} `}
        >
          {!isMinimized && (
            <>
              {console.consoleLog.map((itm, i) => (
                <div key={i}>
                  L: {itm.lstnr} - Msg: {itm.mssg}
                </div>
              ))}
            </>
          )}
        </div>
      )}
      {video && (
        <div
          className={`${styles.output} ${!isMinimized ? styles.open_output : styles.close} `}
        >
          {!isMinimized && (
            <video
              src="URL_CAMARA"
              controls={isPlaying}
              autoPlay={isPlaying}
              style={{ height: "100%" }}
            />
          )}
        </div>
      )}
    </div>
  );
}
