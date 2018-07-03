import {
  SET_FILTER_TYPE,
  FILTER_TYPE
} from "../Constants";

const filterType = (state = FILTER_TYPE.SHOW_ALL, action) => {
  switch (action.type) {
    case SET_FILTER_TYPE:
      return action.filterType;
    default:
      return state
  }
}

export default filterType;
