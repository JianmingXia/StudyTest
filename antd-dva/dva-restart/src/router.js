import React from 'react';
import { Router, Route, Switch, BrowserRouter } from 'dva/router';

import IndexPage from './routes/IndexPage';
import Products from './routes/Products';
import EntryPage from './routes/EntryPage';
import TodoList from './routes/TodoList';

function RouterConfig({ history }) {
  return (
    <Router history={history}>
      <Switch>
        <Route path="/" exact component={EntryPage} />
        <Route path="/0" exact component={IndexPage} />
        <Route path="/1" exact component={Products} />
        <Route path="/2" exact component={TodoList} />
        <BrowserRouter basename="/2" />
      </Switch>
    </Router>
    // <BrowserRouter
    //   forceRefresh={false}
    // >
    //   <Switch>
    //     <Route path="/" exact component={EntryPage} />
    //     <Route path="/0" exact component={Products} />
    //     <Route path="/1" exact component={TodoList} />
    //   </Switch>
    // </BrowserRouter>
  );
}

export default RouterConfig;
