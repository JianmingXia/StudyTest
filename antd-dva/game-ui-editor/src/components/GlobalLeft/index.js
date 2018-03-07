
import React from 'react';
import { connect } from 'dva';
import { Row } from 'antd';
import ResTree from './ResTree.js'
import AnotherResTree from './AnotherResTree.js'
import AddRes from './AddRes.js'
import styles from './index.less'

const Left = ({ dispatch }) => {
  const handleDrop = (params) => {
    dispatch({
      type: 'restree/drop',
      payload: params
    });
  }

  return (
    <div className={styles.left}>
      <Row>
        <AddRes />
      </Row>
      <div style={{ height: "100%" }}>
        <Row style={{ height: "50%", overflowY: "auto" }} >
          <ResTree onDrop={handleDrop} />
        </Row>
        <Row style={{ height: "50%", overflowY: "auto"  }} >
          <AnotherResTree />
        </Row>
      </div>
    </div>
  );
};

export default connect()(Left);
