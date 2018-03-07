import React from 'react';
import { connect } from 'dva';
import { Tree } from 'antd';
import PropTypes from 'prop-types';

const TreeNode = Tree.TreeNode;

const ResTree = ({ restree, onDrop } ) => {
  const loop = data => data.map((item) => {
    if (item.children && item.children.length) {
      return <TreeNode key={item.key} title={item.title}>{loop(item.children)}</TreeNode>;
    }
    return <TreeNode showIcon={true} key={item.key} title={item.title} />;
  });

  const onDragEnter = (info) => {
    debugger;
    console.log(info)
  }

  return (
    <Tree
      className="draggable-tree"
      draggable
      onDrop={onDrop}
      onDragEnter={onDragEnter}
      >
      {loop(restree)}
    </Tree>
  );
}

ResTree.propTypes = {
  restree: PropTypes.array.isRequired,
  onDrop: PropTypes.func.isRequired
}

export default connect(({ restree }) => ({
  restree
}))( ResTree );
