'use strict';

module.exports = appInfo => {
    const config = exports = {};

    // use for cookie sign key, should change to your own and keep security
    config.keys = appInfo.name + '_1531980802737_3533';

    // add your config here
    config.middleware = [];

    config.security = {
        csrf: {
            enable: false,
        },
    };
     
    config.mysql = {
        // 单数据库信息配置
        client: {
            // host
            host: '10.0.3.105',
            // 端口号
            port: '3306',
            // 用户名
            user: 'doc',
            // 密码
            password: 'doc',
            // 数据库名
            database: 'ryoma_test',
        },
        // 是否加载到 app 上，默认开启
        app: true,
        // 是否加载到 agent 上，默认关闭
        agent: false,
    };

    return config;
};