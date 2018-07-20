import { Application } from 'egg';

export default (app: Application) => {
  const { controller, router } = app;

  router.post('/api/user/login', controller.user.login);

  const checkLogin = app.middleware.checkLogin();
  router.post('/api/user/logout', checkLogin, controller.user.logout);
  router.get('/api/user/info', checkLogin, controller.user.info);
};
