import { Button } from '@mui/material';
import React from 'react'
import LoginForm from './LoginForm';

export default function Modal({title, text, loginEvent, cancelEvent, logedIn}) {
  return (
    <div className="modal">
        <div className="modal-content">
            <h1 className="mb-1">{title}</h1>
            <p className="mb-1 bold">{text?text:'Modal content goes here!'}</p>
            <LoginForm loginEvent={loginEvent} cancelEvent={cancelEvent} logedIn={logedIn} />
        </div>
    </div>
  );
}
