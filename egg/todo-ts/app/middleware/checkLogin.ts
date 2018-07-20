import { Context } from 'egg';
import ResponseCode from '../lib/responseCode';

export default function checkLogin() {
  return async (ctx: Context, next: any) => {
    const user = ctx.session.current;

    if (!user) {
      ctx.errResp(ctx.__('NOT_LOGGED_IN'), ResponseCode.NO_LOGIN);
      return;
    }

    await next();
  };
}
