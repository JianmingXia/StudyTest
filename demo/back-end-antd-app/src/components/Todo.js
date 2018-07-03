import React from 'react'

const Todo = ({ completed, text, onClick, onDelete }) => (
  <li style={{
        width: "400px"
      }}>
    <span
      onClick={onClick}
      style={{
      textDecoration: completed ? 'line-through' : 'none',
      width: "350px"
    }}>
      {text}
    </span>

    <button onClick={onDelete}
      style={{
        width: "50px",
        float: "right"
      }}
    >
      x
    </button>
  </li>
);

export default Todo
