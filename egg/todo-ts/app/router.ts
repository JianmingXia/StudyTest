import { Application } from 'egg';

export default (app: Application) => {
  const { controller, router } = app;

  router.post('/api/user/login', controller.user.login);

  const checkLogin = app.middleware.checkLogin();
  router.get('/api/user/info', checkLogin, controller.user.info);
};
