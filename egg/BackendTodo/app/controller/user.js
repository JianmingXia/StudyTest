'use strict';

const Controller = require('egg').Controller;

class UserController extends Controller {
  async login() {
    const {
      username,
      password,
    } = this.ctx.request.body;

    const response = await this.ctx.service.user.login(username, password);

    this.ctx.body = response;
  }

  async info() {
    this.ctx.body = this.ctx.response.ServerResponse.createBySuccess('', this.ctx.session.current);
  }
}

module.exports = UserController;