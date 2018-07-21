# hackernews-async-ts

[Hacker News](https://news.ycombinator.com/) showcase using typescript && egg

## QuickStart

### Development

```bash
$ npm i
$ npm run dev
$ open http://localhost:7001/
```

Don't tsc compile at development mode, if you had run `tsc` then you need to `npm run clean` before `npm run dev`.

### Deploy

```bash
$ npm run tsc
$ npm start
```

### Npm Scripts

- Use `npm run lint` to check code style
- Use `npm test` to run unit test
- se `npm run clean` to clean compiled js at development mode once

### Requirement

- Node.js 8.x
- Typescript 2.8+

## 问题
### 对象关系模型（Sequelize）
之前使用了egg-mysql来直接查询数据库，直接操作数据库、拼接SQL语句，感觉后期这部分内容会很难维护，并且egg-mysql自身好像也没有方便拓展的方法（也有可能是我没有发现），目前使用egg-sequelize，最开始按照官网模板搭了个架子，开始遇到问题了：
- 数据表名称默认是复数（使用freezeTableName冻结表名，默认与model名称对应）
- 会莫名引入createdAt/created_at, updatedAt/updated_at字段（也可进行配置）
- 上面说的createdAt/created_at会被underscore属性影响
- 默认还要有主键id字段，我使用的表叫user_id，添加上primary_key属性即可
以上是遇到的问题，主要原因还是由于没有时间详看文档，文档里也都有解决方法。

- 参考如下：
  - http://docs.sequelizejs.com/
  - https://github.com/eggjs/egg-sequelize
  - https://github.com/atzcl/z