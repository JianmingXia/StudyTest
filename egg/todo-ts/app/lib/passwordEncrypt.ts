import crypto = require('crypto');
import constants from './constants';

export default function encrypt(password: string) {
  const hash = crypto.createHash('md5');
  hash.update(password + constants.PASSWORD_SALT);
  return hash.digest('hex');
};
