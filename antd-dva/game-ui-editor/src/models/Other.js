export default {
  namespace: 'other',
  state: {
    showPropertyManage: true
  },
  reducers: {
    onToggle(state, { payload: task }) {
      return {
        ...state,
        showPropertyManage: !state.showPropertyManage
      }
    },
  }
};
