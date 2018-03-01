import { addTask } from '../services/api';

export default {
    namespace: 'todolist',
    state: [],
    effects: {
        *addTask({ payload }, { call, put }) {
            const response = yield call(addTask, payload);

            yield put({
                type: 'add',
                payload: response.data
            });
        },
    },
    reducers: {
        'change'(state, { payload: id }) {
            return state.map((item) => {
                if (item.id === id) {
                    return { ...item, completed: !item.completed };
                } else {
                    return item;
                }
            })
        },
        'delete'(state, { payload: id }) {
            return state.filter(item => item.id !== id);
        },
        'add'(state, { payload }) {
            console.log(payload);
            return [
                payload,
                ...state
            ];
        },
    },
};