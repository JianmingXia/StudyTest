'use strict';

const {
  SUCCESS,
  ERROR,
} = require('./responseCode');

module.exports = class ServerResponse {
  constructor(code, msg = '', data = {}) {
    this.code = code;
    this.msg = msg;
    this.data = data;
  }

  isSuccess() {
    return this.code === SUCCESS;
  }

  getData() {
    return this.data;
  }

  static createBySuccess(msg = '', data = {}) {
    return new ServerResponse(SUCCESS, msg, data);
  }

  static createByError(msg, code = ERROR) {
    return new ServerResponse(code, msg);
  }
};
