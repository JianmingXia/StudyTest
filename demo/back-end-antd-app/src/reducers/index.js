import {
  combineReducers
} from 'redux';
import todos from './todos';
import filterType from './filter';

export default combineReducers({
  todos,
  filterType
})
