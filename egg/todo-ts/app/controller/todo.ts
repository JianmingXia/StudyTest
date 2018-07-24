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
      updated_at: 0
    };

    await ctx.service.todo.create(param);
  }
  public async info() {
    const { ctx } = this;
    const todoId = ctx.params.id;
    if (!todoId) {
      ctx.errResp(ctx.__('INVALID_INPUT'));
      return;
    }
    await ctx.service.todo.info({
      id: todoId,
      creator_id: ctx.session.current.user_id
    });
  }
  public async update() {
    const { ctx } = this;
    const todoId = ctx.params.id;
    if (!todoId) {
      ctx.errResp(ctx.__('INVALID_INPUT'));
      return;
    }

    const { title, desc = '' } = ctx.request.body;
    const param = { title, desc, updated_at: Math.floor(Date.now() / 1000) };

    const isUpdated = await ctx.service.todo.update(param, {
      id: todoId,
      creator_id: ctx.session.current.user_id
    });

    if (isUpdated) {
      await ctx.service.todo.info({
        id: todoId,
        creator_id: ctx.session.current.user_id
      });
    }
  }
  public async delete() {
    const { ctx } = this;
    const todoId = ctx.params.id;
    if (!todoId) {
      ctx.errResp(ctx.__('INVALID_INPUT'));
      return;
    }
    await ctx.service.todo.delete({
      id: todoId,
      creator_id: ctx.session.current.user_id
    });
  }
}
