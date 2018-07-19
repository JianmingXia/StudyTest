'use strict';

exports.security = {
  csrf: {
    enable: false,
  },
};

module.exports = appInfo => {
  const config = exports;

  config.keys = appInfo.name + '_1531994910962_5234';

  return config;
};
