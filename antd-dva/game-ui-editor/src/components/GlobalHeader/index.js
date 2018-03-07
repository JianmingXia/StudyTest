import React from 'react';
import { connect } from 'dva';
import { Layout } from 'antd';
import styles from './index.less';

const { Header } = Layout;

const GlobalHeader = () => {
  return (
    <Header className={styles.globalHeader}>
      和哈哈哈哈哈哈哈哈哈
    </Header>
  );
}

export default connect()(GlobalHeader);
