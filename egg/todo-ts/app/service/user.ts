import { Service } from 'egg';
import ResponseMessage from '../lib/responseMessage';

export default class UserService extends Service {
  public async login(username: string, password: string) {
    const user = await this.app.mysql.get('user', {
      username,
      password
    });

    if (!user) {
      return this.ctx.errResp(ResponseMessage.LOGIN_FAIL);
    }
    this.ctx.session.current = {
      user_id: user.user_id,
      username: user.username
    };

    this.ctx.succResp({}, ResponseMessage.LOGIN_SUCC);
  }
}

// class UserService extends Service {
//   async login(username, password) {
//     const user = await this.app.mysql.get('user', {
//       username,
//       password
//     });

//     if (!user) {
//       return this.ctx.response.ServerResponse.createByError(
//         this.ctx.response.ResponseMessage.LOGIN_FAIL,
//         this.ctx.response.ResponseCode.LOGIN_FAIL
//       );
//     }

//     this.ctx.session.current = {
//       user_id: user.user_id,
//       username: user.username
//     };

//     return this.ctx.response.ServerResponse.createBySuccess(
//       this.ctx.response.ResponseMessage.LOGIN_SUCC
//     );
//   }
// }
