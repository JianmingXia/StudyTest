import { connect } from 'react-redux';
import TodoList from '../components/TodoList';
import { toggleTodo, deleteTodo } from "../actions/index";
import { FILTER_TYPE } from "../Constants";

const getVisibleTodos = (state) => {
  switch(state.filterType) {
    case FILTER_TYPE.SHOW_COMPLETED:
      return state.todos.filter(todo => todo.completed);
    case FILTER_TYPE.SHOW_UNCOMPLETED:
      return state.todos.filter(todo => !todo.completed);
    default:
      return state.todos;
  }
};

const mapStateToProps = state => ({
  todos: getVisibleTodos(state),
})

const mapDispatchToProps = dispatch => ({
  toggleTodo: id => dispatch(toggleTodo(id)),
  deleteTodo: id => dispatch(deleteTodo(id)),
})

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(TodoList)
