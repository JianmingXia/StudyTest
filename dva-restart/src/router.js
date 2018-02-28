import React from 'react';
import { Router, Route, Switch } from 'dva/router';
// import IndexPage from './routes/IndexPage';
import Products from './routes/Products';
import EntryPage from './routes/EntryPage';
import TodoList from './routes/TodoList';

function RouterConfig({ history }) {
  return (
    <Router history={history}>
      <Switch>
        {/* <Route path="/" exact component={IndexPage} /> */}
        <Route path="/" exact component={EntryPage} />
        <Route path="/0" exact component={Products} />
        <Route path="/1" exact component={TodoList} />
      </Switch>
    </Router>
  );
}

export default RouterConfig;
