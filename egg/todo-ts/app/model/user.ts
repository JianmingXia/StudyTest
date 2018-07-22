import { Application } from 'egg';
import BaseModel from './base';

export default function User(app: Application) {
  const { BIGINT, CHAR } = app.Sequelize;

  const modelSchema = BaseModel(app, 'user', {
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
    register_at: {
      type: BIGINT,
      allowNull: true,
      comment: '密码',
    },
    updated_at: {
      type: BIGINT,
      allowNull: true,
      comment: '密码',
    },
  },
    {
      deletedAt: false,
    });

  return modelSchema;
};
