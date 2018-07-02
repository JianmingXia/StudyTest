import React, { Component } from 'react';
import AddTodo from "../containers/AddTodo";
import VisibleTodoList from "../containers/VisibleTodoList";

class App extends Component {
  render() {
    return (
      <div className="App">
        <AddTodo/>
        <VisibleTodoList />
      </div>
    );
  }
}

export default App;
