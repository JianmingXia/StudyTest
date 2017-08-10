"use strict";
var ExplorerViewOtherTs = (function () {
    function ExplorerViewOtherTs(options) {
        this.options = options;
        this.quqi_id = options.quqi_id || options.qid;
        this.tree_id = options.tree_id || options.tid;
        this.node_id = options.node_id || options.nid;
    }
    ExplorerViewOtherTs.prototype.getInfo = function () {
        var xxxxxxxxxxxxxxxx = "xx";
        return this.quqi_id + " " + this.tree_id;
    };
    return ExplorerViewOtherTs;
}());
module.exports = ExplorerViewOtherTs;
