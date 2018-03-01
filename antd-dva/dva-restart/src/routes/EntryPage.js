import React from 'react';
import { List  } from 'antd';

const links = [
    {
        name: "Index",
        link: "/",
        desc: "返回首页"
    },
    {
        name: "Products",
        link: "/#/0",
        desc: "产品描述。。。"
    },
    {
        name: "TodoList",
        link: "/#/1",
        desc: "TodoList demo"
    }
];

const EntryPage = (props) => (
    <List
        itemLayout="horizontal"
        dataSource={links}
        renderItem={item => (
            <List.Item>
                <List.Item.Meta
                    title={<a href={item.link}>{item.name}</a>}
                    description={item.desc}
                />
            </List.Item>
        )}
    />
);

export default EntryPage;