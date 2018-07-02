import React from 'react'
import Todo from './Todo'

const TodoList = ({ todos }) => (
  <ul>
    {todos.map((todo, index) => (
      <Todo key={index} {...todo} />
    ))}
  </ul>
)

export default TodoList
