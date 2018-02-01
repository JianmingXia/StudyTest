[TOC]

# quqi_log
## 必须做的升级（改动较大）
- log_operate：quqi_id、passport_id
```
ALTER TABLE `log_operate` ADD COLUMN `quqi_id`  int(11) UNSIGNED NOT NULL AFTER `tree_id`;
ALTER TABLE `log_operate` ADD COLUMN `passport_id`  int(11) NOT NULL DEFAULT 0 AFTER `file_type`;
ALTER TABLE `log_operate` MODIFY COLUMN `file_type`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `name`;
ALTER TABLE `log_operate` DROP COLUMN `operator_is_user`;
ALTER TABLE `log_operate` DROP COLUMN `operator_id`;
DROP INDEX `user_id` ON `log_operate`;
CREATE INDEX `user_id` USING BTREE ON `log_operate`(`passport_id`) ;
DROP INDEX `node_id_tree_id` ON `log_operate`;
CREATE INDEX `node_id_tree_id` USING BTREE ON `log_operate`(`node_id`, `tree_id`, `quqi_id`) ;
```


## 直接升级数据库
```
CREATE TABLE `log_company_member_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`user_id`  int(11) NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`time`  int(11) NULL DEFAULT NULL ,
`ip`  char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_company_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`company_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL COMMENT '1为更改系统管理员，2为更改隐身boss，3为更改通讯录管理员，4为更改账户管理员，5为编辑团队名称，6为编辑团队头像' ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`time`  int(11) NULL DEFAULT NULL ,
`ip`  char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_department_group_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`group_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`department_id`  int(11) NULL DEFAULT NULL ,
`time`  int(10) NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_department_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`department_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL COMMENT '0为创建部门，1为删除部门，2为编辑部门：修改部门名字， 3为编辑部门： 修改父部门，4为编辑部门：修改主管，5为增加成员，6为删除成员，7为增加负责人' ,
`time`  int(11) NULL DEFAULT NULL ,
`ip`  char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL COMMENT '操作者用户Id' ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_group_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`group_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`time`  int(10) NULL DEFAULT NULL ,
`ip`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_node_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`quqi_id`  int(11) UNSIGNED ZEROFILL NULL DEFAULT NULL ,
`tree_id`  int(11) UNSIGNED ZEROFILL NULL DEFAULT NULL ,
`node_id`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`ip`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`time`  int(10) NULL DEFAULT NULL ,
`dest_quqi_id`  int(11) UNSIGNED ZEROFILL NULL DEFAULT NULL ,
`dest_tree_id`  int(11) UNSIGNED ZEROFILL NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`share_id`  int(10) UNSIGNED NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_passport_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`passport_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL COMMENT '0 创建;1 发送验证码;2 登陆;3 修改密码;4 二级账号升级;5 二级账号合并;6 修改手机号;7 修改账号名;8 修改头像;9 修改账号绑定的钉钉;10 修改账号绑定的微信;11 登出;' ,
`time`  int(11) NULL DEFAULT NULL ,
`ip`  char(16) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_permission_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`quqi_tree_node_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`time`  int(10) NULL DEFAULT NULL ,
`ip`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `log_share_opt` (
`id`  int(11) NOT NULL AUTO_INCREMENT ,
`share_id`  int(11) NULL DEFAULT NULL ,
`operate_type`  int(11) NULL DEFAULT NULL ,
`operate_user_id`  int(11) NULL DEFAULT NULL ,
`time`  int(11) NULL DEFAULT NULL ,
`ip`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_1`  varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`param_2`  varchar(512) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
PRIMARY KEY (`id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
```