import { EggAppConfig, EggAppInfo, PowerPartial } from 'egg';

// for config.{env}.ts
export type DefaultConfig = PowerPartial<EggAppConfig & BizConfig>;

// app special config scheme
export interface BizConfig {
  sourceUrl: string;
}

export default (appInfo: EggAppInfo) => {
  const config = {} as PowerPartial<EggAppConfig> & BizConfig;

  // use for cookie sign key, should change to your own and keep security
  config.keys = appInfo.name + '_1532076184437_5565';

  // add your config here
  config.middleware = [];

  config.security = {
    csrf: {
      enable: false
    }
  };

  config.sequelize = {
    dialect: 'mysql', // support: mysql, mariadb, postgres, mssql
    database: 'todo',
    host: 'localhost',
    port: '3306',
    username: 'root',
    password: '',
  };

  config.i18n = {
    defaultLocale: 'zh-CN',
  };

  config.redis = {
    client: {
      port: 6379,
      host: '127.0.0.1',
      password: '123',
      db: 0
    }
  };

  return config;
};
