const Controller = require('egg').Controller;

class HomeController extends Controller {
    async index() {
        this.ctx.body = `isIOS: ${this.ctx.isIOS}`;
    }
}

module.exports = HomeController;