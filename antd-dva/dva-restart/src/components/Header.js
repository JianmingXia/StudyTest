import React from 'react';
import { Link } from 'dva/router';

const Header = () => {
    return (
        <div>
            <Link to="/">
                返回首页
            </Link>
        </div>
    );
};

export default Header;
