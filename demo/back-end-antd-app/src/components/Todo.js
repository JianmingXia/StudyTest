import React from 'react'

const Todo = ({ completed, text }) => (
  <li
    style={{
      textDecoration: completed ? 'line-through' : 'none'
    }}
  >
    {text}
  </li>
);

export default Todo
