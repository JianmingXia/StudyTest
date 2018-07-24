// This file was auto created by egg-ts-helper
// Do not modify this file!!!!!!!!!

import Redis from '../../../app/controller/redis';
import Todo from '../../../app/controller/todo';
import User from '../../../app/controller/user';

declare module 'egg' {
  interface IController {
    redis: Redis;
    todo: Todo;
    user: User;
  }
}
