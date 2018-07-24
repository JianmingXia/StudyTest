import { Application } from 'egg';

export default (app: Application) => {
  const { controller, router } = app;

  router.post('/api/user/login', controller.user.login);

  const checkLogin = app.middleware.checkLogin();
  router.post('/api/user/logout', checkLogin, controller.user.logout);
  router.get('/api/user/info', checkLogin, controller.user.info);

  router.post('/api/todo', checkLogin, controller.todo.create);
  router.get('/api/todo/:id', checkLogin, controller.todo.info);
  router.patch('/api/todo/:id', checkLogin, controller.todo.update);
  router.delete('/api/todo/:id', checkLogin, controller.todo.delete);
};
