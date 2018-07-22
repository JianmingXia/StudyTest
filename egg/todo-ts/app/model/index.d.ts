import User from './user'
import Todo from './todo'
import { Model, SequelizeStatic, Sequelize } from 'sequelize'

declare module 'egg' {
  interface Application {
    Sequelize: SequelizeStatic
    model: Sequelize
  }

  // 拓展自有 model 的声明
  interface Context {
    model: {
      User: Model<User, {}>;
      Todo: Model<Todo, {}>;
    }
  }
}
