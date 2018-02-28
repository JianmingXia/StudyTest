let max_id = 2;
export default {
    namespace: 'todolist',
    state: [
        {
            id: 0,
            name: "预置任务",
            completed: false
        },
        {
            id: 1,
            name: "第二个任务",
            completed: true
        }
    ],
    reducers: {
        'change'(state, { payload: id }) {
            console.log(id);
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
        'add'(state, { payload: name }) {
            return [
                {
                    id: max_id++,
                    name: name,
                    completed: false
                },
                ...state
            ];
        },
    },
};