import React from 'react';
import FilterLink from '../containers/FilterLink';
import { FILTER_TYPE } from '../Constants';

const FilterTodos = () => (
  <div>
    <span>Show: </span>
    <FilterLink filter={FILTER_TYPE.SHOW_ALL}>
      All
    </FilterLink>
    <FilterLink filter={FILTER_TYPE.SHOW_UNCOMPLETED}>
      Active
    </FilterLink>
    <FilterLink filter={FILTER_TYPE.SHOW_COMPLETED}>
      Completed
    </FilterLink>
  </div>
)

export default FilterTodos;
