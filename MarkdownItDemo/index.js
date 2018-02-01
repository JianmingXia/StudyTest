var MarkdownIt = require('markdown-it'),
    md = new MarkdownIt();

var files = [
    "数据库更新顺序",
    "前端发布注意事项",
    "内网文档系统升级策略",
    "quqi_approval",
    "quqi_auth",
    "quqi_auth_log",
    "quqi_auth_secret_code",
    "quqi_center",
    "quqi_center_secret_key",
    "quqi_chat",
    "quqi_document_log",
    "quqi_document1",
    "quqi_log",
    "quqi_money",
    "quqi_notify",
    "quqi_push",
    "quqi_session",
    "quqi_updown"
];
var length = files.length;
var input_path_name = "input";
var out_path_name = "output";

for (var i = 0; i < length; i++)
{
    var rf = require("fs");
    var data = rf.readFileSync(__dirname + "/" +  input_path_name + "/" + files[i] + ".md", "utf-8");
    var result = md.render(data);

    rf.writeFile(__dirname + "/" + out_path_name + "/" + files[i] + ".html", result);
}
