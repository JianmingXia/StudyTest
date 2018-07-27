import { Controller } from 'egg';

export default class RedisController extends Controller {
  // String START
  public async get() {
    const { ctx, app } = this;

    const redis = ctx.params.key;

    ctx.succResp({
      redis: await app.redis.get(redis)
    });
  }
  public async set() {
    const { ctx, app } = this;

    const key = ctx.params.key;
    const { value } = ctx.request.body;

    await app.redis.set(key, value);

    ctx.succResp({ [key]: value });
  }
  // String END
  // Hash START
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
  public async deleteHash() {
    const { ctx, app } = this;

    const hash_name = ctx.params.hash_name;
    const hash_field = ctx.params.hash_field;

    await app.redis.hdel(hash_name, hash_field);

    ctx.succResp({
      [hash_name]: await app.redis.hgetall(hash_name)
    });
  }
  public async getHashKeys() {
    const { ctx, app } = this;

    const hash_name = ctx.params.hash_name;

    ctx.succResp({
      [hash_name]: await app.redis.hkeys(hash_name)
    });
  }
  // Hash END
  // List START
  public async lpush() {
    const { ctx, app } = this;

    const list_name = ctx.params.list_name;

    const { value } = ctx.request.body;

    await app.redis.lpushx(list_name, value);

    ctx.succResp({
      [list_name]: await app.redis.lrange(list_name, 0, -1)
    });
  }
  public async deleteListValue() {
    const { ctx, app } = this;

    const list_name = ctx.params.list_name;
    const list_value = ctx.params.list_value;

    await app.redis.lrem(list_name, 0, list_value);

    ctx.succResp({
      [list_name]: await app.redis.lrange(list_name, 0, -1)
    });
  }
  // List END
  // Set START
  public async sadd() {
    const { ctx, app } = this;

    const set_name = ctx.params.set_name;

    const { value } = ctx.request.body;

    await app.redis.sadd(set_name, value);

    ctx.succResp({
      [set_name]: await app.redis.smembers(set_name)
    });
  }
  // Set END
  // common START
  public async delete() {
    const { ctx, app } = this;

    const key_name = ctx.params.key_name;

    await app.redis.del(key_name);

    ctx.succResp({});
  }
  // common END
}
