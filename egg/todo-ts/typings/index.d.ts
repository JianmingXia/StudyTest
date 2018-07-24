declare module 'egg' {
  interface Application {
    Sequelize: SequelizeStatic;
    model: Sequelize;
  }

  export interface Router {
    get(name: string, path: string | RegExp, ...middleware: any[]): Router;
    get(path: string | RegExp, ...middleware: any[]): Router;
    post(name: string, path: string | RegExp, ...middleware: any[]): Router;
    post(path: string | RegExp, ...middleware: any[]): Router;
    patch(path: string | RegExp, ...middleware: any[]): Router;
    delete(path: string | RegExp, ...middleware: any[]): Router;
  }

  interface CurrentUser {
    [key: string]: any;
    user_id: number;
    username: string;
  }

  interface Session {
    [key: string]: any;
    current: CurrentUser
  }

  export interface Context {
    session: Session;
  }
}
