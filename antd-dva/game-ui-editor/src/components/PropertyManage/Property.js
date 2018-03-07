import React from 'react';
import { connect } from 'dva';
import { Form, Input } from 'antd';
import PropTypes from 'prop-types';

const FormItem = Form.Item;

const formItemLayout = {
  labelCol: {
    xs: { span: 6 },
    sm: { span: 8 },
  },
  wrapperCol: {
    xs: { span: 18 },
    sm: { span: 16 },
  },
};

const Property = () => {
  return (
    <Form>
      <FormItem
        {...formItemLayout}
        label="String: "
      >
        <Input placeholder="编辑属性" />
      </FormItem>

      < FormItem
        { ...formItemLayout }
        label = "哈哈哈哈: "
      >
        <Input placeholder = "编辑属性" / >
      </FormItem>
    </Form>
  );
}

Property.propTypes = {

}

export default connect()(Property);
