import React, { Fragment } from 'react';
import { connect } from 'dva';
import { Layout, Col, Icon } from 'antd';
import Game from '../components/Game.js'
import PropertyManage from '../components/PropertyManage'
import GlobalFooter from '../components/GlobalFooter';
import GlobalLeft from '../components/GlobalLeft';
import GlobalHeader from '../components/GlobalHeader';

import styles from './IndexPage.less';

const { Header, Footer, Sider, Content } = Layout;
const copyright = <Fragment>Copyright <Icon type="copyright" /> 2018 杭州乐港科技创新研究院出品</Fragment>;

function IndexPage() {
  return (
    <Layout className={styles.layout}>
      <Sider className={styles.left}>
        <GlobalLeft />
      </Sider>
      <Layout className={styles.right}>
        <GlobalHeader className={styles.header}/>
        <Content className={styles.content}>
          <Col xl={20} lg={16} md={24} sm={24} xs={24} >
            <Game />
          </Col>
          <Col xl={4} lg={8} md={24} sm={24} xs={24}>
            <PropertyManage />
          </Col>
        </Content>
        <Footer className={styles.footer}>
          <GlobalFooter copyright={copyright} />
        </Footer>
      </Layout>
    </Layout>
  );
}

IndexPage.propTypes = {
};

export default connect()(IndexPage);
