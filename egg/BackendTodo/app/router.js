'use strict';

/**
 * @param {Egg.Application} app - egg application
 */
module.exports = app => {
  const { router, controller } = app;

  router.post('/api/user/login', controller.user.login);

  const checkLogin = app.middleware.checkLogin();
  router.get('/api/user/info', checkLogin, controller.user.info);
};
