'use strict';

module.exports = () => {
  return async function checkLogin(ctx, next) {
    const user = ctx.session.current;

    if (!user) {
      ctx.body = ctx.response.ServerResponse.createByError(ctx.response.ResponseCode.NO_LOGIN, ctx.response.ResponseMessage.NO_LOGIN);
      return;
    }

    await next();
  };
};
