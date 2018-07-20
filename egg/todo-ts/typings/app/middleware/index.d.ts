// This file was auto created by egg-ts-helper
// Do not modify this file!!!!!!!!!

import CheckLogin from '../../../app/middleware/checkLogin';

declare module 'egg' {
  interface IMiddleware {
    checkLogin: typeof CheckLogin;
  }
}
