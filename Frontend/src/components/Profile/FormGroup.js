import React from 'react'

export default function FormGroup({
    label,
    type,
    placeholder,
    disabled,
    value,
    onChange,
    reference
}) {
  return (
    <div className="form-group">
    <label>{label}</label>
    <input
      type={type}
      className='form-control'
      placeholder={placeholder}
      disabled={disabled}
      value={value}
      onChange={onChange}
      ref={reference}
    />
  </div>
  )
}
