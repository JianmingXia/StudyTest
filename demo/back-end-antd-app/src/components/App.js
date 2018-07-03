import React, { Component } from 'react';
import AddTodo from "../containers/AddTodo";
import VisibleTodoList from "../containers/VisibleTodoList";
import FilterTodos from "./FilterTodos";

class App extends Component {
  render() {
    return (
      <div className="App">
        <AddTodo/>
        <FilterTodos />
        <VisibleTodoList />
      </div>
    );
  }
}

export default App;
