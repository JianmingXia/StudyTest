import React from 'react'

const Link = ({ children, active, onClick }) => (
  <button
    disabled={active}
    onClick={onClick}
  >
    {children}
  </button>
);

export default Link;
