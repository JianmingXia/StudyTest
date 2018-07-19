'use strict';

exports.security = {
  csrf: {
    enable: false,
  },
};

exports.mysql = {
  client: {
    host: '10.0.3.105',
    port: '3306',
    user: 'doc',
    password: 'doc',
    database: 'ryoma_todo',
  },
  app: true,
  agent: false,
};

module.exports = appInfo => {
  const config = exports;

  // use for cookie sign key, should change to your own and keep security
  config.keys = appInfo.name + '_1531994910962_5234';

  // add your config here
  config.middleware = [];

  return config;
};
