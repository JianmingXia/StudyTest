var quqi_ids = "809866,472711";
var quqi_id_arr = quqi_ids.split(",");

var length = quqi_id_arr.length;
for (var i = 0; i < length; i++) {
    var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4) {
            console.log(xhr);
            if ((xhr.status >= 200 && xhr.status < 300) || xhr.status == 304) {
                // 成功：处理 xhr.responseText 
            } else {
                // 失败
            }
        }
    };
    xhr.open('POST', '/api/notify/system_notify_send', true);
    xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
    xhr.send('receiver_type=team&receiver_desc=统一发送数据可忽略此消息&quqi_id=' + quqi_id_arr[i] + '&title=这是标题&content=这是内容&url=');
}
