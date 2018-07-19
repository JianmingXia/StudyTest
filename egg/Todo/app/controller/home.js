'use strict';

const Controller = require('egg').Controller;

class HomeController extends Controller {
  async index() {
    this.ctx.body = `hi, egg: ${this.app.config.keys}`;
  }

  async login() {
      this.ctx.body = `login`;
  }

  async authCallback() {
      this.ctx.body = `authCallback`;
  }
}

module.exports = HomeController;
