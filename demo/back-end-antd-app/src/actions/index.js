import {
  ADD_TODO,
  TOOGLE_TODO,
  DELETE_TODO
} from "../Constants";

let nextTodoId = 0;

export const addTodo = text => ({
  type: ADD_TODO,
  id: nextTodoId++,
  text
});

export const toggleTodo = id => ({
  type: TOOGLE_TODO,
  id: id
});

export const deleteTodo = id => ({
  type: DELETE_TODO,
  id: id
});
