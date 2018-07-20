'use strict';

const Service = require('egg').Service;

class UserService extends Service {
  async login(username, password) {
    const user = await this.app.mysql.get('user', {
      username,
      password,
    });

    if (!user) {
      return this.ctx.response.ServerResponse.createByError(this.ctx.response.ResponseMessage.LOGIN_FAIL, this.ctx.response.ResponseCode.LOGIN_FAIL);
    }

    this.ctx.session.current = { user_id: user.user_id, username: user.username };

    return this.ctx.response.ServerResponse.createBySuccess(this.ctx.response.ResponseMessage.LOGIN_SUCC);
  }
}

module.exports = UserService;
