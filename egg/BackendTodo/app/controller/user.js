'use strict';

const Controller = require('egg').Controller;

class UserController extends Controller {
  async login() {
    const {
      username,
      password,
    } = this.ctx.request.body;

    const response = await this.ctx.service.user.login(username, password);

    if (response.isSuccess()) {
      this.ctx.session.currentUser = response.getData();
    }

    this.ctx.body = response;
  }
}

module.exports = UserController;