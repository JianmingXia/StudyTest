var superagent = require("superagent");
var cheerio = require("cheerio");
var eventproxy = require("eventproxy");

var url = require("url");
var node_url = "https://cnodejs.org/";

superagent.get(node_url).end(function (err, sres) {
    var $ = cheerio.load(sres.text);
    var topic_url_list = [];

    $('#topic_list .topic_title').each(function (idx, element) {
        var $element = $(element);
        
        topic_url_list.push(url.resolve(node_url, $element.attr("href")));
    });

    var ep = new eventproxy();

    ep.after('topic_html', topic_url_list.length, function (topics) {
        topics = topics.map(function (topicPair) {
            var topicUrl = topicPair[0];
            var topicHtml = topicPair[1];
            var $ = cheerio.load(topicHtml);
            return ({
                title: $('.topic_full_title').text().trim(),
                href: topicUrl,
                comment1: $('.reply_content').eq(0).text().trim(),
                author1: $('.reply_author').eq(0).text().trim(),
            });
        });

        console.log(topics);
    });

    topic_url_list.forEach(function (topicUrl) {
        superagent.get(topicUrl)
            .end(function (err, res) {
                ep.emit('topic_html', [topicUrl, res.text]);
            });
    });
});