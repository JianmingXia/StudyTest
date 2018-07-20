import { Context } from 'egg';
import ResponseCode from '../lib/responseCode';
import ResponseMessage from '../lib/responseMessage';

export default function checkLogin() {
  return async (ctx: Context, next: any) => {
    const user = ctx.session.current;

    if (!user) {
      ctx.errResp(ResponseMessage.NO_LOGIN, ResponseCode.NO_LOGIN);
      return;
    }

    await next();
  };
}
