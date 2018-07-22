import { Controller } from 'egg';

export default class TodoController extends Controller {
  public async create() {
    const { ctx } = this;

    const { title, desc = '' } = ctx.request.body;

    if (!title) {
      ctx.errResp(ctx.__('INVALID_INPUT'));
      return;
    }
    const param = {
      title,
      desc,
      creator_id: this.ctx.session.current.user_id,
      is_completed: 0,
      is_deleted: 0,
      created_at: Math.floor(Date.now() / 1000),
      updated_at: 0,
    };

    await ctx.service.todo.create(param);
  }
  public async info() {
    const { ctx } = this;

    if (!ctx.params.id) {
      ctx.errResp(ctx.__('INVALID_INPUT'));
      return;
    }
    await ctx.service.todo.info(ctx.params.id);
  }
}
