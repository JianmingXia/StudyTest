# React 基础学习

- ReactDOM.render
  ```
  ReactDOM.render(
    <h1>Hello, world!</h1>,
    document.getElementById('example')
  );
  ```

- JSX 语法
  ```
  var names = ['Alice', 'Emily', 'Kate'];

  ReactDOM.render(
    <div>
    {
      names.map(function (name) {
        return <div>Hello, {name}!</div>
      })
    }
    </div>,
    document.getElementById('example')
  );
  ```

  ```
  var arr = [
    <h1>Hello world!</h1>,
    <h2>React is awesome</h2>,
  ];
  ReactDOM.render(
    <div>{arr}</div>,
    document.getElementById('example')
  );
  ```

- 组件（自定义组件）
  ```
  var HelloMessage = React.createClass({
    render: function() {
      return <h1>Hello {this.props.name}</h1>;
    }
  });

  ReactDOM.render(
    <HelloMessage name="John" />,
    document.getElementById('example')
  );
  ```
  - 组件类的第一个字母必须大写
  - 组件类只能包含一个顶层标签
  - 可以通过this.props获取属性

- this.props.children
  ```
  var NotesList = React.createClass({
    render: function() {
      return (
        <ol>
        {
          React.Children.map(this.props.children, function (child) {
            return <li>{child}</li>;
          })
        }
        </ol>
      );
    }
  });

  ReactDOM.render(
    <NotesList>
      <span>hello</span>
      <span>world</span>
    </NotesList>,
    document.body
  );
  ```
  - 推荐使用React.Children.map来处理this.props.children

- PropTypes
  ```
  var MyTitle = React.createClass({
    propTypes: {
      title: React.PropTypes.string.isRequired,
    },

    render: function() {
      return <h1> {this.props.title} </h1>;
    }
  });

  var data = 123;

  ReactDOM.render(
    <MyTitle title={data} />,
    document.body
  );
  ```
  - 验证组件实例的属性是否符合要求

  ```
  var MyTitle = React.createClass({
    getDefaultProps : function () {
      return {
        title : 'Hello World'
      };
    },

    render: function() {
      return <h1> {this.props.title} </h1>;
    }
  });

  ReactDOM.render(
    <MyTitle />,
    document.body
  );
  ```
  - getDefaultProps：设置组件属性的默认值

- 获取真实的DOM节点
  ```
  var MyComponent = React.createClass({
    handleClick: function() {
      this.refs.myTextInput.focus();
    },
    render: function() {
      return (
        <div>
          <input type="text" ref="myTextInput" />
          <input type="button" value="Focus the text input" onClick={this.handleClick} />
        </div>
      );
    }
  });

  ReactDOM.render(
    <MyComponent />,
    document.getElementById('example')
  );
  ```
  - 使用 ref 属性

- this.state
  ```
  var LikeButton = React.createClass({
    getInitialState: function() {
      return {liked: false};
    },
    handleClick: function(event) {
      this.setState({liked: !this.state.liked});
    },
    render: function() {
      var text = this.state.liked ? 'like' : 'haven\'t liked';
      return (
        <p onClick={this.handleClick}>
          You {text} this. Click to toggle.
        </p>
      );
    }
  });

  ReactDOM.render(
    <LikeButton />,
    document.getElementById('example')
  );
  ```
  - 状态机

- 表单
  ```
  var Input = React.createClass({
    getInitialState: function() {
      return {value: 'Hello!'};
    },
    handleChange: function(event) {
      this.setState({value: event.target.value});
    },
    render: function () {
      var value = this.state.value;
      return (
        <div>
          <input type="text" value={value} onChange={this.handleChange} />
          <p>{value}</p>
        </div>
      );
    }
  });

  ReactDOM.render(<Input/>, document.body);
  ```
  - 通过使用onChange调用回调函数，完成同步修改

- 组件的生命周期
  - 三个状态：
    - Mounting：已插入真实 DOM
    - Updating：正在被重新渲染
    - Unmounting：已移出真实 DOM
  - 五个处理函数
    - componentWillMount()
    - componentDidMount()
    - componentWillUpdate(object nextProps, object nextState)
    - componentDidUpdate(object prevProps, object prevState)
    - componentWillUnmount()
  - 特殊状态的处理函数
    - componentWillReceiveProps(object nextProps)：已加载组件收到新的参数时调用
    - shouldComponentUpdate(object nextProps, object nextState)：组件判断是否重新渲染时调用