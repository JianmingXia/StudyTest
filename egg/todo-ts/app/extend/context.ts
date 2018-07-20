import { Context } from 'egg';
import ResponseCode from '../lib/responseCode';

export default {
  succResp(this: Context, data?: object, msg = ''): void {
    if (data) {
      this.body = { code: ResponseCode.SUCC, msg, data };
    } else {
      this.body = { code: ResponseCode.SUCC, msg };
    }
  },
  errResp(
    this: Context,
    msg: string,
    code = ResponseCode.ERROR,
    data?: object
  ): void {
    if (data) {
      this.body = { code, msg, data };
    } else {
      this.body = { code, msg };
    }
  }
};
