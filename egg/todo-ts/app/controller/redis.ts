import { Controller } from 'egg';

export default class RedisController extends Controller {
  public async get() {
    const { ctx, app } = this;

    const redis = ctx.params.key;

    ctx.succResp({ redis: await app.redis.get(redis) });
  }
  public async set() {
    const { ctx, app } = this;

    const key = ctx.params.key;
    const { value } = ctx.request.body;

    await app.redis.set(key, value);

    ctx.succResp({ key: value });
  }
}
