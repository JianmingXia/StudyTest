import { Service } from 'egg';

interface CreateTodo {
  title: string;
  desc: string;
  creator_id: number;
  is_completed: number;
  is_deleted: number;
  created_at: number;
  updated_at: number;
}

export default class TodoService extends Service {
  public async create(param: CreateTodo) {
    const todo = await this.ctx.model.Todo.create({
      ...param
    });

    if (todo) {
      this.ctx.succResp({
        id: todo.id,
        title: todo.title,
        desc: todo.desc,
        creator_id: todo.creator_id,
        is_completed: todo.is_completed,
        is_deleted: todo.is_deleted,
        created_at: todo.created_at,
        updated_at: todo.updated_at
      });
    } else {
      this.ctx.errResp(this.ctx.__('CREATE_TODO_FAIL'));
    }
  }
  public async info(options: {}) {
    const todo = await this.ctx.model.Todo.findOne({
      where: {
        ...options
      }
    });

    if (!todo) {
      this.ctx.errResp(this.ctx.__('TODO_NOT_FOUND'));
    } else if (todo.is_deleted === 1) {
      this.ctx.errResp(this.ctx.__('TODO_DELETED'));
    } else {
      this.ctx.succResp({
        id: todo.id,
        title: todo.title,
        desc: todo.desc,
        creator_id: todo.creator_id,
        is_completed: todo.is_completed,
        is_deleted: todo.is_deleted,
        created_at: todo.created_at,
        updated_at: todo.updated_at
      });
    }
  }
  public async update(values: {}, options: {}) {
    const todo = await this.ctx.model.Todo.update(values, {
      where: {
        ...options,
        is_deleted: 0
      }
    });

    if (todo[0] === 0) {
      this.ctx.errResp(this.ctx.__('TODO_NOT_FOUND'));
      return false;
    } else {
      return true;
    }
  }
  public async delete(options: {}) {
    const todo = await this.ctx.model.Todo.update(
      {
        is_deleted: 1,
        deleted_at: Math.floor(Date.now() / 1000)
      },
      { where: { ...options, is_deleted: 0 } }
    );

    if (todo[0] === 0) {
      this.ctx.errResp(this.ctx.__('TODO_NOT_FOUND_OR_TODO_HAD_DELETED'));
    } else {
      this.ctx.succResp({});
    }
  }
}
