import React from 'react';
import { connect } from 'dva';
import TodoList from '../components/TodoList';
import AddTodo from '../components/AddTodo';

const TodoListApp = ({ dispatch, todolist }) => {
    function handleChange(id) {
        dispatch({
            type: 'todolist/change',
            payload: id
        });
    }

    function handleDelete(id) {
        dispatch({
            type: 'todolist/delete',
            payload: id
        });
    }

    function handleAdd(name) {
        dispatch({
            type: 'todolist/add',
            payload: name
        });
    }

    return (
        <div>
            <h2>TodoList App</h2>
            <AddTodo onAdd={handleAdd} />
            <TodoList onChange={handleChange} onDelete={handleDelete} todolists={todolist}/>
        </div>
    );
};

// export default Products;
export default connect(({ todolist }) => ({
    todolist
}))(TodoListApp);