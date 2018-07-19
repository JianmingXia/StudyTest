'use strict';

const Controller = require('egg').Controller;

class HomeController extends Controller {
  async index() {
    const user = await this.ctx.service.user.find(5);

    this.ctx.body = user;
  }

  async login() {
      this.ctx.body = `login`;
  }

  async authCallback() {
      this.ctx.body = `authCallback`;
  }
}

module.exports = HomeController;
