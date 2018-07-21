import { Application } from 'egg';

export default function User(app: Application) {
  const { BIGINT, CHAR } = app.Sequelize;

  const modelSchema = app.model.define('user', {
    user_id: {
      type: BIGINT,
      unique: true,
      primaryKey: true,
      allowNull: false,
      comment: '用户ID',
    },
    username: {
      type: CHAR(32),
      unique: true,
      allowNull: false,
      comment: '用户名',
    },
    password: {
      type: CHAR(32),
      allowNull: false,
      comment: '密码',
    },
  },
    {
      freezeTableName: true,
      deletedAt: false,
      underscored: true,
      createdAt: 'register_at',
    });

  return modelSchema;
};
