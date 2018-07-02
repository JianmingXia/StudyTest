import {
  ADD_TODO
} from "../Constants";

let nextTodoId = 0;

export const addTodo = text => ({
  type: ADD_TODO,
  id: nextTodoId++,
  text
});
