'use strict';

/**
 * @param {Egg.Application} app - egg application
 */
module.exports = app => {
  const { router, controller } = app;
  router.get('/', controller.home.index);
  
  // 鉴权成功后的回调页面
  router.get('/authCallback', controller.home.authCallback);

  // 渲染登录页面，用户输入账号密码
  router.get('/login', controller.home.login);
  // 登录校验
  router.post('/login', app.passport.authenticate('local', {
      successRedirect: '/authCallback',
      failureRedirect: '/login'
  }));
};
