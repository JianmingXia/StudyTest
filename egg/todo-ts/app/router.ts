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

  // redis test
  // String
  router.get('/api/redis/:key', controller.redis.get);
  router.post('/api/redis/:key', controller.redis.set);

  // hash
  router.post('/api/redis/hash/:hash_name/hash_field/:hash_field', controller.redis.setHash);
  router.delete('/api/redis/hash/:hash_name/hash_field/:hash_field', controller.redis.deleteHash);
  router.get('/api/redis/hash/keys/:hash_name', controller.redis.getHashKeys);

  // list
  router.post('/api/redis/list/:list_name', controller.redis.lpush);
  router.delete('/api/redis/list/:list_name/list_value/:list_value', controller.redis.deleteListValue);

  // set
  router.post('/api/redis/set/:set_name', controller.redis.sadd);
};
