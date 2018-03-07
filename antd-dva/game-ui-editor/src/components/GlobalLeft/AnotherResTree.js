import React from 'react';
import { connect } from 'dva';
import { Tree } from 'antd';
import PropTypes from 'prop-types';

const TreeNode = Tree.TreeNode;

const AnotherResTree = ({ anotherrestree } ) => {
  const loop = data => data.map((item) => {
    if (item.children && item.children.length) {
      return <TreeNode key={item.key} title={item.title}>{loop(item.children)}</TreeNode>;
    }
    return <TreeNode showIcon={true} key={item.key} title={item.title} />;
  });

  const onDragEnter = (info) => {
    console.log(info);
    debugger;
  }

  return (
    <Tree
      className="draggable-tree"
      draggable
      onDragEnter={onDragEnter}
      >
      {loop(anotherrestree)}
    </Tree>
  );
}

AnotherResTree.propTypes = {
  anotherrestree: PropTypes.array.isRequired
}

export default connect(({ anotherrestree }) => ({
  anotherrestree
}))(AnotherResTree );
