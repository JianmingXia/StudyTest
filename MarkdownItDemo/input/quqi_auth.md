[TOC]

# quqi_auth
## 必须做的升级(改动较大)
保留旧的sys_passport表，新表使用手机号密码进行登录，数据无法对应（保留线上账号密码登录，这部分需要修改）；
- 保留passport_id
- 同步name, pinyin

```
ALTER table sys_passport RENAME sys_passport_old;

DROP TABLE IF EXISTS `sys_passport`;
CREATE TABLE `sys_passport` (
  `passport_id` int(11) NOT NULL AUTO_INCREMENT COMMENT '用户账户id',
  `password` varchar(255) DEFAULT NULL COMMENT '密码',
  `session_key` varchar(255) DEFAULT NULL,
  `type` int(11) NOT NULL DEFAULT '1' COMMENT '账户类型，目前2=一级账号；1=钉钉二级账号，3=已删除的钉钉二级账号；4=微信二级账号，5=已删除的微信二级账号；',
  `name` varchar(255) NOT NULL COMMENT '账户名',
  `pinyin` varchar(255) NOT NULL COMMENT '账号名拼音',
  `email` varchar(255) NOT NULL COMMENT '邮箱',
  `phone` varchar(255) NOT NULL COMMENT '手机号码',
  `passport_code` varchar(255) DEFAULT NULL,
  `quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '私人曲奇服务ID',
  `company_quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '专属团队曲奇id',
  `balance` double unsigned NOT NULL DEFAULT '0' COMMENT '账户余额',
  `total_pay` double unsigned NOT NULL DEFAULT '0' COMMENT '累计充值金额',
  `vip` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'vip等级',
  `status` int(11) unsigned NOT NULL DEFAULT '0' COMMENT '账户状态，0正常，1欠费1天。。。8天冻结',
  `last_visit_quqi_id` int(11) unsigned DEFAULT NULL COMMENT '上一次访问的曲奇服务ID',
  `quqi_sort` text COMMENT '团队列表顺序，json字符串',
  `create_time` int(11) DEFAULT NULL COMMENT '创建时间',
  `quqi_guide` text NOT NULL,
  `on_off` varchar(255) DEFAULT '' COMMENT '个人功能开关',
  `register_type` tinyint(4) NOT NULL DEFAULT '0' COMMENT '注册类型，目前0=主动注册，1=被动注册（通讯录邀请，添加员工账号,钉钉同步） 2=外发注册',
  `avatar_url` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`passport_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
```

```
insert into sys_passport
(passport_id, pinyin, name, session_key, email, phone, passport_code, quqi_guide, password) 
SELECT 
passport_id, name, "" as name, session_key, email, "" as phone, passport_code, "" as quqi_guide, password_key as password FROM sys_passport_old;

update sys_passport A, sys_user B set A.name = B.user_name where A.passport_id = B.passport_id;

update sys_passport set type=2;
```

## 可能需要做数据表升级
	sys_company, sys_department, sys_user

```
ALTER TABLE `sys_company` ENGINE=InnoDB;
ALTER TABLE `sys_company` ADD COLUMN `parent_company_id`  int(11) NOT NULL DEFAULT 0 COMMENT '父团队company_id' AFTER `company_name`;
ALTER TABLE `sys_company` ADD COLUMN `is_agency`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否父团队代扣' AFTER `parent_company_id`;
ALTER TABLE `sys_company` ADD COLUMN `is_sync`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否同步创建部门文件夹' AFTER `is_agency`;
ALTER TABLE `sys_company` ADD COLUMN `balance`  double NOT NULL DEFAULT 0 COMMENT '公司余额' AFTER `is_sync`;
ALTER TABLE `sys_company` ADD COLUMN `total_pay`  double NOT NULL DEFAULT 0 COMMENT '累计充值' AFTER `balance`;
ALTER TABLE `sys_company` ADD COLUMN `vip`  int(11) NOT NULL DEFAULT 0 COMMENT 'vip等级' AFTER `total_pay`;
ALTER TABLE `sys_company` ADD COLUMN `status`  int(11) NOT NULL DEFAULT 0 COMMENT '公司账户状态，欠费天数，0正常，1欠费1天。。。8天冻结' AFTER `vip`;
ALTER TABLE `sys_company` ADD COLUMN `quqi_id`  int(11) NOT NULL DEFAULT 0 COMMENT '曲奇服务ID' AFTER `status`;
ALTER TABLE `sys_company` ADD COLUMN `type`  int(10) NULL DEFAULT 1 COMMENT '企业类型（1表示钉钉绑定，2表示手动创建）' AFTER `quqi_id`;
ALTER TABLE `sys_company` ADD COLUMN `edition_type`  tinyint(4) NOT NULL DEFAULT 2 COMMENT '团队版本类型: 1表示团队版，2表示企业版，3个人版' AFTER `type`;
ALTER TABLE `sys_company` ADD COLUMN `create_time`  int(11) NOT NULL DEFAULT 0 COMMENT '团队创建时间' AFTER `edition_type`;
ALTER TABLE `sys_company` ADD COLUMN `province`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '省份' AFTER `create_time`;
ALTER TABLE `sys_company` ADD COLUMN `city`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '城市' AFTER `province`;
ALTER TABLE `sys_company` ADD COLUMN `industry_type`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '行业类型' AFTER `city`;
ALTER TABLE `sys_company` ADD COLUMN `creator_passport_id`  int(11) NOT NULL DEFAULT 0 COMMENT '创建者' AFTER `industry_type`;
ALTER TABLE `sys_company` ADD COLUMN `advanced_boss_uids`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '高级管理员id，逗号分隔' AFTER `boss_uids`;
ALTER TABLE `sys_company` ADD COLUMN `hidden_boss_uids`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '隐身管理员id，逗号分隔' AFTER `advanced_boss_uids`;
ALTER TABLE `sys_company` ADD COLUMN `account_boss_uids`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '账户管理员id，逗号分隔' AFTER `hidden_boss_uids`;
ALTER TABLE `sys_company` ADD COLUMN `contacts_boss_uids`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '通讯录管理员id，逗号分隔' AFTER `account_boss_uids`;
ALTER TABLE `sys_company` ADD COLUMN `invite_url`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `contacts_boss_uids`;
ALTER TABLE `sys_company` ADD COLUMN `icon_url`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `invite_url`;
ALTER TABLE `sys_company` ADD COLUMN `is_delete`  tinyint(4) NOT NULL DEFAULT 0 AFTER `company_code`;
ALTER TABLE `sys_company` MODIFY COLUMN `company_id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '公司id' FIRST ;
ALTER TABLE `sys_company` MODIFY COLUMN `company_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '公司名称' AFTER `company_id`;
ALTER TABLE `sys_company` MODIFY COLUMN `boss_uids`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '管理员id，逗号分隔' AFTER `creator_passport_id`;
ALTER TABLE `sys_department` ENGINE=InnoDB;
ALTER TABLE `sys_department` ADD COLUMN `create_time`  int(11) NOT NULL AFTER `is_delete`;
ALTER TABLE `sys_department` ADD COLUMN `leader_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `create_time`;
ALTER TABLE `sys_department` ADD COLUMN `sub_department_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `user_id_list`;
ALTER TABLE `sys_department` MODIFY COLUMN `is_delete`  tinyint(4) NOT NULL AFTER `company_id`;
ALTER TABLE `sys_user` ENGINE=InnoDB;
ALTER TABLE `sys_user` DROP INDEX `company_user`;
ALTER TABLE `sys_user` ADD COLUMN `user_pinyin`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '名字拼音' AFTER `user_name`;
ALTER TABLE `sys_user` ADD COLUMN `type`  int(11) NOT NULL DEFAULT 1 COMMENT 'user的来源：1=”钉钉“，2=“微信”，3=“通讯录”，4=“系统创建”5=\"外发\"' AFTER `is_delete`;
ALTER TABLE `sys_user` ADD COLUMN `phone`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '' COMMENT 'phone只在user未激活的状态下有用' AFTER `type`;
ALTER TABLE `sys_user` ADD COLUMN `active`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否已激活，0表示未激活，1表示已激活' AFTER `phone`;
ALTER TABLE `sys_user` ADD COLUMN `create_time`  int(11) NOT NULL DEFAULT 0 COMMENT '创建时间' AFTER `active`;
ALTER TABLE `sys_user` MODIFY COLUMN `user_id`  int(11) NOT NULL AUTO_INCREMENT COMMENT '用户id' FIRST ;
ALTER TABLE `sys_user` MODIFY COLUMN `company_id`  int(11) NOT NULL DEFAULT 0 COMMENT '公司id，sys_company.primarykey' AFTER `user_id`;
ALTER TABLE `sys_user` MODIFY COLUMN `passport_id`  int(11) NOT NULL DEFAULT 0 COMMENT '账号id，sys_passport.primarykey' AFTER `company_id`;
ALTER TABLE `sys_user` MODIFY COLUMN `user_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '员工名字' AFTER `passport_id`;
ALTER TABLE `sys_user` MODIFY COLUMN `job`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '职位' AFTER `user_pinyin`;
ALTER TABLE `sys_user` MODIFY COLUMN `is_delete`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '0表示正常，1表示用户已被删除' AFTER `job`;
CREATE INDEX `phone_index` USING BTREE ON `sys_user`(`phone`) ;
```

- sys_company
- sys_user

```
update sys_company set type=2;

update sys_user set active = 1;

update sys_company set quqi_id=1 where company_id=1;

update sys_company set vip=10 where company_id=1;

update sys_department A, (select GROUP_CONCAT(user_id) as user_ids from sys_user where is_delete = 0) B 
set A.user_id_list = B.user_ids where A.department_id=1;
```

## 直接升级数据库

```
ALTER TABLE `ding_company` ENGINE=InnoDB;
ALTER TABLE `ding_company` ADD COLUMN `permanent_code`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' AFTER `company_name`;
ALTER TABLE `ding_company` ADD COLUMN `agent_id`  varchar(100) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL AFTER `permanent_code`;
ALTER TABLE `ding_company` DROP COLUMN `permarent_code`;
ALTER TABLE `ding_department` ENGINE=InnoDB;
ALTER TABLE `ding_passport` ENGINE=InnoDB;
ALTER TABLE `ding_passport` ADD COLUMN `nickname`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `open_id`;
ALTER TABLE `ding_passport` ADD COLUMN `unionid`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `nickname`;
ALTER TABLE `ding_suite` ENGINE=InnoDB;
ALTER TABLE `ding_user` ENGINE=InnoDB;
CREATE TABLE `log_bind_phone` (
`passport_id`  int(11) NOT NULL ,
`tmp_phone`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`create_time`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`passport_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_browse_url` (
`url`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`user_agent`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`ip`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`add_time`  int(11) NULL DEFAULT NULL 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_login_type` (
`passport_id`  int(11) NOT NULL DEFAULT 0 ,
`login_type`  int(11) NOT NULL DEFAULT 0 COMMENT '登录方式，1pc，2钉钉，3云盘app，4微信，5sdkserver，6移动浏览器，7sdkclient，8小程序，9办公app' ,
`last_time`  int(11) NOT NULL DEFAULT 0 COMMENT '最近登录时间' ,
`last_ip`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '最近登录ip' ,
PRIMARY KEY (`passport_id`, `login_type`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_merge_passport` (
`id`  int(11) UNSIGNED NOT NULL AUTO_INCREMENT ,
`main_passport_id`  int(11) NOT NULL COMMENT '一级账号' ,
`deleted_passport_id`  int(11) NOT NULL COMMENT '被合并的二级账号' ,
`deleted_passport_type`  int(11) NOT NULL COMMENT '二级账号类型' ,
`merged_user_ids`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '二级账号中被合并到一级账号的user id，用逗号分开' ,
`deleted_user_ids`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '二级账号中被删除的user id，用逗号分开' ,
`create_time`  int(11) NOT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_team_application` (
`id`  int(11) UNSIGNED NOT NULL AUTO_INCREMENT ,
`company_id`  int(11) NOT NULL ,
`passport_id`  int(11) NOT NULL ,
`name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '用户申请时填的名称' ,
`status`  tinyint(4) NOT NULL COMMENT '申请状态，0表示待处理，1表示已同意，2表示已拒绝，3表示账号不存在' ,
`create_time`  int(11) NOT NULL COMMENT '申请时间' ,
`update_time`  int(11) NOT NULL COMMENT '更新时间，用户重复申请、管理员处理申请时会更新该值' ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `oa_access_token` (
`app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`access_token`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`scope`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`create_time`  int(11) NOT NULL COMMENT '创建时间戳，单位秒' ,
`update_time`  int(11) NOT NULL COMMENT '更新时间戳，单位秒' ,
`expire_time`  int(11) NOT NULL COMMENT '过期时间戳，单位秒' ,
PRIMARY KEY (`app_id`, `open_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `oa_authorization_code` (
`authorization_code`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`redirect_uri`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`scope`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '应用授权作用域，多个作用域间用`,`分隔开' ,
`create_time`  int(11) NOT NULL COMMENT '创建时间戳，单位秒' ,
`expire_time`  int(11) NOT NULL COMMENT '过期时间戳，单位秒' ,
PRIMARY KEY (`authorization_code`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `oa_open_id` (
`open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '保证一个app id中是唯一的，对应一个passport id' ,
`app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`passport_id`  int(11) NOT NULL COMMENT '相对应授权用户的passport id' ,
PRIMARY KEY (`open_id`, `app_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `oa_refresh_token` (
`app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`refresh_token`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`scope`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`create_time`  int(11) NOT NULL COMMENT '创建时间戳，单位秒' ,
`update_time`  int(11) NOT NULL COMMENT '更新时间戳，单位秒' ,
`expire_time`  int(11) NOT NULL COMMENT '过期时间戳，单位秒' ,
PRIMARY KEY (`app_id`, `open_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `oa_third_party_app` (
`app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`app_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`app_secret`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`passport_id`  int(11) NOT NULL COMMENT '该App所属者的passport id' ,
`status`  int(11) NOT NULL DEFAULT 0 COMMENT '0：开发状态；1：审核状态；2：上线状态' ,
`create_time`  int(11) NOT NULL COMMENT '创建时间戳，单位秒' ,
`update_time`  int(11) NOT NULL COMMENT '更新时间戳，单位秒' ,
`redirect_uri`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '不包含\"http://\"，多个之间用\';\'分隔' ,
`is_trust`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`app_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `old_node_map` (
`tree_id`  int(10) NOT NULL ,
`node_id`  int(10) NOT NULL ,
`quqi_id`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`tree_id`, `node_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_company_enterprise_limit_config` (
`company_id`  int(11) NOT NULL DEFAULT 0 ,
`operate_record_keep_day`  int(11) NOT NULL DEFAULT 0 COMMENT '操作记录保留时间（天）' ,
`max_user_count`  int(11) NOT NULL DEFAULT 0 COMMENT '最大人数' ,
`recycle_bin_keep_day`  int(11) NOT NULL DEFAULT 0 COMMENT '回收站保留时间（天）' ,
`max_storage_size`  bigint(20) NOT NULL DEFAULT 0 COMMENT '存储容量' ,
`enterprise_expire_time`  int(11) NOT NULL DEFAULT 0 COMMENT '企业过期时间' ,
PRIMARY KEY (`company_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_company_team_invite_url` (
`invite_url`  char(32) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`company_id`  int(11) NULL DEFAULT NULL ,
`user_id`  int(11) NULL DEFAULT NULL ,
`user_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`create_time`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`invite_url`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_company_team_read_permission` (
`company_id`  int(11) NOT NULL ,
`read_permission`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
PRIMARY KEY (`company_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;

CREATE TABLE `sys_invite_code` (
`parent_quqi_id`  int(11) NOT NULL ,
`child_quqi_id`  int(11) NOT NULL ,
`code`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`expire_time`  int(11) NULL DEFAULT NULL ,
PRIMARY KEY (`parent_quqi_id`, `child_quqi_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `sys_jump_link` (
`id`  int(10) NOT NULL ,
`link`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_office_tools` (
`quqi_id`  int(10) NOT NULL ,
`on_off_str`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '使用情况 0表示未开通 1表示开通' ,
PRIMARY KEY (`quqi_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_on_off` (
`quqi_id`  int(10) NOT NULL ,
`on_off_str`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT 'vip等级功能' ,
`common_on_off_str`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '基础功能' ,
PRIMARY KEY (`quqi_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `sys_passport_bind_quqiid` (
`passport_id`  int(11) NOT NULL ,
`quqi_id`  int(11) NULL DEFAULT NULL ,
`register_type`  tinyint(4) NOT NULL COMMENT '1为被动，2为外发' ,
`create_time`  int(11) NOT NULL COMMENT '创建时间' ,
PRIMARY KEY (`passport_id`, `create_time`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_passport_quqi_sort` (
`passport_id`  int(10) NOT NULL ,
`type`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '类型：1：曲奇云盘，2：曲奇办公' ,
`quqi_sort`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '团队列表顺序' ,
`update_time`  int(10) NULL DEFAULT 0 ,
PRIMARY KEY (`passport_id`, `type`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_passport_visit_quqi` (
`passport_id`  int(10) NOT NULL ,
`type`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '类型：1：曲奇云盘，2：曲奇办公' ,
`quqi_id`  int(10) NOT NULL ,
`visit_time`  int(10) NULL DEFAULT 0 COMMENT '查看时间' ,
PRIMARY KEY (`passport_id`, `type`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_special_guide` (
`passport_id`  int(11) NOT NULL ,
`notify_guide_on`  tinyint(4) NULL DEFAULT 0 COMMENT '动态引导' ,
`permission_assign_guide_on`  tinyint(4) NULL DEFAULT 0 COMMENT '权限分配' ,
`contact_manage_guide_on`  tinyint(4) NULL DEFAULT 0 COMMENT '通讯录' ,
`special_guide`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '特殊引导内容' ,
PRIMARY KEY (`passport_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;

CREATE TABLE `sys_user_guide` (
`user_id`  int(10) NOT NULL ,
`guide`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '用户在团队中引导状态' ,
PRIMARY KEY (`user_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_validate_code` (
`id`  int(11) UNSIGNED NOT NULL AUTO_INCREMENT ,
`phone`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`code`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`expire_time`  int(11) NOT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `task_ding_company` (
`corp_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`operate_dingtalk_user_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`status`  tinyint(4) NULL DEFAULT 0 ,
`create_time`  int(10) NULL DEFAULT 0 ,
`start_time`  int(10) NULL DEFAULT 0 ,
`end_time`  int(10) NULL DEFAULT 0 ,
`fail_reason`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`corp_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `wechat_app` (
`app_id`  int(10) NOT NULL COMMENT '微信app标识符' ,
`desc`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`wechat_app_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`wechat_app_secret`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`access_token`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '接口调用凭据' ,
`access_token_expire_time`  int(10) NULL DEFAULT NULL COMMENT '过期时间' ,
`jsapi_ticket`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '微信JS接口的临时票据' ,
`jsapi_ticket_expire_time`  int(10) NULL DEFAULT NULL ,
`create_time`  int(10) NULL DEFAULT NULL ,
`update_time`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`app_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `wechat_app_passport` (
`id`  int(10) NOT NULL AUTO_INCREMENT ,
`app_id`  int(10) NULL DEFAULT 0 ,
`open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`union_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`create_time`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `wechat_passport` (
`union_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '微信统一标识' ,
`passport_id`  int(11) NOT NULL DEFAULT 0 ,
`nick_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`is_delete`  tinyint(3) NULL DEFAULT 0 ,
`create_time`  int(10) NULL DEFAULT 0 COMMENT '创建时间' ,
`delete_time`  int(10) NULL DEFAULT 0 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `wechat_passport_old` (
`union_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '微信统一标识' ,
`passport_id`  int(11) NULL DEFAULT NULL ,
`public_open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '曲奇公众号用户标识' ,
`public_yunpan_open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`qr_open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '网站应用用户标识' ,
`mobile_open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '移动应用用户标识' ,
`mini_program_open_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`nick_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '用户的昵称' ,
`create_time`  int(10) NULL DEFAULT NULL COMMENT '创建时间' ,
`update_time`  int(10) NULL DEFAULT 0 ,
PRIMARY KEY (`union_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
CREATE TABLE `wechat_public` (
`type`  tinyint(4) NOT NULL DEFAULT 0 ,
`access_token`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '微信公众号接口调用凭据' ,
`expire_time`  int(10) NULL DEFAULT NULL COMMENT '过期时间' ,
`jsapi_ticket`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '公众号用于调用微信JS接口的临时票据' ,
`jsapi_ticket_expire_time`  int(10) NULL DEFAULT NULL ,
PRIMARY KEY (`type`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Dynamic
;
```

## 其它数据升级 && 新表内容复制
```
insert into sys_passport_visit_quqi select passport_id, 2 as type, 1 as quqi_id, 0 as visit_time from sys_passport;
```

```
DROP TABLE IF EXISTS `sys_company_edition_limit_config`;
CREATE TABLE `sys_company_edition_limit_config` (
  `edition_type` tinyint(4) NOT NULL COMMENT '团队版本类型：1表示团队版，2表示企业版',
  `operate_record_keep_day` int(10) DEFAULT '0' COMMENT '操作记录保留时间（天）',
  `max_user_count` int(10) DEFAULT '0' COMMENT '最大人数',
  `recycle_bin_keep_day` int(10) DEFAULT '0' COMMENT '回收站保留时间（天）',
  `max_vod_size` bigint(20) DEFAULT '0' COMMENT '视频支持转码文件最大大小',
  `max_storage_size` bigint(20) DEFAULT '0' COMMENT '存储容量',
  PRIMARY KEY (`edition_type`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='团队版本对应的限制';

-- ----------------------------
-- Records of sys_company_edition_limit_config
-- ----------------------------
INSERT INTO `sys_company_edition_limit_config` VALUES ('1', '30', '30', '30', '26214400', '1099511627776');
INSERT INTO `sys_company_edition_limit_config` VALUES ('2', '180', '5000', '180', '26214400', '1099511627776000');
INSERT INTO `sys_company_edition_limit_config` VALUES ('3', '30', '1', '30', '26214400', '1099511627776');
```

## 删除数据表（可能需要迁移到其它的数据库）
```
DROP TABLE `ding_department_test`;
DROP TABLE `cfg_server`;
```