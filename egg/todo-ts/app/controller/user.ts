import { Controller } from 'egg';

export default class UserController extends Controller {
  public async login() {
    const { ctx } = this;

    const { username, password } = ctx.request.body;

    await ctx.service.user.login(username, password);
  }
  public async logout() {
    this.ctx.service.user.logout();

    this.ctx.succResp();
  }
  public async info() {
    this.ctx.succResp(this.ctx.session.current);
  }
}
