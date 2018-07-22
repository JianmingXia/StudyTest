import { Application } from 'egg';
import BaseModel from './base';

export default function Todo(app: Application) {
  const { BIGINT, TEXT, CHAR, TINYINT } = app.Sequelize;

  const modelSchema = BaseModel(app, 'todo', {
    id: {
      type: BIGINT,
      unique: true,
      autoIncrement: true,
      primaryKey: true,
      comment: '任务ID',
    },
    title: {
      type: CHAR(32),
      allowNull: false,
      comment: '任务名称',
    },
    desc: {
      type: TEXT,
      allowNull: true,
      comment: '任务描述',
    },
    creator_id: {
      type: BIGINT,
      allowNull: false,
      comment: '用户ID',
    },
    is_completed: {
      type: TINYINT,
      comment: '是否已完成',
    },
    is_deleted: {
      type: TINYINT,
      comment: '是否已被删除',
    },
    created_at: {
      type: BIGINT,
      allowNull: true,
      comment: '密码',
    },
    updated_at: {
      type: BIGINT,
      allowNull: true,
      comment: '密码',
    },
  });

  return modelSchema;
};
