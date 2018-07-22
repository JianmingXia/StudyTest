// This file was auto created by egg-ts-helper
// Do not modify this file!!!!!!!!!

import Base from '../../../app/model/base';
import Todo from '../../../app/model/todo';
import User from '../../../app/model/user';

declare module 'sequelize' {
  interface Sequelize {
    Base: ReturnType<typeof Base>;
    Todo: ReturnType<typeof Todo>;
    User: ReturnType<typeof User>;
  }
}
