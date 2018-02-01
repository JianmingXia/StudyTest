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
xhr.open('POST', 'http://local.quqi.com/auth/company/create', true);
xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
xhr.send('company_name=新的团队版&edition_type=1&ignore_copy_doc=1');

var xhr = new XMLHttpRequest();

//#region
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
xhr.open('POST', 'http://local.quqi.com//api/service/getServiceType', true);
xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
xhr.send('quqi_id=12163');
//#endregion

