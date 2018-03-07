import { Menu, Dropdown, Button } from 'antd';
const SubMenu = Menu.SubMenu;

const menu = (
  <Menu>
    <Menu.Item> 创建空节点</Menu.Item>
    <SubMenu title="创建UI结点">
      <Menu.Item> Button </Menu.Item>
      <Menu.Item> Label </Menu.Item>
    </SubMenu>
  </Menu>
);

const AddRes = () => {
  return (
    <Dropdown overlay={menu} placement="bottomLeft">
      <Button> + </Button>
    </Dropdown>
  );
};

export default AddRes;