import request from '../utils/request';

export function addTask(params) {
  return request('/api/addTask', {
    method: 'POST',
    body: params
  });
}
