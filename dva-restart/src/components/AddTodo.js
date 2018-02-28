import React, { Component } from 'react';
import { Form, Input, Button } from 'antd';
const FormItem = Form.Item;

// const AddTodo = ({ onAdd }) => {
//     const { getFieldDecorator } = this.props.form;

//     function onSubmit() {
//         console.log(this);
//     }

//     return (
//         <div>
//             <Form layout="inline" onSubmit={() => onSubmit()}>
//                 <FormItem>
//                     {getFieldDecorator('userName')(
//                         <Input size="large" placeholder="请输入任务名称" />
//                     )}
//                 </FormItem>
//                 <FormItem>
//                     <Button size="large" type="primary" htmlType="submit">添加</Button>
//                 </FormItem>
//             </Form>
//         </div>
//     );
// };

class AddTodo extends Component {
    handleSubmit(e) {
        e.preventDefault();

        this.props.form.validateFields((err, values) => {
            if (!err) {
                this.props.onAdd(values.task_name);

                this.props.form.setFieldsValue({ task_name: "" });
            }
        });
    }

    render() {
        const { getFieldDecorator } = this.props.form;

        return (
            <div>
                <Form layout="inline" onSubmit={this.handleSubmit.bind(this)}>
                    <FormItem>
                        {/* <Input size="large" placeholder="请输入任务名称" /> */}
                        {getFieldDecorator('task_name', {
                            rules: [{ required: true, message: '请输入任务名' }],
                        })(
                            <Input size="large" placeholder="请输入任务名称" />
                            )
                        }
                    </FormItem>
                    <FormItem>
                        <Button size="large" type="primary" htmlType="submit">添加</Button>
                    </FormItem>
                </Form>
            </div>
        )
    }
}

const NormalAddTodo = Form.create()(AddTodo);
export default NormalAddTodo;