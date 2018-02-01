[TOC]

# quqi_center
## 数据直接覆盖
```
DROP TABLE IF EXISTS `cfg_lang`;
CREATE TABLE `cfg_lang` (
  `key` varchar(255) NOT NULL,
  `chs` varchar(255) NOT NULL,
  PRIMARY KEY (`key`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_lang
-- ----------------------------
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_BLOCKED', '账户冻结');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_BLOCKED_TIPS', '账户冻结时会禁用文档功能，公司数据将在冻结一个月后删除。请立即充值以保证曲奇文档的正常使用。');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_BLOCKED_TIPS_DING_1', '【曲奇文档】【');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_BLOCKED_TIPS_DING_2', '】账户已冻结，数据将在1个月后删除。请立即充值以保证曲奇文档的正常使用。');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_OVERDUE', '该账号已欠费冻结，请联系管理员进行充值');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_OVERDUE_TIPS', '账户欠费时会禁用部分文档功能，欠费7天后将禁用文档功能。请立即充值以保证文档的正常使用。');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_OVERDUE_TIPS_DING_1', '【曲奇文档】【');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_OVERDUE_TIPS_DING_2', '】账户已欠费，欠费7天后将禁用文档功能。请立即充值以保证曲奇文档的正常使用。');
INSERT INTO `cfg_lang` VALUES ('ACCOUNT_OVERDUE_TITLE', '账户欠费');
INSERT INTO `cfg_lang` VALUES ('ACTIVATION_CODE_EMPTY', '激活码为空！');
INSERT INTO `cfg_lang` VALUES ('ACTIVATION_CODE_ERROR', '激活码错误！');
INSERT INTO `cfg_lang` VALUES ('ADD_ADMIN_PERMISSION_2', '添加管理权限');
INSERT INTO `cfg_lang` VALUES ('ADD_COMMENT_GROUP_MEMBERS_FAIL', '评论群添加人员失败');
INSERT INTO `cfg_lang` VALUES ('ADD_NEW_VERSION', '新增版本');
INSERT INTO `cfg_lang` VALUES ('ADD_PERMISSION_1', '为');
INSERT INTO `cfg_lang` VALUES ('ADD_READ_PERMISSION_2', '添加查阅权限');
INSERT INTO `cfg_lang` VALUES ('ADJUST_TO', '调整至');
INSERT INTO `cfg_lang` VALUES ('ADMIN_ENTERPRISE_EXPIRE_TIME', '企业已欠费过期，在30天内您可以下载备份文件，请立即充值以保证曲奇文档的正常使用。');
INSERT INTO `cfg_lang` VALUES ('AGENT_BILL_COST_1', '【');
INSERT INTO `cfg_lang` VALUES ('AGENT_BILL_COST_2', '】代扣账单');
INSERT INTO `cfg_lang` VALUES ('AGENT_COST', '代扣费');
INSERT INTO `cfg_lang` VALUES ('AGENT_ERROR', '不合法的钉钉agentid');
INSERT INTO `cfg_lang` VALUES ('ALIYUN_SMS_SIGN_NAME', '曲奇');
INSERT INTO `cfg_lang` VALUES ('ALREADY_FAVORITE', '已收藏!');
INSERT INTO `cfg_lang` VALUES ('ALREADY_HAVE_QUQI_ID', '已绑定Quqi ID！');
INSERT INTO `cfg_lang` VALUES ('AND_SO_ON', '等');
INSERT INTO `cfg_lang` VALUES ('API_UNUSEFUL', '接口不可用');
INSERT INTO `cfg_lang` VALUES ('APPID_NOT_EXIST', '该appid不存在。');
INSERT INTO `cfg_lang` VALUES ('APPLY_JOIN_TEAM', '申请加入团队');
INSERT INTO `cfg_lang` VALUES ('APPROVAL_CHECK_EXIST', '文档有待审批申请，审批同意后文档将自动定稿');
INSERT INTO `cfg_lang` VALUES ('APPROVAL_REVOKED', '审批申请已被撤销!');
INSERT INTO `cfg_lang` VALUES ('APP_ADD_TASK_NOTIFY', '将你加入任务');
INSERT INTO `cfg_lang` VALUES ('APP_APN_CONTENT', '请点击查看详情');
INSERT INTO `cfg_lang` VALUES ('APP_APPROVAL_NOTIFY', '您有一条未处理待办');
INSERT INTO `cfg_lang` VALUES ('APP_CHAT_NOTIFY', '您有一条新的评论');
INSERT INTO `cfg_lang` VALUES ('APP_NOTIFICATION_NOTIFY', '您有一条新的动态');
INSERT INTO `cfg_lang` VALUES ('APP_NOT_ONLINE', 'APP不处于上线状态。');
INSERT INTO `cfg_lang` VALUES ('BACKEND_CREATE_ENTERPRISE', '运营后台创建企业');
INSERT INTO `cfg_lang` VALUES ('BALANCE_DUE', '账户余额不足');
INSERT INTO `cfg_lang` VALUES ('BALANCE_DUE_TIPS', '为保证曲奇文档的正常使用，请立即进行充值');
INSERT INTO `cfg_lang` VALUES ('BILL_COST', '扣费账单');
INSERT INTO `cfg_lang` VALUES ('BIND_DING_FAIL', '绑定钉钉账号失败');
INSERT INTO `cfg_lang` VALUES ('BIND_PHONE', '绑定手机号');
INSERT INTO `cfg_lang` VALUES ('BIND_PHONE_FAIL', '绑定手机号失败');
INSERT INTO `cfg_lang` VALUES ('BIND_WECHAT_BINDED_QUQI', '绑定失败，该微信已绑定其他曲奇账号');
INSERT INTO `cfg_lang` VALUES ('BUFFER_DOC_COST', '试用期免费');
INSERT INTO `cfg_lang` VALUES ('BUFFER_OVERDUE_TIPS', '您的团队试用期已结束，请在试用期结束后的一周内进行充值，以免账户欠费为您带来不便，感谢您的支持！');
INSERT INTO `cfg_lang` VALUES ('BUFFER_OVERDUE_TIPS_DING_1', '团队');
INSERT INTO `cfg_lang` VALUES ('BUFFER_OVERDUE_TIPS_DING_2', '的试用期已结束，请在试用期结束后的一周内进行充值，以免账户欠费为您带来不便，感谢您的支持！');
INSERT INTO `cfg_lang` VALUES ('BUFFER_OVERDUE_TITLE', '试用期已结束');
INSERT INTO `cfg_lang` VALUES ('BUFFER_TIP_TIPS', '您的团队试用期即将到期，请及时充值避免欠费。');
INSERT INTO `cfg_lang` VALUES ('BUFFER_TIP_TIPS_DING_1', '团队');
INSERT INTO `cfg_lang` VALUES ('BUFFER_TIP_TIPS_DING_2', '的试用期即将到期，请及时充值避免欠费。');
INSERT INTO `cfg_lang` VALUES ('BUFFER_TIP_TITLE', '试用期即将到期');
INSERT INTO `cfg_lang` VALUES ('can not find target node', '目的节点不存在!');
INSERT INTO `cfg_lang` VALUES ('can not insert into db', '数据库插入失败!');
INSERT INTO `cfg_lang` VALUES ('CANT_DELETE_SHARE', '无法删除发布');
INSERT INTO `cfg_lang` VALUES ('CHANGE_PHONE_FAIL', '更换手机失败');
INSERT INTO `cfg_lang` VALUES ('CHANGE_TO', '变更为');
INSERT INTO `cfg_lang` VALUES ('CHAT_NOTIFICATION_AT_TIP', '：在评论中@了你');
INSERT INTO `cfg_lang` VALUES ('CHAT_NOTIFICATION_TIP', '有新的评论');
INSERT INTO `cfg_lang` VALUES ('CHECK_USER_EMPTY', '审批人不可为空!');
INSERT INTO `cfg_lang` VALUES ('CHILD_COMPANY', '子团队');
INSERT INTO `cfg_lang` VALUES ('CHS_LEFT_BRACKETS', '【');
INSERT INTO `cfg_lang` VALUES ('CHS_RIGHT_BRACKETS', '】');
INSERT INTO `cfg_lang` VALUES ('CLICK_DETAIL', '单击查看详情');
INSERT INTO `cfg_lang` VALUES ('CODE_EMPTY', 'code不可以为空');
INSERT INTO `cfg_lang` VALUES ('CODE_IS_USED', 'code被重复使用。');
INSERT INTO `cfg_lang` VALUES ('COFIRM_PASSWORD_ERROR', '确认密码不正确');
INSERT INTO `cfg_lang` VALUES ('COIN_BALANCE', '曲奇余额:');
INSERT INTO `cfg_lang` VALUES ('COLON', '：');
INSERT INTO `cfg_lang` VALUES ('COME_FROM', '来自于');
INSERT INTO `cfg_lang` VALUES ('COMPANY_CHILD', '子团队');
INSERT INTO `cfg_lang` VALUES ('COMPANY_EDITION_LIMIT_OPERATE_RECORD_KEEP_DAY_1', '仅支持');
INSERT INTO `cfg_lang` VALUES ('COMPANY_EDITION_LIMIT_OPERATE_RECORD_KEEP_DAY_2', '天内的操作记录查询');
INSERT INTO `cfg_lang` VALUES ('COMPANY_EDITION_TYPE_INVALID', '团队版本类型无效');
INSERT INTO `cfg_lang` VALUES ('COMPANY_INSERT_DB_FAIL', '更新公司数据库失败');
INSERT INTO `cfg_lang` VALUES ('COMPANY_INVITE_URL_ERROR', '公司邀请链接错误');
INSERT INTO `cfg_lang` VALUES ('COMPANY_INVITE_URL_IS_OFF', '该团队已经关闭员工自主申请');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NAME', '团队名称');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NAME_EMPTY', '公司名为空！');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NAME_EXIST', '该公司名已被占用');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NAME_FORMAT', '团队名称格式错误');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NAME_TOO_LONG', '团队名称过长');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NORMAL', '一般');
INSERT INTO `cfg_lang` VALUES ('COMPANY_NOT_EXIST', '公司不存在');
INSERT INTO `cfg_lang` VALUES ('COMPANY_PARENT', '父团队');
INSERT INTO `cfg_lang` VALUES ('COMPANY_PUBLIC_DIR_DETAIL', '该文件夹用于存放特殊项目文件夹，配置权限后可开始协作');
INSERT INTO `cfg_lang` VALUES ('COMPANY_PUBLIC_DIR_NAME', '自定义文件夹');
INSERT INTO `cfg_lang` VALUES ('COMPANY_TYPE', '团队类型');
INSERT INTO `cfg_lang` VALUES ('COPY_DIR', '复制');
INSERT INTO `cfg_lang` VALUES ('COPY_DIR_DETAIL', '被复制到');
INSERT INTO `cfg_lang` VALUES ('COPY_DOC', '复制');
INSERT INTO `cfg_lang` VALUES ('COPY_DOC_DETAIL', '被复制到');
INSERT INTO `cfg_lang` VALUES ('COPY_ERROR_EXCEPTION', '复制意外错误!');
INSERT INTO `cfg_lang` VALUES ('COPY_ERROR_LOOP', '复制循环错误!');
INSERT INTO `cfg_lang` VALUES ('COPY_LIMITS_BEYOUND', '复制超出限制!');
INSERT INTO `cfg_lang` VALUES ('CORPID_EXIST', 'CORPID已存在');
INSERT INTO `cfg_lang` VALUES ('CORPID_NOT_EXIST', 'CORPID不存在');
INSERT INTO `cfg_lang` VALUES ('CREATE_COMMENT_GROUP_FAIL', '创建评论群失败');
INSERT INTO `cfg_lang` VALUES ('CREATE_DEPARTMENT_FAIL', '创建部门失败');
INSERT INTO `cfg_lang` VALUES ('CREATE_DIR', '新建');
INSERT INTO `cfg_lang` VALUES ('CREATE_DIR_DETAIL', '创建文件夹');
INSERT INTO `cfg_lang` VALUES ('CREATE_DOC', '新建');
INSERT INTO `cfg_lang` VALUES ('CREATE_DOC_DETAIL', '创建文档');
INSERT INTO `cfg_lang` VALUES ('CREATE_FAILED', '创建失败!');
INSERT INTO `cfg_lang` VALUES ('CREATE_FILE_DETAIL', '创建了文件');
INSERT INTO `cfg_lang` VALUES ('CREATE_TOO_MANY_COMPANY', '一个账号只能创建100个团队');
INSERT INTO `cfg_lang` VALUES ('CREATE_USER_FAIL', '添加员工失败');
INSERT INTO `cfg_lang` VALUES ('CROSS_QUQI_COPY_PERMISSION_ERROR', '团队间只能进行单文档复制！');
INSERT INTO `cfg_lang` VALUES ('DEAR_USER', '尊敬的用户：');
INSERT INTO `cfg_lang` VALUES ('DEFAULT_FAVORITES_FOLDER_NAME', '我的收藏');
INSERT INTO `cfg_lang` VALUES ('DEFAULT_TEAM_FAVORITES_FOLDER_NAME', '团队收藏');
INSERT INTO `cfg_lang` VALUES ('DELETE_BOSS_NOT_SELF', '取消管理员参数错误');
INSERT INTO `cfg_lang` VALUES ('DELETE_DEPARTMENT_FAIL', '删除部门失败');
INSERT INTO `cfg_lang` VALUES ('DELETE_DIR', '删除');
INSERT INTO `cfg_lang` VALUES ('DELETE_DIR_DETAIL', '删除文件夹');
INSERT INTO `cfg_lang` VALUES ('DELETE_DOC', '删除');
INSERT INTO `cfg_lang` VALUES ('DELETE_DOC_DETAIL', '删除文档');
INSERT INTO `cfg_lang` VALUES ('DELETE_FAIL', '删除失败!');
INSERT INTO `cfg_lang` VALUES ('DELETE_FILE', '删除文件');
INSERT INTO `cfg_lang` VALUES ('DELETE_FILE_DETAIL', '删除了文件');
INSERT INTO `cfg_lang` VALUES ('DELETE_USER_FAIL', '删除员工失败');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT', '部门');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_DIR_NOT_MOVE', '该文件夹为部门文件夹，需管理员在通讯录中修改部门结构，来进行移动操作');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_EXTERNAL_DIR_DETAIL', '该文件夹可用于外部部门协作。新建协作项目文件夹后，配置权限即可使用。');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_EXTERNAL_DIR_NAME', '对外协作');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_FOLDER', '部门文件夹');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_FOLDER_DETAIL', '该文件夹为部门文件夹。部门文件夹不可重命名，删除和移动，可通过变更通讯录部门结构进行更改。');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_INTERNAL_DIR_DETAIL', '该文件夹用于部门内协作的开展，当前部门内人员可进行编辑。');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_INTERNAL_DIR_NAME', '内部协同');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_INTERNAL_STAFF_DIR_NAME', '全员协同');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_KNOWLEDGE_DETAIL', '请将部门内的知识共享内容放在这个文件夹中，建立部门知识库。');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_KNOWLEDGE_NAME', '知识沉淀');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_MANAGER_DIR_DETAIL', '该文件夹用于存放部门内绩效等管理文件，仅部门主管及上级主管可见。');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_MANAGER_DIR_NAME', '部门管理');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_MEMBERS_DIR_DETAIL', '该文件夹用于个人工作文件的存储，请各位员工将工作文件上传至该文件夹中');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_MEMBERS_DIR_NAME', '部门成员');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_NAME_EMPTY', '部门名称为空');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_NAME_NOT_CONTINUOUS', '部门名称不连续');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_NOT_FOUND', '部门不存在');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_SUBORDINATE_DETAIL', '该文件夹内存放下级部门的部门文件夹。通过更改通讯录中部门结构，会自动调整部门文件夹结构');
INSERT INTO `cfg_lang` VALUES ('DEPARTMENT_SUBORDINATE_NAME', '下级部门');
INSERT INTO `cfg_lang` VALUES ('DEST_NODE_NOT_FOUND', '目的节点不存在!');
INSERT INTO `cfg_lang` VALUES ('DEST_NOT_EXIST', '目标不存在!');
INSERT INTO `cfg_lang` VALUES ('DEST_QUQI_NOT_EXIST', '请求的Quqi服务不存在');
INSERT INTO `cfg_lang` VALUES ('DEST_TREE_NOT_EXIST', '请求的树不存在');
INSERT INTO `cfg_lang` VALUES ('DFEPARTMENT_DIR_NOT_DELETE', '该文件夹为部门文件夹，需管理员在通讯录中删除部门后，才能删除该目录');
INSERT INTO `cfg_lang` VALUES ('DFEPARTMENT_DIR_NOT_RENAME', '该文件夹为部门文件夹，需管理员在通讯录中修改部门名称，来进行重命名操作');
INSERT INTO `cfg_lang` VALUES ('DINGDING_COMPANY', '钉钉');
INSERT INTO `cfg_lang` VALUES ('DINGDING_NEW_USER_INVITE_TIP_1', '【曲奇办公】团队（');
INSERT INTO `cfg_lang` VALUES ('DINGDING_NEW_USER_INVITE_TIP_2', '）邀请您加入曲奇办公进行协作，您可以通过：钉钉-工作-曲奇办公开始工作，或在pc浏览器中登录quqi.com,通过钉钉扫码进行登录。');
INSERT INTO `cfg_lang` VALUES ('DING_PASSPORT_IS_BINDED', '绑定失败，该钉钉已绑定其他曲奇账号');
INSERT INTO `cfg_lang` VALUES ('DING_SERVER_ERROR', '连接钉钉服务器失败');
INSERT INTO `cfg_lang` VALUES ('DING_TALK_USER_ID_FAIL', '');
INSERT INTO `cfg_lang` VALUES ('DIR_CANT_SHARE', '目录不可发布');
INSERT INTO `cfg_lang` VALUES ('DISCARDED_ACCESS_TOKEN', 'access token废除。');
INSERT INTO `cfg_lang` VALUES ('DOC_CANT_SET_SHARE_TYPE', '此文档不可设置此发布类型');
INSERT INTO `cfg_lang` VALUES ('DOC_EDIT_LOCKED', '删除失败，文件可能处于被编辑状态，请检查后重试');
INSERT INTO `cfg_lang` VALUES ('DOC_EMPTY_CONTENT', '文档内容为空，请编辑后重试');
INSERT INTO `cfg_lang` VALUES ('DOC_NUM_COST', '文档数扣费');
INSERT INTO `cfg_lang` VALUES ('DOC_SYS', '文档系统（');
INSERT INTO `cfg_lang` VALUES ('DOC_TRANSFORM_SAME_NAME_NODE_EXISTS', '已有同名曲奇文档存在，请重命名后再进行转换');
INSERT INTO `cfg_lang` VALUES ('DOC_TYPE_ERROR', '文件类型错误');
INSERT INTO `cfg_lang` VALUES ('DOC_TYPE_NOT_IMG', '非图片格式');
INSERT INTO `cfg_lang` VALUES ('EDITION_OVER_MAX_USER_CNT', '成员人数已满！');
INSERT INTO `cfg_lang` VALUES ('EDIT_DEPARTMENT_FAIL', '修改部门失败！');
INSERT INTO `cfg_lang` VALUES ('EDIT_DOC', '提交版本');
INSERT INTO `cfg_lang` VALUES ('EDIT_DOC_DETAIL', '提交文档版本');
INSERT INTO `cfg_lang` VALUES ('EDIT_FILE_FAIL', '编辑文件失败!');
INSERT INTO `cfg_lang` VALUES ('EDIT_PUSH_CUSTOM_FAIL', '修改动态设置失败！');
INSERT INTO `cfg_lang` VALUES ('EDIT_USER_FAIL', '编辑员工失败');
INSERT INTO `cfg_lang` VALUES ('ENTERPRISE_APPLICATION', '企业申请');
INSERT INTO `cfg_lang` VALUES ('ENTERPRISE_EDITION_STORAGE_ALARM', '文档容量即将到达上限。您可以联系客服提升文档容量。');
INSERT INTO `cfg_lang` VALUES ('ENTERPRISE_EDITION_STORAGE_OVERRUN', '企业文档总容量已超出限制。请联系客服提升文档容量。');
INSERT INTO `cfg_lang` VALUES ('ENTERPRISE_EXPIRE_TIME', '企业已欠费过期，请联系管理员充值。');
INSERT INTO `cfg_lang` VALUES ('EXPIRED_ACCESS_TOKEN', 'access token过期。');
INSERT INTO `cfg_lang` VALUES ('EXPIRE_TIME_CODE', '该验证码已过期，请重新发起邀请');
INSERT INTO `cfg_lang` VALUES ('EXTERNAL_SHARE', '曲奇办公');
INSERT INTO `cfg_lang` VALUES ('FAVORITES_NOT_EXIST', '用户收藏不存在!');
INSERT INTO `cfg_lang` VALUES ('FILE_MOVE_NOTIFY_1', '从');
INSERT INTO `cfg_lang` VALUES ('FILE_MOVE_NOTIFY_2', '移动文件至');
INSERT INTO `cfg_lang` VALUES ('FILE_MOVE_NOTIFY_3', '移动了文件至别处');
INSERT INTO `cfg_lang` VALUES ('FILE_NOT_VOD', '文件不能播放');
INSERT INTO `cfg_lang` VALUES ('FIRST_PAY_GIFT_DETAIL', '首冲赠送');
INSERT INTO `cfg_lang` VALUES ('FOLLOW_FAIL', '关注失败!');
INSERT INTO `cfg_lang` VALUES ('FOLLOW_FAILED', '关注失败!');
INSERT INTO `cfg_lang` VALUES ('GET DRAFT FAIL', '获取草稿失败!');
INSERT INTO `cfg_lang` VALUES ('GET_ACCESS_TOKEN_FAIL', '获取登录token失败');
INSERT INTO `cfg_lang` VALUES ('GET_ACCESS_TOKEN_THROUGH_CODE_FAIL', '用code换取access token值失败。');
INSERT INTO `cfg_lang` VALUES ('GET_AUTH_INFO_FAIL', '获取钉钉账号信息失败');
INSERT INTO `cfg_lang` VALUES ('GET_CODE_FAIL', '获取code值失败。');
INSERT INTO `cfg_lang` VALUES ('GET_JS_API_TICKET_ERROR', '获取js_api凭据失败');
INSERT INTO `cfg_lang` VALUES ('GET_QUQI_ID_FAIL', '获取Quqi ID失败');
INSERT INTO `cfg_lang` VALUES ('GET_REFRESH_TOKEN_FAIL', '获取refresh token值失败。');
INSERT INTO `cfg_lang` VALUES ('GET_USER_INFO_CODE_ERROR', '获取用户账号信息失败');
INSERT INTO `cfg_lang` VALUES ('GET_USER_INFO_FAIL', '钉钉CODE换取用户身份失败');
INSERT INTO `cfg_lang` VALUES ('GET_VALIDATE_CODE_FAIL', '获取手机验证码失败');
INSERT INTO `cfg_lang` VALUES ('GRANT_ADMIN_PERMISSION', '为您开通了管理权限');
INSERT INTO `cfg_lang` VALUES ('GRANT_READ_PERMISSION', '为您开通了查阅权限');
INSERT INTO `cfg_lang` VALUES ('GRANT_WRITE_PERMISSION', '为您开通了编辑权限');
INSERT INTO `cfg_lang` VALUES ('GROUP_DECORATE_1', '群组【');
INSERT INTO `cfg_lang` VALUES ('GROUP_DECORATE_2', '】');
INSERT INTO `cfg_lang` VALUES ('GROUP_NAME_OCCUPIED', '该群组名已存在，请修改后重试');
INSERT INTO `cfg_lang` VALUES ('GROUP_NOT_FOUND', '未找到组!');
INSERT INTO `cfg_lang` VALUES ('HAVE_INVITE_CODE', '是否有邀请码');
INSERT INTO `cfg_lang` VALUES ('HIDDEN_BOSS_STATUS', '当前处于隐身状态，请在管理中心退出隐身后再进行操作');
INSERT INTO `cfg_lang` VALUES ('HOLIDAY_DOC_COST', '法定节假日免费');
INSERT INTO `cfg_lang` VALUES ('HTTP_USER_AGENT_ERROR', '用户代理错误');
INSERT INTO `cfg_lang` VALUES ('IMPORT_MEMBER_FAIL', '导入通讯录失败');
INSERT INTO `cfg_lang` VALUES ('INDEPENDENT_COMPANY', '独立团队');
INSERT INTO `cfg_lang` VALUES ('INDUSTRY_TYPE_EMPTY', '所属行业不可为空');
INSERT INTO `cfg_lang` VALUES ('INITIATIVE_REGISTER', '主动');
INSERT INTO `cfg_lang` VALUES ('INPUT_INVALID', '');
INSERT INTO `cfg_lang` VALUES ('INSERT_DIRECTORY_FAIL', '插入目录失败!');
INSERT INTO `cfg_lang` VALUES ('INSERT_NODE_FAIL', '插入节点失败!');
INSERT INTO `cfg_lang` VALUES ('INVALID_ACCESS_TOKEN', 'access token非法。');
INSERT INTO `cfg_lang` VALUES ('INVALID_APP_SECRET', 'client_secret（即appkey）非法。');
INSERT INTO `cfg_lang` VALUES ('INVALID_COMPANY', '无效公司!');
INSERT INTO `cfg_lang` VALUES ('INVALID_DEPARTMENT_ID', '无效的部门');
INSERT INTO `cfg_lang` VALUES ('INVALID_DEPARTMENT_NAME', '部门名称不合法');
INSERT INTO `cfg_lang` VALUES ('INVALID_DOC_TYPE', '无效的文档类型');
INSERT INTO `cfg_lang` VALUES ('INVALID_FAVORITES_ITEM_TYPE', '无效收藏类型!');
INSERT INTO `cfg_lang` VALUES ('INVALID_GROUP', '无效群组!');
INSERT INTO `cfg_lang` VALUES ('INVALID_GROUP_NAME', '无效组名!');
INSERT INTO `cfg_lang` VALUES ('INVALID_INPUT', '无效的输入');
INSERT INTO `cfg_lang` VALUES ('INVALID_INVITATION_CODE', '无效的邀请码！');
INSERT INTO `cfg_lang` VALUES ('INVALID_INVITE_CODE', '验证码填写错误，请确认后重试');
INSERT INTO `cfg_lang` VALUES ('INVALID_NAME', '无效名称!');
INSERT INTO `cfg_lang` VALUES ('INVALID_NITIFI_ID', '无效通知ID!');
INSERT INTO `cfg_lang` VALUES ('INVALID_PAGE', '无效页码!');
INSERT INTO `cfg_lang` VALUES ('INVALID_PARENT_ID', '无效父节点!');
INSERT INTO `cfg_lang` VALUES ('INVALID_PHONE', '手机号不合法');
INSERT INTO `cfg_lang` VALUES ('INVALID_QUQI_ID', '无效的Quqi ID！');
INSERT INTO `cfg_lang` VALUES ('INVALID_REDIRECT_URI', '回调地址不合法');
INSERT INTO `cfg_lang` VALUES ('INVALID_REFRESH_TOKEN', 'refresh token非法。');
INSERT INTO `cfg_lang` VALUES ('INVALID_TIME', '无效时间!');
INSERT INTO `cfg_lang` VALUES ('INVALID_URL', '无效URL!');
INSERT INTO `cfg_lang` VALUES ('INVALID_USER_NAME', '用户名不合法');
INSERT INTO `cfg_lang` VALUES ('INVITATION_QUQI_ID', '无效曲奇号');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_1', '【曲奇】');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_2', '希望添加');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_3', '成为其子团队，并拥有');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_4', '的最高管理权限，若同意邀请，请将验证码：【');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_5', '】提供给');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_CONTENT_6', '的管理员');
INSERT INTO `cfg_lang` VALUES ('INVITE_CODE_TITLE', '邀请成为子团队');
INSERT INTO `cfg_lang` VALUES ('INVITE_GIFT_DETAIL', '邀请赠送');
INSERT INTO `cfg_lang` VALUES ('IS_CHILD_COMPANY', '是否是子团队');
INSERT INTO `cfg_lang` VALUES ('IS_LOGIN', '该账户已登录');
INSERT INTO `cfg_lang` VALUES ('JOIN_COMMENT_GROUP_FAIL', '加入评论群失败');
INSERT INTO `cfg_lang` VALUES ('JOIN_COMPANY_FAIL', '申请加入团队失败');
INSERT INTO `cfg_lang` VALUES ('JOYPORT_GROUP_NAME', '杭州乐港科技有限公司');
INSERT INTO `cfg_lang` VALUES ('JS_API_TICKET_FAIL', '');
INSERT INTO `cfg_lang` VALUES ('LACK_ACCESS_TOKEN', '缺少access token。');
INSERT INTO `cfg_lang` VALUES ('LACK_CLIENT_ID', '缺少参数client_id。');
INSERT INTO `cfg_lang` VALUES ('LACK_CLIENT_SECRET', '缺少参数client_secret。');
INSERT INTO `cfg_lang` VALUES ('LACK_CODE', '缺少参数code。');
INSERT INTO `cfg_lang` VALUES ('LACK_OR_INVALID_GRANT_TYPE', '缺少参数grant_type或grant_type非法。');
INSERT INTO `cfg_lang` VALUES ('LACK_OR_INVALID_RESPONSE_TYPE', '缺少参数response_type或response_type非法。');
INSERT INTO `cfg_lang` VALUES ('LACK_REFRESH_TOKEN', '缺少refresh token。');
INSERT INTO `cfg_lang` VALUES ('LEFT_BRACKET', '【');
INSERT INTO `cfg_lang` VALUES ('LICENCE_CODE_ERROR', '');
INSERT INTO `cfg_lang` VALUES ('LINK_NOT_EXIST', '链接不存在！');
INSERT INTO `cfg_lang` VALUES ('LOGIN_FAIL', '登录失败');
INSERT INTO `cfg_lang` VALUES ('MARK_READ_FAIL', '标记已读失败!');
INSERT INTO `cfg_lang` VALUES ('MOVE_DIR', '修改路径');
INSERT INTO `cfg_lang` VALUES ('MOVE_DIR_DETAIL', '转移至');
INSERT INTO `cfg_lang` VALUES ('MOVE_DOC', '修改路径');
INSERT INTO `cfg_lang` VALUES ('MOVE_DOC_DETAIL', '转移至');
INSERT INTO `cfg_lang` VALUES ('MOVE_FAIL', '移动失败!');
INSERT INTO `cfg_lang` VALUES ('MOVE_FILE_DETAIL_1_1', '移动文件，从');
INSERT INTO `cfg_lang` VALUES ('MOVE_FILE_DETAIL_1_2', '至');
INSERT INTO `cfg_lang` VALUES ('MOVE_FILE_DETAIL_2_1', '移动文件');
INSERT INTO `cfg_lang` VALUES ('MOVE_FILE_DETAIL_2_2', '至别处');
INSERT INTO `cfg_lang` VALUES ('MOVE_FILE_DETAIL_3_1', '移动文件至');
INSERT INTO `cfg_lang` VALUES ('MULTI_DOWNLOAD', '【批量下载】');
INSERT INTO `cfg_lang` VALUES ('MULTI_VERSION_VAILD', '多版本对比功能未开通!');
INSERT INTO `cfg_lang` VALUES ('MY_PRIVATE_TREE', '我的私有目录');
INSERT INTO `cfg_lang` VALUES ('NAME_NOT_VALID', '名称格式不符');
INSERT INTO `cfg_lang` VALUES ('NEED_RENEW_VIP_1', '您的文档系统（');
INSERT INTO `cfg_lang` VALUES ('NEED_RENEW_VIP_2', '）');
INSERT INTO `cfg_lang` VALUES ('NEED_RENEW_VIP_3', '将于');
INSERT INTO `cfg_lang` VALUES ('NEED_RENEW_VIP_4', '到期。我们提醒您及时续费，以保证功能的正常使用。');
INSERT INTO `cfg_lang` VALUES ('NEED_UPGRADE_VIP', '）的容量即将达到上限，我们提醒您及时扩容，以保证功能的正常使用。');
INSERT INTO `cfg_lang` VALUES ('NOBODY', '');
INSERT INTO `cfg_lang` VALUES ('Node invalid or not document', '不存在或非文件!');
INSERT INTO `cfg_lang` VALUES ('NODE IS NULL', '空节点!');
INSERT INTO `cfg_lang` VALUES ('NODE_ADDED_COMMENT_GROUP', '节点已创建评论群');
INSERT INTO `cfg_lang` VALUES ('NODE_COMMENT_GROUP_NOT_EXIST', '评论群组不存在');
INSERT INTO `cfg_lang` VALUES ('NODE_DELETED', '文档被删除!');
INSERT INTO `cfg_lang` VALUES ('NODE_NOT_USER', '用户报告不匹配');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_CREATE_DOC', '新建了文档');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_EDIT_DOC', '修改了文档');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_PASS_CHECK', '同意了文档审批');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_REJECT_CHECK', '驳回了文档审批');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_UPLOAD_DIR', '上传了文件夹');
INSERT INTO `cfg_lang` VALUES ('NOTIFY_UPLOAD_DOC', '上传了文档');
INSERT INTO `cfg_lang` VALUES ('NOT_ADMIN_NODE', '没有可管理的节点');
INSERT INTO `cfg_lang` VALUES ('NOT_ADMIN_PERMISSION', '无管理员权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_ADVANCE_PERMISSION', '无权限,请联系高级系统管理员!');
INSERT INTO `cfg_lang` VALUES ('NOT_AUTHORIZED_TO_READ', '没有查阅权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_AUTHORIZED_TO_VIEW', '无访问权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_AUTHORIZED_TO_WRITE', '没有编辑权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_AUTHORIZED_TO_WRITE_PARENT_DIRECTORY', '没有当前文件上级目录权限，无法进行转换');
INSERT INTO `cfg_lang` VALUES ('NOT_COMPANY', '不是公司!');
INSERT INTO `cfg_lang` VALUES ('NOT_COMPANY_CANT_SHARE', '非曲奇团队不可发布');
INSERT INTO `cfg_lang` VALUES ('NOT_DELETE_ROOT', '不能删除根目录!');
INSERT INTO `cfg_lang` VALUES ('NOT_EDIT_PERMISSION', '无修改权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_ENTERPRISE_EDITION', '非企业版公司');
INSERT INTO `cfg_lang` VALUES ('NOT_HTTP_POST', 'HTTP请求非post方式。');
INSERT INTO `cfg_lang` VALUES ('NOT_INVITE_MYSELF', '不能邀请自己!');
INSERT INTO `cfg_lang` VALUES ('NOT_INVITE_PARENT_COMPANY', '不能邀请自己的父团队!');
INSERT INTO `cfg_lang` VALUES ('NOT_MEMBER_OF_COMPANY', '非公司成员!');
INSERT INTO `cfg_lang` VALUES ('NOT_MOVE_AUTHORIZED', '无剪切权限，需拥有【目标目录】和【源目录】上级文件夹的编辑权限才能进行剪切');
INSERT INTO `cfg_lang` VALUES ('NOT_MULTI_QUQI_CUT', '无法进行跨公司剪切，您可以通过单文档复制进行文件转移');
INSERT INTO `cfg_lang` VALUES ('NOT_NESTIFICATION_PASTE', '不能嵌套粘贴!');
INSERT INTO `cfg_lang` VALUES ('NOT_READ_PERMISSION', '无阅读权限!');
INSERT INTO `cfg_lang` VALUES ('NOT_RENAME_ROOT', '根节点不能重命名!');
INSERT INTO `cfg_lang` VALUES ('NOT_SHARING_CANT_STOP_SHARE', '非发布状态不可停止发布');
INSERT INTO `cfg_lang` VALUES ('NOT_STOP_SHARE_CANT_CONTINUE_SHARE', '非停止发布状态不可继续发布');
INSERT INTO `cfg_lang` VALUES ('NOT_TEAM_EDITION', '非团队版公司');
INSERT INTO `cfg_lang` VALUES ('NOT_VAILD_NODE', '找不到目标文档！');
INSERT INTO `cfg_lang` VALUES ('NOT_VAILD_TREE', '无效树!');
INSERT INTO `cfg_lang` VALUES ('NOT_VAILD_URL', '无效URL!');
INSERT INTO `cfg_lang` VALUES ('NOT_VALID_NODE', '找不到目标文档！');
INSERT INTO `cfg_lang` VALUES ('NOT_VALID_NODE_ID', '无效节点id!');
INSERT INTO `cfg_lang` VALUES ('NOT_VALID_QUQI', '您不是该公司成员或该团队不存在，请检查后重试');
INSERT INTO `cfg_lang` VALUES ('NOT_YOUR_PRIVATE_SERVICE', '不是你的私人空间!');
INSERT INTO `cfg_lang` VALUES ('NOT_YOUR_PRIVATE_TREE', '不是你的私人空间!');
INSERT INTO `cfg_lang` VALUES ('NO_FILE_FOR_SMASH', '没有需要粉碎的文件!');
INSERT INTO `cfg_lang` VALUES ('NO_INVITE_CODE', '无邀请码');
INSERT INTO `cfg_lang` VALUES ('NO_JOYPORT', '');
INSERT INTO `cfg_lang` VALUES ('NO_TREE_CAN_DISPLAY', '没有找到树!');
INSERT INTO `cfg_lang` VALUES ('office file convert fail', 'office文件转换失败');
INSERT INTO `cfg_lang` VALUES ('ONLY_ADMIN_CAN_COPY_MULTI_FILE', '只有管理员可以进行企业间多文件复制');
INSERT INTO `cfg_lang` VALUES ('ONLY_BOSS_CAN_CREATE_FIRST_DIRECTORY', '只有团队Boss能创建根节点目录!');
INSERT INTO `cfg_lang` VALUES ('OPERATE_DETAIL', '由');
INSERT INTO `cfg_lang` VALUES ('OPERATE_DETAIL_1', '由');
INSERT INTO `cfg_lang` VALUES ('OPERATE_DETAIL_2', '转移至');
INSERT INTO `cfg_lang` VALUES ('OUT_OF_MULTI_DOWNLOAD_SIZE', '批量下载文件大小最大支持5G');
INSERT INTO `cfg_lang` VALUES ('PARAM ERROR', '参数错误!');
INSERT INTO `cfg_lang` VALUES ('PARENT_AGENT_COST', '父团队代扣');
INSERT INTO `cfg_lang` VALUES ('PARENT_COMPANY_EXIST', '父团队已存在');
INSERT INTO `cfg_lang` VALUES ('PARENT_COMPANY_NOT_EXIST', '父团队不存在');
INSERT INTO `cfg_lang` VALUES ('PARENT_COPY_PERMISSION_ERROR', '团队间仅允许单个文档复制，如有大量文档需系统管理员进行复制');
INSERT INTO `cfg_lang` VALUES ('PARENT_HAD_SET_WATERMARK', '父目录已被设置水印');
INSERT INTO `cfg_lang` VALUES ('PARENT_WATERMARK_IS_ON', '请在上级文件夹设置水印');
INSERT INTO `cfg_lang` VALUES ('PASSIVE_REGISTER', '被动');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_ALREADY_BIND_DING', '账号已经绑定钉钉');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_ALREADY_IN_COMPANY', '账号已经是该团队成员');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_FROZEN', '登录失败次数过多，请稍后再试');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_NAME_ERROR', '姓名错误');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_NOT_ACTIVATE', '密码未激活');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_NOT_BIND_PHONE', '当前账号未绑定手机');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_NOT_EXIST', '账号不存在');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_OR_PASSWORD_ERROR', '手机号或密码错误');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_SERVICE_CANNT_ADD_COMMENT_GROUP', '曲奇笔记不可创建评论群');
INSERT INTO `cfg_lang` VALUES ('PASSPORT_TREE_MAX_DOC', '曲奇笔记文档数量已达到上限!');
INSERT INTO `cfg_lang` VALUES ('PASSWORD_ERROR', '密码错误');
INSERT INTO `cfg_lang` VALUES ('PASSWORD_NOT_VALID', '密码格式不符');
INSERT INTO `cfg_lang` VALUES ('PASSWORD_REGISTERED', '该手机号码已经注册过曲奇');
INSERT INTO `cfg_lang` VALUES ('PASTE_FILE_DETAIL', '粘贴了文件');
INSERT INTO `cfg_lang` VALUES ('PATH PARAM ERROR', '路径错误!');
INSERT INTO `cfg_lang` VALUES ('PAY_DETAIL', '充值');
INSERT INTO `cfg_lang` VALUES ('PAY_GIFT_DETAIL', '充值赠送');
INSERT INTO `cfg_lang` VALUES ('PAY_MONEY_ERROR', '充值金额错误');
INSERT INTO `cfg_lang` VALUES ('PERMARENT_CODE_EMPTY', '企业的永久授权码不可为空');
INSERT INTO `cfg_lang` VALUES ('PERMISSION_DENIED', '没有权限!');
INSERT INTO `cfg_lang` VALUES ('PERMISSION_DIR_USER_TITLE_1', '目录/文件');
INSERT INTO `cfg_lang` VALUES ('PERMISSION_DIR_USER_TITLE_2', '管理');
INSERT INTO `cfg_lang` VALUES ('PERMISSION_DIR_USER_TITLE_3', '编辑');
INSERT INTO `cfg_lang` VALUES ('PERMISSION_DIR_USER_TITLE_4', '查阅');
INSERT INTO `cfg_lang` VALUES ('PERSONAL_COMPANY_NAME', '的团队');
INSERT INTO `cfg_lang` VALUES ('PERSONAL_TEAM_NAME', '个人云盘');
INSERT INTO `cfg_lang` VALUES ('PHONE', '手机号');
INSERT INTO `cfg_lang` VALUES ('PHONE_ALREAD_EXIST', '手机号已存在');
INSERT INTO `cfg_lang` VALUES ('PHONE_BINDED_DING', '该手机已绑定其他钉钉');
INSERT INTO `cfg_lang` VALUES ('PHONE_BINDED_WECHAT', '该手机已绑定其他微信');
INSERT INTO `cfg_lang` VALUES ('PHONE_EMPTY', '手机号为空');
INSERT INTO `cfg_lang` VALUES ('PHONE_ERROR', '该手机未注册曲奇账号');
INSERT INTO `cfg_lang` VALUES ('PHONE_IS_USED', '该手机已注册曲奇账号');
INSERT INTO `cfg_lang` VALUES ('PHONE_NOT_VALID', '手机号格式错误');
INSERT INTO `cfg_lang` VALUES ('PRIVATE_TREE_NOT_GROUP', '私有树!');
INSERT INTO `cfg_lang` VALUES ('PRIVATE_TREE_NOT_PERMISSION', '私有树没有权限设置！');
INSERT INTO `cfg_lang` VALUES ('PRIVATE_TREE_NOT_STAFF', '个人空间没有员工!');
INSERT INTO `cfg_lang` VALUES ('PUSH_DATA_TEST', '编码');
INSERT INTO `cfg_lang` VALUES ('QUIT_USER_FAIL', '退出团队失败');
INSERT INTO `cfg_lang` VALUES ('QUQI', '曲奇');
INSERT INTO `cfg_lang` VALUES ('QUQI_BETA_REGISTER_TIP', '曲奇正在内测中，暂时只对内测用户开放，尽请谅解！');
INSERT INTO `cfg_lang` VALUES ('QUQI_COMPANY', '多人');
INSERT INTO `cfg_lang` VALUES ('QUQI_DOC', '曲奇文档');
INSERT INTO `cfg_lang` VALUES ('QUQI_ID_NOT_FIND', 'quqi_id不存在');
INSERT INTO `cfg_lang` VALUES ('QUQI_NOT_FOUND', '账号不存在!');
INSERT INTO `cfg_lang` VALUES ('QUQI_NOT_MATCH_NAME', '填写的团队名称与曲奇号不匹配，请检查后重试');
INSERT INTO `cfg_lang` VALUES ('QUQI_PERSON_COMPANY', '个人');
INSERT INTO `cfg_lang` VALUES ('QUQI_SERVER_REQUEST_FAIL', '请求失败');
INSERT INTO `cfg_lang` VALUES ('QUQI_SHARE_IS_OFF', '此曲奇发布功能未开启');
INSERT INTO `cfg_lang` VALUES ('READ_WATERMARK_IS_OFF', '水印功能已关闭');
INSERT INTO `cfg_lang` VALUES ('RECYCLE_OUT_SPACE', '回收站空间不足，请系统管理员清理回收站');
INSERT INTO `cfg_lang` VALUES ('RECYCLE_PREVIEW_VAILD', '删除预览功能未开通!');
INSERT INTO `cfg_lang` VALUES ('redirect', '账号异常，请刷新页面后重试');
INSERT INTO `cfg_lang` VALUES ('REGISTER_CREATE_COMPANY', '注册时创建团队');
INSERT INTO `cfg_lang` VALUES ('REGISTER_FAIL', '注册失败');
INSERT INTO `cfg_lang` VALUES ('REGISTER_GIFT', '注册赠送');
INSERT INTO `cfg_lang` VALUES ('REGISTER_GIFT_DETAIL', '注册赠送');
INSERT INTO `cfg_lang` VALUES ('REGISTER_USER_NAME', '注册人');
INSERT INTO `cfg_lang` VALUES ('REMOVE_ADMIN_PERMISSION_2', '的管理权限');
INSERT INTO `cfg_lang` VALUES ('REMOVE_PERMISSION_1', '取消');
INSERT INTO `cfg_lang` VALUES ('REMOVE_READ_PERMISSION_2', '的查阅权限');
INSERT INTO `cfg_lang` VALUES ('REMOVE_WRITE_PERMISSION_2', '的编辑权限');
INSERT INTO `cfg_lang` VALUES ('RENAME_COMPANY', '重命名');
INSERT INTO `cfg_lang` VALUES ('RENAME_COMPANY_DETAIL', '修改团队名称');
INSERT INTO `cfg_lang` VALUES ('RENAME_DIR', '重命名');
INSERT INTO `cfg_lang` VALUES ('RENAME_DIR_DETAIL', '重命名文件夹');
INSERT INTO `cfg_lang` VALUES ('RENAME_DOC', '重命名');
INSERT INTO `cfg_lang` VALUES ('RENAME_DOC_DETAIL', '重命名文档');
INSERT INTO `cfg_lang` VALUES ('RENAME_FAIL', '重命名失败!');
INSERT INTO `cfg_lang` VALUES ('RENAME_IS_EXISTS', '重命名已存在!');
INSERT INTO `cfg_lang` VALUES ('RENAME_IS_NULL', '重命名不能为空!');
INSERT INTO `cfg_lang` VALUES ('RENAME_OP_1', '重命名《');
INSERT INTO `cfg_lang` VALUES ('RENAME_OP_2', '》');
INSERT INTO `cfg_lang` VALUES ('REPORT_ID_NULL', '报告ID错误');
INSERT INTO `cfg_lang` VALUES ('REPORT_NAME_EMPTY', '报告名称为空');
INSERT INTO `cfg_lang` VALUES ('REPORT_WEEKLY_TIP', '至');
INSERT INTO `cfg_lang` VALUES ('RESTORE_DIR', '复原');
INSERT INTO `cfg_lang` VALUES ('RESTORE_DIR_DETAIL', '复原了文件夹');
INSERT INTO `cfg_lang` VALUES ('RESTORE_FILE', '复原');
INSERT INTO `cfg_lang` VALUES ('RESTORE_FILE_DETAIL', '复原了文件');
INSERT INTO `cfg_lang` VALUES ('REUPLOAD_EXT_NOT_SAME', '请上传相同后缀的文件!');
INSERT INTO `cfg_lang` VALUES ('REUPLOAD_FILE', '上传');
INSERT INTO `cfg_lang` VALUES ('REUPLOAD_FILE_DETAIL', '上传新版本');
INSERT INTO `cfg_lang` VALUES ('RIGHT_BRACKET', '】');
INSERT INTO `cfg_lang` VALUES ('SAME_NAME_NODE_EXISTS', '重复命名!');
INSERT INTO `cfg_lang` VALUES ('SAVE DRAFT FAIL', '草稿保存失败!');
INSERT INTO `cfg_lang` VALUES ('SAVE_CONTENT_FAIL', '保存内容失败!');
INSERT INTO `cfg_lang` VALUES ('SERVER_ERROR', '服务器内部错误');
INSERT INTO `cfg_lang` VALUES ('SET_PERMISSION', '修改节点权限');
INSERT INTO `cfg_lang` VALUES ('SEVER_ERROR', '服务器内部错误');
INSERT INTO `cfg_lang` VALUES ('SHARE_DIR', '分享');
INSERT INTO `cfg_lang` VALUES ('SHARE_DIR_DETAIL', '分享文件夹');
INSERT INTO `cfg_lang` VALUES ('SHARE_DOC', '分享');
INSERT INTO `cfg_lang` VALUES ('SHARE_DOC_DETAIL', '分享文档');
INSERT INTO `cfg_lang` VALUES ('SHARE_EXPIRED', '发布已超时');
INSERT INTO `cfg_lang` VALUES ('SHARE_EXPIRED_TIME_UNVALID', '发布时间不符合格式');
INSERT INTO `cfg_lang` VALUES ('SHARE_INFO_NOT_CORRESPOND', '发布信息不对应');
INSERT INTO `cfg_lang` VALUES ('SHARE_IS_STOP', '发布已停止');
INSERT INTO `cfg_lang` VALUES ('SHARE_NODE_LIMIT_TIMES', '单个文档最多发布50次');
INSERT INTO `cfg_lang` VALUES ('SHARE_NOT_CORRESPOND_INTERFACE', '请调用对应于发布类型的接口');
INSERT INTO `cfg_lang` VALUES ('SHARE_NOT_EXIST', '发布不存在');
INSERT INTO `cfg_lang` VALUES ('SHARE_NOT_IN_SHARING', '不在发布中');
INSERT INTO `cfg_lang` VALUES ('SHARE_NO_PERMISSION_VIEW_NODE', '发布没有权限查看此文档');
INSERT INTO `cfg_lang` VALUES ('SHARE_OVERRUN', '发布已达最大查阅人数');
INSERT INTO `cfg_lang` VALUES ('SHARE_REGISTER', '外发');
INSERT INTO `cfg_lang` VALUES ('SHARE_SET_CANT_DOWNLOAD', '此发布文档不可下载');
INSERT INTO `cfg_lang` VALUES ('SHARE_TYPE_UNVALID', '发布类型无效');
INSERT INTO `cfg_lang` VALUES ('SHARE_VIEW_NUMBER_LIMIT_CANT_SMALLER', '最大发布人数不可更小');
INSERT INTO `cfg_lang` VALUES ('SHARE_VIEW_NUMBER_LIMIT_UNVALID', '最大发布人数无效');
INSERT INTO `cfg_lang` VALUES ('SHARE_VIEW_TIPS_1', '可以请负责人（ ');
INSERT INTO `cfg_lang` VALUES ('SHARE_VIEW_TIPS_2', '）给你开通权限哦~');
INSERT INTO `cfg_lang` VALUES ('SIGN_ERROR', '签名错误');
INSERT INTO `cfg_lang` VALUES ('SOURCE_NODE_NOT_FOUND', '源节点不存在!');
INSERT INTO `cfg_lang` VALUES ('SOURCE_NOT_EXISTS', '资源不存在!');
INSERT INTO `cfg_lang` VALUES ('STORAGE_RUN_OUT', '）的容量已经达到上限，我们提醒您及时扩容，以保证功能的正常使用。');
INSERT INTO `cfg_lang` VALUES ('SUPER_COPY_DIR', '复制');
INSERT INTO `cfg_lang` VALUES ('SUPER_COPY_DIR_DETAIL', '跨树复制文件夹');
INSERT INTO `cfg_lang` VALUES ('SUPER_COPY_DOC', '复制');
INSERT INTO `cfg_lang` VALUES ('SUPER_COPY_DOC_DETAIL', '跨树复制文档');
INSERT INTO `cfg_lang` VALUES ('SUPER_MOVE_DIR', '修改路径');
INSERT INTO `cfg_lang` VALUES ('SUPER_MOVE_DIR_DETAIL', '跨树迁移文件夹');
INSERT INTO `cfg_lang` VALUES ('SUPER_MOVE_DOC', '修改路径');
INSERT INTO `cfg_lang` VALUES ('SUPER_MOVE_DOC_DETAIL', '跨树迁移文档');
INSERT INTO `cfg_lang` VALUES ('TASK_ACCEPTANCE_PLUGIN_ADD_1', '新增任务验收人');
INSERT INTO `cfg_lang` VALUES ('TASK_ACCEPTANCE_PLUGIN_DELETE_1', '删除了任务验收人');
INSERT INTO `cfg_lang` VALUES ('TASK_ACCEPTANCE_PLUGIN_EDIT_1', '将验收人由');
INSERT INTO `cfg_lang` VALUES ('TASK_ADD', '发起了任务');
INSERT INTO `cfg_lang` VALUES ('TASK_BELONG_PLUGIN_ADD_1', '新增任务归属团队');
INSERT INTO `cfg_lang` VALUES ('TASK_DEADLINE_PLUGIN_ADD_1', '新增任务截止时间');
INSERT INTO `cfg_lang` VALUES ('TASK_DEADLINE_PLUGIN_DELETE_1', '删除了任务截止时间');
INSERT INTO `cfg_lang` VALUES ('TASK_DEADLINE_PLUGIN_EDIT_1', '将任务截止时间由');
INSERT INTO `cfg_lang` VALUES ('TASK_DESC_PLUGIN_ADD_1', '新增任务描述：');
INSERT INTO `cfg_lang` VALUES ('TASK_DESC_PLUGIN_DELETE_1', '删除了任务描述');
INSERT INTO `cfg_lang` VALUES ('TASK_DESC_PLUGIN_EDIT_1', '变更任务描述为：');
INSERT INTO `cfg_lang` VALUES ('TASK_INIVITATION_MESSAGE_ACCEPT', '已同意');
INSERT INTO `cfg_lang` VALUES ('TASK_INIVITATION_MESSAGE_RECALL', '已撤回');
INSERT INTO `cfg_lang` VALUES ('TASK_INIVITATION_MESSAGE_REFUSE', '已拒绝');
INSERT INTO `cfg_lang` VALUES ('TASK_MEMBER_PLUGIN_ADD_1', '将');
INSERT INTO `cfg_lang` VALUES ('TASK_MEMBER_PLUGIN_ADD_2', '加入任务');
INSERT INTO `cfg_lang` VALUES ('TASK_PRINCIPAL_INIVITATION_MESSAGE', '邀请你成为任务负责人');
INSERT INTO `cfg_lang` VALUES ('TASK_PRINCIPAL_PLUGIN_ADD_1', '新增任务负责人');
INSERT INTO `cfg_lang` VALUES ('TASK_PRINCIPAL_PLUGIN_DELETE_1', '删除了任务负责人');
INSERT INTO `cfg_lang` VALUES ('TASK_PRINCIPAL_PLUGIN_EDIT_1', '将负责人由');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_ADD_1', '新增任务优先级');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_DELETE_1', '删除了任务优先级');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_EDIT_1', '将任务优先级由');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_EDIT_2', '调整至');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_LEVEL_1', '普通');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_LEVEL_2', '紧急');
INSERT INTO `cfg_lang` VALUES ('TASK_PRIORITY_PLUGIN_LEVEL_3', '非常紧急');
INSERT INTO `cfg_lang` VALUES ('TASK_REOPEN', '重新打开了任务');
INSERT INTO `cfg_lang` VALUES ('TASK_STATUS_0', '进行中');
INSERT INTO `cfg_lang` VALUES ('TASK_STATUS_1', '已完成');
INSERT INTO `cfg_lang` VALUES ('TASK_STATUS_2', '已关闭');
INSERT INTO `cfg_lang` VALUES ('TASK_STATUS_EDIT_1', '将任务状态由');
INSERT INTO `cfg_lang` VALUES ('TEAM_EDITION_COMPANY_NOT_CHILD', '团队版不可以创建子团队');
INSERT INTO `cfg_lang` VALUES ('TEAM_EDITION_NOT_API', '团队版此接口不可用');
INSERT INTO `cfg_lang` VALUES ('TEAM_EDITION_SET_BOSS_FAIL', '团队版设置boss参数错误');
INSERT INTO `cfg_lang` VALUES ('TEAM_EDITION_STORAGE_ALARM', '文档容量即将到达上限。您可以联系客服试用企业版曲奇，获取更大容量。');
INSERT INTO `cfg_lang` VALUES ('TEAM_EDITION_STORAGE_OVERRUN', '团队文档总容量已超出限制。请联系客服试用企业版曲奇，获取更大容量。');
INSERT INTO `cfg_lang` VALUES ('TEMP_AUTH_CODE_IS_EMPTY', '临时授权码不可为空');
INSERT INTO `cfg_lang` VALUES ('THIS_SHARE_CANT_EDIT', '此发布文档不可编辑');
INSERT INTO `cfg_lang` VALUES ('THIS_SHARE_DOC_CANT_DOWNLOAD', '此文档类型不可下载/导出');
INSERT INTO `cfg_lang` VALUES ('THIS_SHARE_DOC_CANT_HAS_WATERMARK', '此文档类型不可添加水印');
INSERT INTO `cfg_lang` VALUES ('TODAY_COST', '扣费:');
INSERT INTO `cfg_lang` VALUES ('TRANSFORM_DOC', '转换');
INSERT INTO `cfg_lang` VALUES ('TRANSFORM_DOC_DETAIL', '转换为曲奇文档');
INSERT INTO `cfg_lang` VALUES ('TRANSFORM_XLS', '转换');
INSERT INTO `cfg_lang` VALUES ('TRANSFORM_XLS_DETAIL', '转换为曲奇表格');
INSERT INTO `cfg_lang` VALUES ('TREE_ID_IS_NOT_VALID', '无效树id!');
INSERT INTO `cfg_lang` VALUES ('TREE_NOT_FOUND', '文档树不存在!');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY', '待合并账号在某个公司中已存在用户，请删除后再试！');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY_1', '手机账号存在与当前账号相同团队：');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY_2', '【');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY_3', '】、');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY_4', '】，');
INSERT INTO `cfg_lang` VALUES ('TWO_PASSPORT_IN_SAME_COMPANY_5', '请先退出该团队后再进行绑定。');
INSERT INTO `cfg_lang` VALUES ('UNBIND_DING_FAIL', '解绑钉钉账号失败');
INSERT INTO `cfg_lang` VALUES ('UNBIND_WECHAT_FAIL', '解绑微信失败！');
INSERT INTO `cfg_lang` VALUES ('UNFOLLOW_FAILED', '取消关注失败!');
INSERT INTO `cfg_lang` VALUES ('UNKNOWN_ERROR', '未知错误!');
INSERT INTO `cfg_lang` VALUES ('UNSHARE_DIR', '取消分享');
INSERT INTO `cfg_lang` VALUES ('UNSHARE_DIR_DETAIL', '取消分享文件夹');
INSERT INTO `cfg_lang` VALUES ('UNSHARE_DOC', '取消分享');
INSERT INTO `cfg_lang` VALUES ('UNSHARE_DOC_DETAIL', '取消分享文档');
INSERT INTO `cfg_lang` VALUES ('UPDATE_COMMENT_GROUP_ACCESS_TOKEN_FAIL', '更新评论群组token失败');
INSERT INTO `cfg_lang` VALUES ('UPDATE_DEPARTMENT_NAME_FAIL', '修改部门名失败');
INSERT INTO `cfg_lang` VALUES ('UPDATE_DEPARTMENT_PARENT_FAIL', '移动部门失败');
INSERT INTO `cfg_lang` VALUES ('UPDOWN_UNKNOWN_ERROR', '上传失败，请稍后重试');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_DIR', '上传');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_DIR_DETAIL', '上传文件夹');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_FAIL', '上传失败');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_FILE', '上传');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_FILE_DETAIL', '上传附件');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_FOLDER_DETAIL', '上传文件夹');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_NEW_VERSION', '上传');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_NEW_VERSION_DETAIL', '上传新版本');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_SIZE_TOO_LARGE_1', '上传文件过大,只能上传');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_SIZE_TOO_LARGE_2', 'M大小以下的文件');
INSERT INTO `cfg_lang` VALUES ('UPLOAD_TOO_LARGE', '上传头像过大，请压缩后重试');
INSERT INTO `cfg_lang` VALUES ('URL_EMPTY', 'URL不可为空');
INSERT INTO `cfg_lang` VALUES ('USER_ID_ERROR', 'user_id错误');
INSERT INTO `cfg_lang` VALUES ('USER_INVITE_REGISTER', '用户邀请');
INSERT INTO `cfg_lang` VALUES ('USER_NAME', '用户名');
INSERT INTO `cfg_lang` VALUES ('USER_NAME_EMPTY', '用户名为空');
INSERT INTO `cfg_lang` VALUES ('USER_NOT_DEPARTMENT', '用户部门错误');
INSERT INTO `cfg_lang` VALUES ('USER_NOT_FOUND', '用户不存在!');
INSERT INTO `cfg_lang` VALUES ('USER_NOT_MEMBER_OF_COMPANY', '非公司成员!');
INSERT INTO `cfg_lang` VALUES ('VALIDATE_CODE_ERROR', '验证码错误！');
INSERT INTO `cfg_lang` VALUES ('VALIDATE_CODE_EXPIRED', '验证码已过期');
INSERT INTO `cfg_lang` VALUES ('VEST_IN', '归属于');
INSERT INTO `cfg_lang` VALUES ('VIP_EXPIRED_1', '您的文档系统（');
INSERT INTO `cfg_lang` VALUES ('VIP_EXPIRED_2', '）会员已经到期，还有');
INSERT INTO `cfg_lang` VALUES ('VIP_EXPIRED_3', '个工作日将会清空内容，请及时续费。');
INSERT INTO `cfg_lang` VALUES ('VIP_FUNCTION_LIMITED', 'vip等级不足，功能被限制！');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_GIFT_DETAIL', '曲奇券充值');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_INVALID', '曲奇券无效!');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_CREATE_COMPANY_1', '已成功创建团队');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_CREATE_COMPANY_2', '好友首次充值200元以上，将再赠送你10000曲奇券哦！');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_PAY_MINT_MONEY_1', '已为团队进行充值啦');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_PAY_MINT_MONEY_2', '快去邀请其他好友注册曲奇吧！');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_REGISTER_PASSPORT_1', '已成功注册账号');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_REGISTER_PASSPORT_2', '推荐好友创建团队有更多惊喜哦！');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_SYSTEM_GIFT_TIP', '恭喜');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_TIP_1', '您邀请的好友');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_TIP_2', '，系统赠送您价值');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_TIP_3', '曲奇币的曲奇优惠券一张，请在【个人账号管理】-【曲奇券】中查看和使用。');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_NOTIFICATION_TITLE', '曲奇券到账提示');
INSERT INTO `cfg_lang` VALUES ('VOUCHER_USE_DETAIL', '曲奇券兑换');
INSERT INTO `cfg_lang` VALUES ('WATERMARK_CANT_DOWNLOAD', '开启水印的文档不可下载');
INSERT INTO `cfg_lang` VALUES ('WECHAT_PUBLIC_SUBSCRIBE_REPLY', '【曲奇办公，是一种管理方式】欢迎关注曲奇办公，曲奇办公是一款以文档为载体的“轻量级”企业办公管理应用。如果您正在用word、Excel等文档作为管理工具的话，曲奇办公可以帮您做得更好！');
INSERT INTO `cfg_lang` VALUES ('WECHAT_PUBLIC_YUN_PAN_SUBSCRIBE_REPLY', '您好，欢迎关注曲奇云盘，体验云端协同办公，遇见更高效的自己！\n在这里您可以了解曲奇云盘功能和场景使用，也可以随时留言咨询我们任何产品问题。');
INSERT INTO `cfg_lang` VALUES ('WECHAT_SNS_SCOPE_NEED_SNSAPI_USERINFO', 'scope应该为snsapi_userinfo');
INSERT INTO `cfg_lang` VALUES ('XLS_TRANSFORM_SAME_NAME_NODE_EXISTS', '已有同名曲奇表格存在，请重命名后再进行转换');
INSERT INTO `cfg_lang` VALUES ('YOU_CANT_EDIT_SHARE_DOC', '无法编辑此发布文档');
```

## 新增数据表并同步内容
- cfg_center_server
- cfg_session_server
- cfg_notify_server
- cfg_push_server
- cfg_auth_server
- cfg_quqi_server
- cfg_doc_server
- cfg_approval_server
- cfg_chat_server
- cfg_vip
- cfg_updown_server
- cfg_cache_server
- cfg_ext

```
CREATE TABLE `cfg_center_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id',
  `server_id` int(11) NOT NULL,
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL,
  `node_local_ip` varchar(50) DEFAULT NULL,
  `node_name` varchar(50) DEFAULT NULL,
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL,
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_center_server
-- ----------------------------
INSERT INTO `cfg_center_server` VALUES ('127.0.0.1', '1', 'fcgi_server', '10002', '500', '2', '2', '', null, '', '127.0.0.1', 'center', '2', '.*.quqi.com$', '', '3');

CREATE TABLE `cfg_session_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0',
  `node_type` varchar(50) DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2',
  `node_local_ip` varchar(50) NOT NULL DEFAULT '' COMMENT '运行服务器的ip',
  `node_name` varchar(50) DEFAULT NULL COMMENT 'quqiserver节点名称',
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法',
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_session_server
-- ----------------------------
INSERT INTO `cfg_session_server` VALUES ('127.0.0.1', '1', '1', 'fcgi_server', '10020', '500', '2', '2', '', null, '', '127.0.0.1', 'session_demo', '2', '', '', '3');

CREATE TABLE `cfg_notify_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0',
  `server_id` int(11) NOT NULL,
  `auth_id` int(11) NOT NULL DEFAULT '0',
  `session_id` int(11) NOT NULL DEFAULT '1',
  `db_id` int(11) NOT NULL DEFAULT '0',
  `node_type` varchar(50) DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2',
  `node_local_ip` varchar(50) NOT NULL DEFAULT '' COMMENT '运行服务器的ip',
  `node_name` varchar(50) DEFAULT NULL COMMENT 'quqiserver节点名称',
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法',
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  `server_domain` varchar(255) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_notify_server
-- ----------------------------
INSERT INTO `cfg_notify_server` VALUES ('127.0.0.1', '1', '1', '1', '1', 'fcgi_server', '10030', '500', '2', '2', '', null, '', '127.0.0.1', 'notify_demo', '2', '', '', '3', '');

CREATE TABLE `cfg_push_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定server_id',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0' COMMENT '数据库配置',
  `session_id` int(11) NOT NULL DEFAULT '1',
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL,
  `node_local_ip` varchar(50) DEFAULT NULL,
  `node_name` varchar(50) DEFAULT NULL,
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL,
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='实时推送消息服务器配置';

-- ----------------------------
-- Records of cfg_push_server
-- ----------------------------
INSERT INTO `cfg_push_server` VALUES ('127.0.0.1', '1', '1', '1', 'fcgi_server', '10100', '500', '2', '2', '127.0.0.1', '9222', null, '127.0.0.1', 'push_local', '2', '.quqi.com', null, '3');

CREATE TABLE `cfg_auth_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0' COMMENT 'auth数据库配置',
  `secret_code_db_id` int(11) NOT NULL,
  `session_id` int(11) NOT NULL DEFAULT '1',
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL,
  `node_local_ip` varchar(50) DEFAULT NULL,
  `node_name` varchar(50) DEFAULT NULL,
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL,
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_auth_server
-- ----------------------------
INSERT INTO `cfg_auth_server` VALUES ('127.0.0.1', '1', '1', '1', '1', 'fcgi_server', '10010', '500', '2', '2', ' ', null, '', '127.0.0.1', 'auth_demo', '2', '', '', '3');
DROP TABLE IF EXISTS `cfg_quqi_server`;
CREATE TABLE `cfg_quqi_server` (
  `server_ip` varchar(50) NOT NULL,
  `server_id` int(11) NOT NULL,
  `auth_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应auth服务器连接配置',
  `notify_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应notify服务器连接配置',
  `session_id` int(11) NOT NULL DEFAULT '1',
  `updown_id` int(11) NOT NULL,
  `node_type` varchar(50) DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2',
  `node_local_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '运行服务器的ip',
  `node_name` varchar(50) DEFAULT NULL COMMENT 'quqiserver节点名称',
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法',
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `worker_load` int(11) NOT NULL DEFAULT '1',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`),
  UNIQUE KEY `node_local_ip_node_listen_port` (`node_local_ip`,`node_listen_port`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_quqi_server
-- ----------------------------
INSERT INTO `cfg_quqi_server` VALUES ('127.0.0.1', '1', '1', '1', '1', '1', 'fcgi_server', '10060', '500', '1', '1', '', null, '', '127.0.0.1', 'quqi_demo', '2', '.quqi.com', '', '1', '3');
DROP TABLE IF EXISTS `cfg_doc_server`;
CREATE TABLE `cfg_doc_server` (
  `server_ip` varchar(50) NOT NULL,
  `server_id` int(11) NOT NULL,
  `auth_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应auth服务器连接配置',
  `notify_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应notify服务器连接配置',
  `session_id` int(11) NOT NULL DEFAULT '1',
  `updown_id` int(11) NOT NULL,
  `node_type` varchar(50) DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2',
  `node_local_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '运行服务器的ip',
  `node_name` varchar(50) DEFAULT NULL COMMENT 'quqiserver节点名称',
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法',
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `worker_load` int(11) NOT NULL DEFAULT '1',
  `node_server_option` int(11) NOT NULL,
  `quqi_server_id` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`),
  UNIQUE KEY `node_local_ip_node_listen_port` (`node_local_ip`,`node_listen_port`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_doc_server
-- ----------------------------
INSERT INTO `cfg_doc_server` VALUES ('127.0.0.1', '1', '1', '1', '1', '1', 'fcgi_server', '10070', '500', '1', '1', '', null, '', '127.0.0.1', 'doc_demo', '2', 'quqi.com', '', '1', '3', '1');

DROP TABLE IF EXISTS `cfg_approval_server`;
CREATE TABLE `cfg_approval_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定server_id',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0' COMMENT '数据库配置',
  `auth_id` int(11) NOT NULL DEFAULT '1',
  `session_id` int(11) NOT NULL DEFAULT '1',
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL,
  `node_local_ip` varchar(50) DEFAULT NULL,
  `node_name` varchar(50) DEFAULT NULL,
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL,
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='待办服务器配置';

-- ----------------------------
-- Records of cfg_approval_server
-- ----------------------------
INSERT INTO `cfg_approval_server` VALUES ('127.0.0.1', '1', '1', '1', '1', 'fcgi_server', '10090', '500', '2', '2', '127.0.0.1', '9222', null, '127.0.0.1', '', '2', '.quqi.com', null, '3');

DROP TABLE IF EXISTS `cfg_chat_server`;
CREATE TABLE `cfg_chat_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0',
  `node_type` varchar(50) DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2',
  `node_local_ip` varchar(50) NOT NULL DEFAULT '' COMMENT '运行服务器的ip',
  `node_name` varchar(50) DEFAULT NULL COMMENT 'quqiserver节点名称',
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法',
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  PRIMARY KEY (`server_ip`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='chat服务器配置';

-- ----------------------------
-- Records of cfg_chat_server
-- ----------------------------
INSERT INTO `cfg_chat_server` VALUES ('127.0.0.1', '1', '1', 'fcgi_server', '20030', '500', '2', '2', '', null, '', '127.0.0.1', 'chat_local', '2', '.quqi.com', '', '3');

DROP TABLE IF EXISTS `cfg_vip`;
CREATE TABLE `cfg_vip` (
  `level` int(10) NOT NULL COMMENT 'VIP等级',
  `name` varchar(255) NOT NULL DEFAULT '' COMMENT 'VIP名称',
  `price` double NOT NULL COMMENT '需要累计充值金额',
  `recycle_num` int(11) NOT NULL COMMENT '回收站上限文件数量',
  `upload_size` int(11) NOT NULL COMMENT '上传文件最大大小，单位M',
  `config` text NOT NULL COMMENT '功能配置信息，功能开关字符串',
  PRIMARY KEY (`level`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_vip
-- ----------------------------
INSERT INTO `cfg_vip` VALUES ('0', 'VIP0', '0', '100', '10', '00000');
INSERT INTO `cfg_vip` VALUES ('1', 'VIP1', '100', '200', '20', '10000');
INSERT INTO `cfg_vip` VALUES ('2', 'VIP2', '200', '300', '40', '11000');
INSERT INTO `cfg_vip` VALUES ('3', 'VIP3', '500', '450', '60', '11100');
INSERT INTO `cfg_vip` VALUES ('4', 'VIP4', '1000', '700', '80', '11110');
INSERT INTO `cfg_vip` VALUES ('5', 'VIP5', '2000', '1000', '100', '11111');
INSERT INTO `cfg_vip` VALUES ('6', 'VIP6', '5000', '1400', '200', '11111');
INSERT INTO `cfg_vip` VALUES ('7', 'VIP7', '10000', '2000', '400', '11111');
INSERT INTO `cfg_vip` VALUES ('8', 'VIP8', '20000', '3000', '600', '11111');
INSERT INTO `cfg_vip` VALUES ('9', 'VIP9', '50000', '4500', '800', '11111');
INSERT INTO `cfg_vip` VALUES ('10', 'VIP10', '100000', '7000', '1024', '11111');

DROP TABLE IF EXISTS `cfg_updown_server`;
CREATE TABLE `cfg_updown_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id',
  `server_id` int(11) NOT NULL,
  `db_id` int(11) NOT NULL DEFAULT '0',
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `node_listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `node_backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `node_net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `node_net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  `node_server_ip` varchar(50) DEFAULT '127.0.0.1',
  `node_server_port` int(11) DEFAULT '9222' COMMENT '上层连接服务器端口号',
  `node_actions` varchar(255) DEFAULT NULL,
  `node_local_ip` varchar(50) DEFAULT NULL,
  `node_name` varchar(50) DEFAULT NULL,
  `node_waiting_time` int(11) DEFAULT '2' COMMENT '超时等待的时间，单位秒',
  `node_option_allow_url` varchar(50) DEFAULT NULL,
  `node_monitor_server_addresses` varchar(50) DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控',
  `node_server_option` int(11) NOT NULL,
  `server_domain` varchar(255) DEFAULT NULL,
  `weight` int(11) NOT NULL DEFAULT '1' COMMENT '被分配到的权重，越大概率越高',
  `status` int(11) NOT NULL COMMENT '服务器状态，0是关闭状态，1是启动状态，DocServer1分钟检测一次',
  PRIMARY KEY (`server_ip`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='auth服务器配置';

-- ----------------------------
-- Records of cfg_updown_server
-- ----------------------------
INSERT INTO `cfg_updown_server` VALUES ('127.0.0.1', '1', '1', 'fcgi_server', '10050', '500', '2', '2', '', null, '', '127.0.0.1', 'updown_demo_1', '2', '.*', '', '3', 'file.quqi.com', '100', '1');

DROP TABLE IF EXISTS `cfg_cache_server`;
CREATE TABLE `cfg_cache_server` (
  `server_ip` varchar(50) NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id',
  `server_id` int(11) NOT NULL,
  `node_type` varchar(50) NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型',
  `listen_port` int(11) NOT NULL DEFAULT '0' COMMENT '对外的fcgi监听端口',
  `backlog` int(11) DEFAULT '500' COMMENT '监听队列大小',
  `net_schedule_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数',
  `net_process_cnt` int(11) DEFAULT '2' COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数',
  PRIMARY KEY (`server_ip`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_cache_server
-- ----------------------------
INSERT INTO `cfg_cache_server` VALUES ('127.0.0.1', '1', 'fcgi_server', '10040', '500', '2', '2');

DROP TABLE IF EXISTS `cfg_ext`;
CREATE TABLE `cfg_ext` (
  `ext` varchar(25) NOT NULL DEFAULT '' COMMENT '文件后缀名',
  `doc_type` varchar(25) NOT NULL DEFAULT '' COMMENT '文档系统文件类型',
  PRIMARY KEY (`ext`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_ext
-- ----------------------------
INSERT INTO `cfg_ext` VALUES ('3gp', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('aac', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('aai', 'jp-aai');
INSERT INTO `cfg_ext` VALUES ('ai', 'jp-ai');
INSERT INTO `cfg_ext` VALUES ('aif', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('amr', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('apk', 'jp-apk');
INSERT INTO `cfg_ext` VALUES ('arj', 'jp-zip');
INSERT INTO `cfg_ext` VALUES ('art', 'jp-art');
INSERT INTO `cfg_ext` VALUES ('arw', 'jp-arw');
INSERT INTO `cfg_ext` VALUES ('asf', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('avi', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('avs', 'jp-avs');
INSERT INTO `cfg_ext` VALUES ('bat', 'jp-exe');
INSERT INTO `cfg_ext` VALUES ('beg', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('cals', 'jp-cals');
INSERT INTO `cfg_ext` VALUES ('cgm', 'jp-cgm');
INSERT INTO `cfg_ext` VALUES ('cin', 'jp-cin');
INSERT INTO `cfg_ext` VALUES ('cr2', 'jp-cr2');
INSERT INTO `cfg_ext` VALUES ('crw', 'jp-crw');
INSERT INTO `cfg_ext` VALUES ('csv', 'jp-csv');
INSERT INTO `cfg_ext` VALUES ('cur', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('cut', 'jp-cut');
INSERT INTO `cfg_ext` VALUES ('dcm', 'jp-dcm');
INSERT INTO `cfg_ext` VALUES ('dcr', 'jp-dcr');
INSERT INTO `cfg_ext` VALUES ('dcx', 'jp-dcx');
INSERT INTO `cfg_ext` VALUES ('dng', 'jp-dng');
INSERT INTO `cfg_ext` VALUES ('doc', 'jp-doc');
INSERT INTO `cfg_ext` VALUES ('docx', 'jp-doc');
INSERT INTO `cfg_ext` VALUES ('dot', 'jp-dot');
INSERT INTO `cfg_ext` VALUES ('dps', 'jp-dps');
INSERT INTO `cfg_ext` VALUES ('dpx', 'jp-dpx');
INSERT INTO `cfg_ext` VALUES ('epdf', 'jp-epdf');
INSERT INTO `cfg_ext` VALUES ('epi', 'jp-epi');
INSERT INTO `cfg_ext` VALUES ('eps', 'jp-eps');
INSERT INTO `cfg_ext` VALUES ('epsf', 'jp-epsf');
INSERT INTO `cfg_ext` VALUES ('epsi', 'jp-epsi');
INSERT INTO `cfg_ext` VALUES ('ept', 'jp-ept');
INSERT INTO `cfg_ext` VALUES ('et', 'jp-et');
INSERT INTO `cfg_ext` VALUES ('exe', 'jp-exe');
INSERT INTO `cfg_ext` VALUES ('exr', 'jp-exr');
INSERT INTO `cfg_ext` VALUES ('fax', 'jp-fax');
INSERT INTO `cfg_ext` VALUES ('fig', 'jp-fig');
INSERT INTO `cfg_ext` VALUES ('fits', 'jp-fits');
INSERT INTO `cfg_ext` VALUES ('flv', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('fpx', 'jp-fpx');
INSERT INTO `cfg_ext` VALUES ('gif', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('gplt', 'jp-gplt');
INSERT INTO `cfg_ext` VALUES ('gz', 'jp-zip');
INSERT INTO `cfg_ext` VALUES ('hdr', 'jp-hdr');
INSERT INTO `cfg_ext` VALUES ('hpgl', 'jp-hpgl');
INSERT INTO `cfg_ext` VALUES ('hrz', 'jp-hrz');
INSERT INTO `cfg_ext` VALUES ('html', 'jp-html');
INSERT INTO `cfg_ext` VALUES ('ico', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('ipa', 'jp-ipa');
INSERT INTO `cfg_ext` VALUES ('j2c', 'jp-j2c');
INSERT INTO `cfg_ext` VALUES ('j2k', 'jp-j2k');
INSERT INTO `cfg_ext` VALUES ('jbig', 'jp-jbig');
INSERT INTO `cfg_ext` VALUES ('jng', 'jp-jng');
INSERT INTO `cfg_ext` VALUES ('jp2', 'jp-jp2');
INSERT INTO `cfg_ext` VALUES ('jpe', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('jpeg', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('jpg', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('jpt', 'jp-jpt');
INSERT INTO `cfg_ext` VALUES ('jxr', 'jp-jxr');
INSERT INTO `cfg_ext` VALUES ('m2v', 'jp-m2v');
INSERT INTO `cfg_ext` VALUES ('m4a', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('man', 'jp-man');
INSERT INTO `cfg_ext` VALUES ('mat', 'jp-mat');
INSERT INTO `cfg_ext` VALUES ('mid', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('midi', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('mindnode', 'jp-mm');
INSERT INTO `cfg_ext` VALUES ('mkv', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mm', 'jp-mm');
INSERT INTO `cfg_ext` VALUES ('mng', 'jp-mng');
INSERT INTO `cfg_ext` VALUES ('mono', 'jp-mono');
INSERT INTO `cfg_ext` VALUES ('mov', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mp2', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('mp3', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('mp4', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mpeg', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mpeg2', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mpeg4', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mpega', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('mpg', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mpga', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('mrw', 'jp-mrw');
INSERT INTO `cfg_ext` VALUES ('mtv', 'jp-mtv');
INSERT INTO `cfg_ext` VALUES ('nef', 'jp-nef');
INSERT INTO `cfg_ext` VALUES ('ogg', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('orf', 'jp-orf');
INSERT INTO `cfg_ext` VALUES ('otb', 'jp-otb');
INSERT INTO `cfg_ext` VALUES ('p7', 'jp-p7');
INSERT INTO `cfg_ext` VALUES ('palm', 'jp-palm');
INSERT INTO `cfg_ext` VALUES ('pbm', 'jp-pbm');
INSERT INTO `cfg_ext` VALUES ('pcd', 'jp-pcd');
INSERT INTO `cfg_ext` VALUES ('pcds', 'jp-pcds');
INSERT INTO `cfg_ext` VALUES ('pcx', 'jp-pcx');
INSERT INTO `cfg_ext` VALUES ('pdb', 'jp-pdb');
INSERT INTO `cfg_ext` VALUES ('pdf', 'jp-pdf');
INSERT INTO `cfg_ext` VALUES ('pef', 'jp-pef');
INSERT INTO `cfg_ext` VALUES ('pfa', 'jp-pfa');
INSERT INTO `cfg_ext` VALUES ('pfb', 'jp-pfb');
INSERT INTO `cfg_ext` VALUES ('pfm', 'jp-pfm');
INSERT INTO `cfg_ext` VALUES ('pgm', 'jp-pgm');
INSERT INTO `cfg_ext` VALUES ('picon', 'jp-picon');
INSERT INTO `cfg_ext` VALUES ('pict', 'jp-pict');
INSERT INTO `cfg_ext` VALUES ('png', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('png00', 'jp-png00');
INSERT INTO `cfg_ext` VALUES ('png24', 'jp-png24');
INSERT INTO `cfg_ext` VALUES ('png32', 'jp-png32');
INSERT INTO `cfg_ext` VALUES ('png48', 'jp-png48');
INSERT INTO `cfg_ext` VALUES ('png64', 'jp-png64');
INSERT INTO `cfg_ext` VALUES ('png8', 'jp-png8');
INSERT INTO `cfg_ext` VALUES ('pnm', 'jp-pnm');
INSERT INTO `cfg_ext` VALUES ('ppm', 'jp-ppm');
INSERT INTO `cfg_ext` VALUES ('ppt', 'jp-ppt');
INSERT INTO `cfg_ext` VALUES ('pptx', 'jp-ppt');
INSERT INTO `cfg_ext` VALUES ('ps', 'jp-ps');
INSERT INTO `cfg_ext` VALUES ('ps2', 'jp-ps2');
INSERT INTO `cfg_ext` VALUES ('ps3', 'jp-ps3');
INSERT INTO `cfg_ext` VALUES ('psb', 'jp-psb');
INSERT INTO `cfg_ext` VALUES ('psd', 'jp-psd');
INSERT INTO `cfg_ext` VALUES ('ptif', 'jp-ptif');
INSERT INTO `cfg_ext` VALUES ('pwp', 'jp-pwp');
INSERT INTO `cfg_ext` VALUES ('qt', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('ra', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('rad', 'jp-rad');
INSERT INTO `cfg_ext` VALUES ('raf', 'jp-raf');
INSERT INTO `cfg_ext` VALUES ('ram', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('rar', 'jp-zip');
INSERT INTO `cfg_ext` VALUES ('rfg', 'jp-rfg');
INSERT INTO `cfg_ext` VALUES ('rla', 'jp-rla');
INSERT INTO `cfg_ext` VALUES ('rle', 'jp-rle');
INSERT INTO `cfg_ext` VALUES ('rm', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('rmvb', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('rp', 'jp-rp');
INSERT INTO `cfg_ext` VALUES ('sct', 'jp-sct');
INSERT INTO `cfg_ext` VALUES ('sfw', 'jp-sfw');
INSERT INTO `cfg_ext` VALUES ('sgi', 'jp-sgi');
INSERT INTO `cfg_ext` VALUES ('sid', 'jp-sid');
INSERT INTO `cfg_ext` VALUES ('sun', 'jp-sun');
INSERT INTO `cfg_ext` VALUES ('svg', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('svgz', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('swf', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('tga', 'jp-tga');
INSERT INTO `cfg_ext` VALUES ('tif', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('tiff', 'jp-img');
INSERT INTO `cfg_ext` VALUES ('tim', 'jp-tim');
INSERT INTO `cfg_ext` VALUES ('txt', 'jp-txt');
INSERT INTO `cfg_ext` VALUES ('vicar', 'jp-vicar');
INSERT INTO `cfg_ext` VALUES ('viff', 'jp-viff');
INSERT INTO `cfg_ext` VALUES ('vsd', 'jp-vsd');
INSERT INTO `cfg_ext` VALUES ('wav', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('wbmp', 'jp-wbmp');
INSERT INTO `cfg_ext` VALUES ('wdp', 'jp-wdp');
INSERT INTO `cfg_ext` VALUES ('webp', 'jp-webp');
INSERT INTO `cfg_ext` VALUES ('wm', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('wma', 'jp-audio');
INSERT INTO `cfg_ext` VALUES ('wmd', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('wmf', 'jp-wmf');
INSERT INTO `cfg_ext` VALUES ('wmv', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('wmx', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('wmz', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('wpg', 'jp-wpg');
INSERT INTO `cfg_ext` VALUES ('wps', 'jp-wps');
INSERT INTO `cfg_ext` VALUES ('wvx', 'jp-vedio');
INSERT INTO `cfg_ext` VALUES ('x3f', 'jp-x3f');
INSERT INTO `cfg_ext` VALUES ('xbm', 'jp-xbm');
INSERT INTO `cfg_ext` VALUES ('xcf', 'jp-xcf');
INSERT INTO `cfg_ext` VALUES ('xls', 'jp-xls');
INSERT INTO `cfg_ext` VALUES ('xlsx', 'jp-xls');
INSERT INTO `cfg_ext` VALUES ('xpm', 'jp-xpm');
INSERT INTO `cfg_ext` VALUES ('xwd', 'jp-xwd');
INSERT INTO `cfg_ext` VALUES ('z', 'jp-zip');
INSERT INTO `cfg_ext` VALUES ('zip', 'jp-zip');
```

## 可能需要做数据表升级
```
ALTER TABLE `cfg_storage` ADD COLUMN `AppID`  int(11) NOT NULL AFTER `access_key`;
ALTER TABLE `cfg_storage` ADD COLUMN `SecretID`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `AppID`;
ALTER TABLE `cfg_storage` ADD COLUMN `SecretKey`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `SecretID`;
ALTER TABLE `cfg_storage` ADD COLUMN `Region`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `SecretKey`;
ALTER TABLE `cfg_storage` ADD COLUMN `LogoutType`  tinyint(4) NOT NULL AFTER `Region`;
ALTER TABLE `cfg_storage` ADD COLUMN `SignExpiredTime`  int(10) NOT NULL AFTER `LogoutType`;
ALTER TABLE `cfg_storage` ADD COLUMN `request_id_log_limit_time`  int(10) NULL DEFAULT 100 COMMENT 'cos 打印request id' AFTER `SignExpiredTime`;
ALTER TABLE `cfg_storage` MODIFY COLUMN `type`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '存储类型，目前支持\"oss\"和\"local\"' AFTER `id`;
ALTER TABLE `cfg_storage` MODIFY COLUMN `host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'OSS域名或者Local磁盘主目录' AFTER `type`;
ALTER TABLE `cfg_storage` MODIFY COLUMN `bucket_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'OSS bucket_name或者磁盘二级目录' AFTER `host`;
```


## 直接升级数据库
```
CREATE TABLE `cfg_auth_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_error` (
`error_id`  int(11) NOT NULL ,
`error_desc`  varchar(256) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`error_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_front_end_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id' ,
`server_id`  int(11) NOT NULL ,
`node_type`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型' ,
`node_listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`node_backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`node_net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`node_net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
`node_server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '127.0.0.1' ,
`node_server_port`  int(11) NULL DEFAULT 9222 COMMENT '上层连接服务器端口号' ,
`node_actions`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_local_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_name`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_waiting_time`  int(11) NULL DEFAULT 2 COMMENT '超时等待的时间，单位秒' ,
`node_option_allow_url`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_monitor_server_addresses`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控' ,
`node_server_option`  int(11) NOT NULL ,
PRIMARY KEY (`server_ip`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_function` (
`function_id`  int(11) NOT NULL AUTO_INCREMENT ,
`offset`  int(11) NULL DEFAULT NULL COMMENT '对应onoff位数' ,
`name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '功能名' ,
`detail`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '附加简述' ,
PRIMARY KEY (`function_id`),
UNIQUE INDEX `offset` USING BTREE (`offset`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_gift` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`pay_money`  int(11) NULL DEFAULT NULL COMMENT '充值金额' ,
`pay_gift`  int(11) NULL DEFAULT NULL COMMENT '赠送曲奇币' ,
`limit_days`  int(11) NULL DEFAULT 0 COMMENT '创建团队的天数限制' ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_log_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_log_file` (
`server`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
` root_path`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`server`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `cfg_message_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' ,
`server_id`  int(11) NOT NULL ,
`db_id`  int(11) NOT NULL DEFAULT 0 ,
`node_type`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT 'fcgi_server' COMMENT '节点类型' ,
`node_listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`node_backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`node_net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`node_net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
`node_server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址' ,
`node_server_port`  int(11) NULL DEFAULT 9222 COMMENT '上层连接服务器端口号' ,
`node_actions`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2' ,
`node_local_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '运行服务器的ip' ,
`node_name`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'quqiserver节点名称' ,
`node_waiting_time`  int(11) NULL DEFAULT 2 COMMENT '超时等待的时间，单位秒' ,
`node_option_allow_url`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法' ,
`node_monitor_server_addresses`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控' ,
`node_server_option`  int(11) NOT NULL ,
PRIMARY KEY (`server_ip`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_money_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_monitor` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`type`  int(11) NULL DEFAULT NULL COMMENT '监控类型，1：socket监控 2：http监控' ,
`server_name`  varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`extension`  varchar(128) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '扩展内容，根据type不同而不同' ,
`enable`  int(11) NULL DEFAULT 0 ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `cfg_notify_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_quqi_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_sdk_proxy_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定auth_id' ,
`server_id`  int(11) NOT NULL ,
`db_id`  int(11) NOT NULL DEFAULT 0 COMMENT 'auth数据库配置' ,
`node_type`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT 'fcgi_server' COMMENT '节点类型' ,
`node_listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`node_backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`node_net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`node_net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
`node_server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '127.0.0.1' ,
`node_server_port`  int(11) NULL DEFAULT 9222 COMMENT '上层连接服务器端口号' ,
`node_actions`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_local_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_name`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_waiting_time`  int(11) NULL DEFAULT 2 COMMENT '超时等待的时间，单位秒' ,
`node_option_allow_url`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`node_monitor_server_addresses`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控' ,
`node_server_option`  int(11) NOT NULL ,
PRIMARY KEY (`server_ip`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `cfg_server_log_onoff` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`server`  varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`log_type`  varchar(256) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`log_way`  varchar(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`enable`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `cfg_session_db` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`host`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`port`  int(11) NOT NULL ,
`dbname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`username`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`password`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`connect_cnt`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_task_relay_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`server_id`  int(11) NOT NULL DEFAULT 0 ,
`session_id`  int(11) NOT NULL DEFAULT 1 ,
`db_id`  int(11) NOT NULL DEFAULT 0 ,
`node_type`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT 'fcgi_server' COMMENT '节点类型' ,
`node_listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`node_backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`node_net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`node_net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
`node_server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '127.0.0.1' COMMENT '上层连接服务器的ip地址' ,
`node_server_port`  int(11) NULL DEFAULT 9222 COMMENT '上层连接服务器端口号' ,
`node_actions`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '该节点能做的活，格式actions=action_name1|action1_step1|action1_step2,action_name2|action2_step1|action2_step2' ,
`node_local_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT '运行服务器的ip' ,
`node_name`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT 'quqiserver节点名称' ,
`node_waiting_time`  int(11) NULL DEFAULT 2 COMMENT '超时等待的时间，单位秒' ,
`node_option_allow_url`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '设置允许跨域的url，多个可以用|分割，使用尾部搜索法' ,
`node_monitor_server_addresses`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '监控服务器地址，格式为127.0.0.1:1234|127.0.0.2:1234，为空则不启用监控' ,
`node_server_option`  int(11) NOT NULL ,
PRIMARY KEY (`server_ip`),
UNIQUE INDEX `node_local_ip_node_listen_port` USING BTREE (`node_local_ip`, `node_listen_port`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_task_router_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定server_id' ,
`server_id`  int(11) NOT NULL DEFAULT 0 ,
`relay_id`  int(11) NOT NULL DEFAULT 0 ,
`db_id`  int(11) NOT NULL DEFAULT 0 ,
`listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
PRIMARY KEY (`server_ip`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `cfg_task_server` (
`server_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '0' COMMENT '服务器ip，用于确定server_id' ,
`server_id`  int(11) NOT NULL DEFAULT 0 ,
`router_id`  int(11) NOT NULL DEFAULT 0 ,
`db_id`  int(11) NOT NULL DEFAULT 0 ,
`listen_port`  int(11) NOT NULL DEFAULT 0 COMMENT '对外的fcgi监听端口' ,
`backlog`  int(11) NULL DEFAULT 500 COMMENT '监听队列大小' ,
`net_schedule_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的读取发送线程, 一般为cpu核数' ,
`net_process_cnt`  int(11) NULL DEFAULT 2 COMMENT '用来创建底层使用的上层处理线程，一般为cpu核数' ,
PRIMARY KEY (`server_ip`, `listen_port`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `quqi_id_pool` (
`quqi_id`  int(11) UNSIGNED NOT NULL ,
`type`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '0表示随机生成的普通quqi_id，1表示保留的特殊quqi_id' ,
`status`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '0表示该quqi\\_id的邀请码未发放，1表示已发放邀请码给公司但未被使用，2表示已发放邀请码给个人但未被使用，3表示已被公司使用，4表示已被个人使用, 5表示已经回收的公司quqi_id' ,
`owner_id`  int(11) NOT NULL DEFAULT 0 COMMENT '为company_id或passport_id' ,
`invitation_code`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '邀请码，随机生成的字符串' ,
PRIMARY KEY (`quqi_id`),
INDEX `type` USING BTREE (`type`) ,
INDEX `status` USING BTREE (`status`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
```

## 特殊升级
```
DROP TABLE IF EXISTS `sys_service`;
CREATE TABLE `sys_service` (
  `quqi_id` int(11) unsigned NOT NULL COMMENT 'quqi服务id',
  `service_type` int(11) NOT NULL COMMENT '服务类型，1为面向公司的曲奇服务，2为面向个人的曲奇服务',
  `owner_id` int(11) NOT NULL DEFAULT '0' COMMENT '根据服务类型，为company\\_id或passport\\_id。0表示这是未分配的service',
  `server_id` int(11) NOT NULL DEFAULT '0' COMMENT '运行该服务的quqi server id',
  `db_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应cfg\\\\_db表中的id',
  `doc_db_id` int(11) NOT NULL DEFAULT '0',
  `report_db_id` int(11) NOT NULL DEFAULT '0',
  `doc_server_id` int(11) NOT NULL DEFAULT '0',
  `report_server_id` int(11) NOT NULL DEFAULT '0',
  `doc_storage_id` int(11) NOT NULL DEFAULT '0',
  `report_storage_id` int(11) NOT NULL DEFAULT '0',
  `has_init` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0表示未初始化，1表示已初始化',
  `preset_status` tinyint(4) NOT NULL DEFAULT '0' COMMENT '0标识初始化 其它值则标识预先动作的状态',
  PRIMARY KEY (`quqi_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of sys_service
-- ----------------------------
INSERT INTO `sys_service` VALUES ('1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '3', '1');
```

## 被删除的数据表
- quqi_center.sys_group 迁移至quqi_document1.company_group，同步成功后可手动删除`sys_group`

```
DROP TABLE `cfg_db`;
DROP TABLE `sys_tree`;
```