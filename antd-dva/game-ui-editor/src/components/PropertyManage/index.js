import React, { Fragment } from 'react';
import { connect } from 'dva';
import { Collapse, Button, Tabs, Icon } from 'antd';
import PropTypes from 'prop-types';
import Property from './Property.js';
import styles from './index.less';

const Panel = Collapse.Panel;
const TabPane = Tabs.TabPane;

const PropertyManage = ({ other, dispatch }) => {
  const onToggle = () => {
    dispatch({
      type: 'other/onToggle'
    });
  }

  const getShow = () => {
    if (other.showPropertyManage === true) {
      return <Fragment>
        <Button type="primary" onClick={onToggle}>隐藏</Button>
        <Collapse >
          <Panel header="属性类型1" key="1">
            <Property />
          </Panel>
          <Panel header="属性类型2" key="2">
            <Property />
          </Panel>
        </Collapse>
      </Fragment>
    } else {
      return <Button type="primary" onClick={onToggle}>显示</Button>
    }
  }

  return (
    <Tabs defaultActiveKey="1" className={styles.property} type="card">
      <TabPane tab={<span><Icon type="apple" />属性编辑器</span>} key="1">
        {getShow()}
      </TabPane>
    </Tabs>
  );
}

PropertyManage.propTypes = {

}

export default connect(({other}) => ({
  other
}))(PropertyManage);
