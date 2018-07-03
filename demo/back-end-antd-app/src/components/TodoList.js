import React from 'react'
import Todo from './Todo'

const TodoList = ({ todos, toggleTodo, deleteTodo }) => (
  <ul>
    {todos.map((todo, index) => (
      <Todo key={index} {...todo}
        onClick={() => toggleTodo(todo.id)} onDelete={() => deleteTodo(todo.id)} />
    ))}
  </ul>
)

export default TodoList
