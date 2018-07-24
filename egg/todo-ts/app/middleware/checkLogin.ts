import { Context } from 'egg';

export default function checkLogin() {
  return async (ctx: Context, next: any) => {
    const user = ctx.session.current;

    if (!user || !user.valid) {
      ctx.errResp(ctx.__('NOT_LOGGED_IN'));
      return;
    }

    await next();
  };
}
