const Controller = require('egg').Controller;

class HomeController extends Controller {
    async index() {
        this.ctx.body = `Now request isIOS: ${this.ctx.isIOS}`;
    }
}

module.exports = HomeController;