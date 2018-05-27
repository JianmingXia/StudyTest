var express = require("express");
var utility = require("utility");

var app = express();

app.get("/", function(req, res) {
    console.log(req.query);
    var q = req.query.q;

    res.send(utility.md5(q));
});

app.listen(3000, function() {
    console.log("app is listening at port: 3000");
});