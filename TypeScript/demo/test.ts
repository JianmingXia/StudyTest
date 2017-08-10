class ExplorerViewOtherTs {
  quqi_id: number;
  tree_id: number;
  node_id: number;

  constructor(public options) {
    this.quqi_id = options.quqi_id || options.qid;
    this.tree_id = options.tree_id || options.tid;
    this.node_id = options.node_id || options.nid;
  }

  getInfo(): string {
    let xxxxxxxxxxxxxxxx = "xx";
    return this.quqi_id + " " +  this.tree_id;
  }
}

export = ExplorerViewOtherTs;
