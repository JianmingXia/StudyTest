import { Application } from 'egg';
import { DefineAttributes } from 'sequelize';

export default function BaseModel(
  app: Application,
  table: string,
  attributes: DefineAttributes,
  options: object = {},
) {
  const modelSchema = app.model.define(table,
    {
      ...attributes,
    },
    {
      ...options,
      freezeTableName: true,
      underscored: true,
      timestamps: false,
    }
  );

  return modelSchema;
}
