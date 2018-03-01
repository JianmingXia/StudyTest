import React from 'react';
import { List  } from 'antd';

const links = [
    {
        name: "Index",
        link: "/0",
        desc: "demo"
    },
    {
        name: "Products",
        link: "/1",
        desc: "产品描述。。。"
    },
    {
        name: "TodoList",
        link: "/2",
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