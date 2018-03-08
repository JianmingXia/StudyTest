import React from 'react';
import { connect } from 'dva';
import { Layout } from 'antd';
import classNames from 'classnames';

import styles from './index.less';

const { Header } = Layout;

const GlobalHeader = ({className}) => {
  const clsString = classNames(styles.globalHeader, className);
  return (
    <Header className={clsString}>
      和哈哈哈哈哈哈哈哈哈
    </Header>
  );
}

export default connect()(GlobalHeader);
