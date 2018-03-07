export default {
  namespace: 'restree',
  state: [
    {
      key: 0,
      title: "x",
      children: [{
          key: 3,
          title: "华或多或少"
        },
        {
          key: 4,
          title: "大大师傅"
        }
      ]
    },
    {
      key: 1,
      title: "sfddssdfds"
    },
    {
      key: 2,
      title: "啦啦啦啦啦"
    },
    {
      key: 1,
      title: "sfddssdfds"
    },
    {
      key: 2,
      title: "啦啦啦啦啦"
    },
    {
      key: 1,
      title: "sfddssdfds"
    },
    {
      key: 2,
      title: "啦啦啦啦啦"
    },
    {
      key: 1,
      title: "sfddssdfds"
    },
    {
      key: 2,
      title: "啦啦啦啦啦"
    }
  ],
  reducers: {
    drop(state, { payload: task }) {
      return [
        {
          key: 0,
          title: "新的结构",
          children: [{
              key: 3,
              title: "华或多或少"
            },
            {
              key: 4,
              title: "大大师傅"
            },
            {
              key: 2,
              title: "啦啦啦啦啦"
            }
          ]
        },
        {
          key: 1,
          title: "重置过顺序啦"
        }
      ]
    },
  }
};
