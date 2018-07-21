import { Service } from 'egg';
import PasswordEncrypt from '../lib/passwordEncrypt';

export default class UserService extends Service {
  public async login(username: string, password: string) {
    const user = await this.ctx.model.User.findOne({
      where: {
        username,
        password: PasswordEncrypt(password),
      }
    });

    const { ctx } = this;
    if (!user) {
      return ctx.errResp(ctx.__('LOGIN_FAIL'));
    }
    ctx.session.current = {
      user_id: user.user_id,
      username: user.username
    };

    ctx.succResp(ctx.session.current, ctx.__('LOGIN_SUCC'));
  }
  public logout() {
    this.ctx.session.current = null;
  }
}
