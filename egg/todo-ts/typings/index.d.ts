declare module 'egg' {
  interface Application {
    mysql: any;
  }

  export interface Router {
    get(name: string, path: string | RegExp, ...middleware: any[]): Router;
    get(path: string | RegExp, ...middleware: any[]): Router;
    post(name: string, path: string | RegExp, ...middleware: any[]): Router;
    post(path: string | RegExp, ...middleware: any[]): Router;
  }
}