import { Controller } from 'egg';

export default class RedisController extends Controller {
  // 字符串类型
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

    ctx.succResp({ [key]: value });
  }
  // hash类型
  public async setHash() {
    const { ctx, app } = this;

    const hash_name = ctx.params.hash_name;
    const hash_field = ctx.params.hash_field;

    const { value } = ctx.request.body;

    await app.redis.hset(hash_name, hash_field, hash_field + value);

    ctx.succResp({
      [hash_name]: await app.redis.hgetall(hash_name)
    });
  }
}
