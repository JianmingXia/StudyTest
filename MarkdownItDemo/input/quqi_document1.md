[TOC]

# quqi_document1
## 必须做的升级(改动较大)
- tree_doc：quqi_id, lastest_version_size,size字段
- tree_doc_version: quqi_id, doc_type, doc_ext, is_encrypt
- tree_node: quqi_id
- tree_permission: quqi_id

```
ALTER TABLE `tree_doc` ROW_FORMAT=Dynamic;
ALTER TABLE `tree_doc` ADD COLUMN `quqi_id`  int(11) NOT NULL AFTER `node_id`;
ALTER TABLE `tree_doc` ADD COLUMN `lastest_version_size`  bigint(20) NOT NULL DEFAULT 0 COMMENT '最新版本大小' AFTER `doc_ext`;
ALTER TABLE `tree_doc` ADD COLUMN `size`  bigint(15) UNSIGNED NOT NULL AFTER `lastest_version_size`;
ALTER TABLE `tree_doc` ADD COLUMN `sheet_plugin_info`  varchar(2048) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '' AFTER `size`;
ALTER TABLE `tree_doc` DROP PRIMARY KEY;
ALTER TABLE `tree_doc` ADD PRIMARY KEY (`node_id`, `quqi_id`);

ALTER TABLE `tree_doc_version` ADD COLUMN `quqi_id`  int(11) NOT NULL AFTER `node_id`;
ALTER TABLE `tree_doc_version` ADD COLUMN `user_name`  char(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `user_id`;
ALTER TABLE `tree_doc_version` ADD COLUMN `doc_type`  tinyint(3) UNSIGNED NULL DEFAULT 0 AFTER `add_time`;
ALTER TABLE `tree_doc_version` ADD COLUMN `doc_ext`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' AFTER `doc_type`;
ALTER TABLE `tree_doc_version` ADD COLUMN `convert_to_pic`  int(6) NOT NULL DEFAULT 0 AFTER `is_stored`;
ALTER TABLE `tree_doc_version` ADD COLUMN `pic_size_info`  varchar(2048) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '' AFTER `convert_to_pic`;
ALTER TABLE `tree_doc_version` ADD COLUMN `wiki_format`  tinyint(3) NULL DEFAULT 0 COMMENT '曲奇文档版式' AFTER `pic_size_info`;
ALTER TABLE `tree_doc_version` ADD COLUMN `convert_to_mobile_pic`  int(11) NULL DEFAULT 0 AFTER `wiki_format`;
ALTER TABLE `tree_doc_version` ADD COLUMN `mobile_pic_size_info`  varchar(2048) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL AFTER `convert_to_mobile_pic`;
ALTER TABLE `tree_doc_version` ADD COLUMN `has_thumbnail`  tinyint(4) NULL DEFAULT 0 AFTER `mobile_pic_size_info`;
ALTER TABLE `tree_doc_version` ADD COLUMN `has_mobile_thumbnail`  tinyint(4) NULL DEFAULT 0 AFTER `has_thumbnail`;
ALTER TABLE `tree_doc_version` ADD COLUMN `is_encrypt`  tinyint(4) NOT NULL DEFAULT 1 COMMENT '是否加密存储' AFTER `has_mobile_thumbnail`;
ALTER TABLE `tree_doc_version` ADD COLUMN `is_vod`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否点播视频' AFTER `is_encrypt`;
ALTER TABLE `tree_doc_version` MODIFY COLUMN `doc_size`  bigint(15) UNSIGNED NOT NULL AFTER `doc_md5`;
ALTER TABLE `tree_doc_version` MODIFY COLUMN `old_oss_path`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' AFTER `store_name`;
ALTER TABLE `tree_doc_version` MODIFY COLUMN `is_stored`  int(2) NOT NULL DEFAULT 0 AFTER `old_oss_path`;
ALTER TABLE `tree_doc_version` DROP PRIMARY KEY;
ALTER TABLE `tree_doc_version` ADD PRIMARY KEY (`node_id`, `quqi_id`, `version`);

ALTER TABLE `tree_node` ROW_FORMAT=Dynamic;
ALTER TABLE `tree_node` ADD COLUMN `quqi_id`  int(11) UNSIGNED NOT NULL AFTER `tree_id`;
ALTER TABLE `tree_node` ADD COLUMN `comments_group_id`  char(48) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' AFTER `shared`;
ALTER TABLE `tree_node` ADD COLUMN `is_finalize`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否定稿' AFTER `isdeleted`;
ALTER TABLE `tree_node` ADD COLUMN `is_preset`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否预置文档' AFTER `update_time`;
ALTER TABLE `tree_node` MODIFY COLUMN `node_id`  int(10) NOT NULL FIRST ;
ALTER TABLE `tree_node` MODIFY COLUMN `last_editor`  int(10) NULL DEFAULT 0 COMMENT '最后修改人id，user_id' AFTER `is_finalize`;
ALTER TABLE `tree_node` MODIFY COLUMN `update_time`  int(10) UNSIGNED NULL DEFAULT 0 COMMENT '最后修改时间' AFTER `last_editor`;
ALTER TABLE `tree_node` DROP PRIMARY KEY;
ALTER TABLE `tree_node` ADD PRIMARY KEY (`node_id`, `quqi_id`);
CREATE INDEX `quqi_id` USING BTREE ON `tree_node`(`quqi_id`) ;

ALTER TABLE `tree_permission` ROW_FORMAT=Dynamic;
ALTER TABLE `tree_permission` ADD COLUMN `quqi_id`  int(11) UNSIGNED NOT NULL AFTER `tree_id`;
ALTER TABLE `tree_permission` ADD COLUMN `update_time`  int(11) UNSIGNED NOT NULL DEFAULT 0 AFTER `quqi_id`;
ALTER TABLE `tree_permission` DROP PRIMARY KEY;
ALTER TABLE `tree_permission` ADD PRIMARY KEY (`node_id`, `tree_id`, `quqi_id`);
```

```
update tree_doc set quqi_id = 1;
update tree_doc A join (select node_id, SUM(doc_size) as sum_size from tree_doc_version GROUP BY node_id) B
on A.node_id = B.node_id
set A.size = B.sum_size;
update tree_doc A join tree_doc_version B
on A.node_id = B.node_id and A.lastest_version = B.version
set A.lastest_version_size = B.doc_size;

update tree_doc_version A join tree_doc B
on A.node_id = B.node_id 
set A.quqi_id = B.quqi_id, A.doc_type=B.doc_type, A.doc_ext=B.doc_ext, A.is_encrypt=1;

update tree_node set quqi_id=1;

update tree_permission set quqi_id=1;
```

## 直接升级数据库
- tree_doc_draft不做升级

```
CREATE TABLE `browses_history` (
`history_id`  bigint(19) UNSIGNED NOT NULL AUTO_INCREMENT ,
`quqi_id`  int(10) NOT NULL ,
`passport_id`  int(10) NOT NULL ,
`history_type`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '浏览类型' ,
`browse_time`  int(10) NOT NULL DEFAULT 0 COMMENT '浏览时间' ,
`item_id_1`  int(10) NULL DEFAULT NULL COMMENT 'item内容与type相关' ,
`item_id_2`  int(10) NULL DEFAULT NULL ,
`item_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`item_path`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`item_editor`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT '' ,
`item_type`  tinyint(4) UNSIGNED NULL DEFAULT 0 ,
`item_version`  int(10) NULL DEFAULT 0 COMMENT '版本' ,
`item_version_old`  int(10) NULL DEFAULT 0 COMMENT '旧版本' ,
PRIMARY KEY (`history_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `company_group` (
`group_id`  bigint(19) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT '群组id' ,
`group_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '群组名' ,
`is_department`  tinyint(4) NOT NULL COMMENT '1:department;0:user create' ,
`company_id`  int(10) NULL DEFAULT NULL ,
`department_id`  int(11) NOT NULL COMMENT '部门id(if is_department==1)' ,
`creator_user_id`  int(11) NOT NULL COMMENT '创建人id(if is_department==0)' ,
`admin_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '群组管理员id列表，逗号分隔' ,
`member_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '群组成员id列表，逗号分隔' ,
PRIMARY KEY (`group_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `company_permission` (
`company_id`  int(11) NOT NULL ,
`permission_type`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '0自定义权限，1全体编辑权限' ,
PRIMARY KEY (`company_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `favorites_item` (
`item_id`  bigint(19) UNSIGNED NOT NULL AUTO_INCREMENT COMMENT '收藏项id' ,
`item_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '收藏项名称' ,
`parent_id`  int(10) UNSIGNED NOT NULL DEFAULT 0 COMMENT '父收藏项id' ,
`passport_id`  int(10) UNSIGNED NOT NULL COMMENT '该收藏所属用户的passport\\_id' ,
`quqi_id`  int(10) UNSIGNED NOT NULL COMMENT '保存该收藏项的quqi服务id' ,
`add_time`  int(10) UNSIGNED NOT NULL COMMENT '创建时间' ,
`type`  tinyint(4) NOT NULL COMMENT '0表示默认收藏夹，1表示该节点为收藏文件夹，2表示该节点对应公司树上的一个节点' ,
`doc_tree_id`  int(10) NULL DEFAULT NULL ,
`doc_node_id`  int(10) NULL DEFAULT NULL ,
`url`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '该收藏对应的URL' ,
`status`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '0表示正常，1表示对应的公司树节点已删除，2表示对应的公司树节点已粉碎，3表示没有对应的公司树节点读权限' ,
PRIMARY KEY (`item_id`),
INDEX `tree` USING BTREE (`passport_id`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `follow_item` (
`item_id`  bigint(19) UNSIGNED NOT NULL AUTO_INCREMENT ,
`passport_id`  int(11) UNSIGNED NOT NULL ,
`quqi_id`  int(11) UNSIGNED NOT NULL ,
`add_time`  int(11) UNSIGNED NOT NULL ,
`type`  int(11) NOT NULL COMMENT '1表示拒绝接收动态，2表示接收动态' ,
`tag`  int(11) NULL DEFAULT NULL COMMENT '表示动态用什么颜色的标签' ,
`doc_tree_id`  int(11) NOT NULL ,
`doc_node_id`  int(11) NOT NULL ,
`push_app`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '是否推送到手机' ,
`push_custom`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL COMMENT '推送定制选项组成的字符串，0表示都不订阅，1表示接受动态不推送到钉钉，3表示接受动态并推送到钉' ,
`status`  int(11) NULL DEFAULT NULL COMMENT '表示用户在该节点的权限' ,
PRIMARY KEY (`item_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_node_id` (
`quqi_id`  int(11) UNSIGNED NOT NULL AUTO_INCREMENT ,
`node_id`  int(11) NOT NULL COMMENT '当前最大node_id' ,
PRIMARY KEY (`quqi_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `sys_tree` (
`quqi_id`  int(11) UNSIGNED NOT NULL ,
`tree_id`  int(11) NOT NULL COMMENT '树id' ,
`storage_config_id`  int(11) NOT NULL COMMENT '应用cfg_store的配置' ,
PRIMARY KEY (`quqi_id`, `tree_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_dir` (
`node_id`  int(11) NOT NULL ,
`quqi_id`  int(11) NOT NULL ,
`watermark_type`  int(11) NOT NULL DEFAULT 0 COMMENT '水印类型，0为不开启水印' ,
`watermark_detail`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '自定义水印内容' ,
`dir_type`  int(11) NULL DEFAULT 0 ,
`dir_detail`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
PRIMARY KEY (`node_id`, `quqi_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_doc_check` (
`quqi_id`  int(11) NOT NULL ,
`node_id`  int(11) NOT NULL ,
`version`  int(11) NOT NULL ,
`user_id`  int(11) NOT NULL ,
`user_name`  varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`add_time`  int(11) NOT NULL DEFAULT 0 COMMENT '发起待审核时间' ,
`check_status`  int(11) NOT NULL DEFAULT 0 COMMENT '审批状态，0待审批，1已审批，2已驳回' ,
`check_time`  int(11) NOT NULL DEFAULT 0 COMMENT '审阅时间' ,
PRIMARY KEY (`quqi_id`, `node_id`, `version`, `user_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_doc_office_convert` (
`quqi_id`  int(11) NOT NULL ,
`tree_id`  int(11) NOT NULL ,
`node_id`  int(11) NOT NULL ,
`version`  int(11) NOT NULL ,
`type`  int(10) NOT NULL COMMENT '转换类型' ,
`add_time`  int(11) NOT NULL ,
`doc_md5`  char(32) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`doc_size`  int(11) NULL DEFAULT NULL ,
`store_path`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`store_name`  varchar(1024) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL ,
`status`  int(11) NULL DEFAULT 0 ,
PRIMARY KEY (`quqi_id`, `tree_id`, `node_id`, `type`, `version`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
DROP TABLE IF EXISTS `tree_doc_draft`;
CREATE TABLE `tree_doc_draft` (
  `draft_id` bigint(19) unsigned NOT NULL AUTO_INCREMENT,
  `quqi_id` int(10) NOT NULL,
  `passport_id` int(10) NOT NULL,
  `draft_type` tinyint(4) NOT NULL DEFAULT '0' COMMENT '草稿类型',
  `update_time` int(10) NOT NULL DEFAULT '0' COMMENT '更新时间',
  `item_id_1` int(10) DEFAULT NULL COMMENT 'item内容与type相关',
  `item_id_2` int(10) DEFAULT NULL,
  `item_name` varchar(255) DEFAULT NULL,
  `item_type` tinyint(4) unsigned DEFAULT '0',
  `item_content` longtext,
  `item_version` int(10) DEFAULT NULL,
  `store_path` varchar(1024) DEFAULT NULL,
  `store_name` varchar(1024) DEFAULT NULL,
  `wiki_format` tinyint(3) DEFAULT '0' COMMENT '曲奇文档版式',
  PRIMARY KEY (`draft_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
CREATE TABLE `tree_doc_vod` (
`quqi_id`  int(11) NOT NULL ,
`node_id`  int(11) NOT NULL ,
`version`  int(11) NOT NULL ,
`vod_url`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '原始视频播放链接' ,
`update_time`  int(11) NOT NULL DEFAULT 0 COMMENT '状态更新时间' ,
`status`  int(11) NOT NULL DEFAULT 0 COMMENT '转码状态，1正在转码，2转码完成，3转码失败' ,
PRIMARY KEY (`quqi_id`, `node_id`, `version`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_node_deleted` (
`node_id`  int(10) UNSIGNED NOT NULL ,
`node_name`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' ,
`is_dir`  tinyint(4) NOT NULL DEFAULT 0 ,
`doc_type`  tinyint(4) NULL DEFAULT NULL ,
`parent_id`  int(10) UNSIGNED NOT NULL DEFAULT 0 ,
`tree_id`  int(10) UNSIGNED NOT NULL ,
`quqi_id`  int(10) UNSIGNED NOT NULL ,
`add_time`  int(10) UNSIGNED NOT NULL DEFAULT 0 ,
`shared`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '兼容老版本' ,
`isdeleted`  tinyint(4) NOT NULL DEFAULT 0 ,
`last_editor`  int(10) NULL DEFAULT 0 ,
`update_time`  int(10) UNSIGNED NULL DEFAULT 0 ,
`read_user_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`read_group_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`write_user_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`write_group_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`admin_user_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`admin_group_id_list`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL ,
`delete_operate_id`  varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL DEFAULT '' COMMENT '格式为「qid_tid_nid」' ,
`is_direct_deleted`  tinyint(4) NULL DEFAULT 0 COMMENT '删除操作是否直接在该节点上执行' ,
`path_name`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '完整路径名称，不包括当前节点' ,
`path_nid`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '完整路径上各个节点id拼接，不包括当前节点' ,
`delete_time`  int(10) NOT NULL COMMENT '删除操作执行时间' ,
`delete_user_id`  int(11) NOT NULL COMMENT '操作执行人user_id' ,
`total_number`  int(10) UNSIGNED NOT NULL COMMENT '自身及所有子节点的节点数量' ,
`total_size`  bigint(20) UNSIGNED NOT NULL COMMENT '自身及所有子节点的容量大小' ,
`lastest_version_total_size`  bigint(20) NOT NULL DEFAULT 0 COMMENT '自身及所有子节点的最新版本容量大小' ,
PRIMARY KEY (`node_id`, `quqi_id`),
INDEX `proid` USING BTREE (`tree_id`) ,
INDEX `operate_id` USING BTREE (`delete_operate_id`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_node_smashed` (
`node_id`  int(10) UNSIGNED NOT NULL ,
`tree_id`  int(10) UNSIGNED NOT NULL ,
`quqi_id`  int(11) UNSIGNED NOT NULL ,
`content`  text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT 'JSON格式的节点数据' ,
PRIMARY KEY (`node_id`, `quqi_id`),
INDEX `proj` USING BTREE (`tree_id`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_share` (
`share_id`  bigint(19) UNSIGNED NOT NULL AUTO_INCREMENT ,
`passport_id`  int(10) NOT NULL ,
`lastest_passport_id`  int(10) NULL DEFAULT 0 COMMENT '最近修改人' ,
`share_type`  tinyint(4) NULL DEFAULT 0 COMMENT '发布类型' ,
`code`  varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '分享code(至少保证在一个quqi中是唯一的)' ,
`quqi_id`  int(10) NOT NULL ,
`tree_id`  int(10) NOT NULL ,
`node_id`  int(10) NOT NULL ,
`view_number_limit`  int(10) NOT NULL COMMENT '可查看人数' ,
`add_time`  int(11) NOT NULL COMMENT '添加时间' ,
`edit_time`  int(11) NOT NULL COMMENT '最近修改时间' ,
`expired_time`  int(11) NOT NULL COMMENT '过期时间' ,
`status`  tinyint(4) NOT NULL DEFAULT 0 COMMENT '分享状态' ,
`pause_time`  int(11) NULL DEFAULT 0 COMMENT '暂停时间' ,
`watermark_type`  int(10) NULL DEFAULT 0 COMMENT '水印类型' ,
`watermark_detail`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '水印添加的其它文档' ,
PRIMARY KEY (`share_id`),
UNIQUE INDEX `unique_quqi_code` USING BTREE (`quqi_id`, `code`) 
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_share_delete` (
`share_id`  int(11) UNSIGNED NOT NULL ,
`passport_id`  int(10) NOT NULL ,
`lastest_passport_id`  int(10) NULL DEFAULT 0 COMMENT '最近修改人' ,
`share_type`  tinyint(4) NULL DEFAULT 0 COMMENT '发布类型' ,
`code`  varchar(16) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL COMMENT '分享code(至少保证在一个quqi中是唯一的)' ,
`quqi_id`  int(10) NOT NULL ,
`tree_id`  int(10) NOT NULL ,
`node_id`  int(10) NOT NULL ,
`view_number_limit`  int(10) NOT NULL COMMENT '可查看人数' ,
`add_time`  int(11) NOT NULL COMMENT '添加时间' ,
`edit_time`  int(11) NOT NULL COMMENT '最近修改时间' ,
`expired_time`  int(11) NOT NULL COMMENT '过期时间' ,
`status`  tinyint(4) NULL DEFAULT 0 COMMENT '状态' ,
`pause_time`  int(11) NULL DEFAULT 0 COMMENT '暂停时间' ,
`watermark_type`  int(10) NULL DEFAULT 0 COMMENT '水印类型' ,
`watermark_detail`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '水印添加的其它内容' ,
PRIMARY KEY (`share_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_share_read` (
`share_id`  int(11) NOT NULL ,
`passport_id`  int(10) NOT NULL ,
`name`  varchar(256) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`read_time`  int(11) NOT NULL ,
`stay_time`  int(11) NOT NULL COMMENT '停留时间' ,
`reading_info`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '阅读数量：图片——只有图片流才会计算；文件夹——统计文档查阅个数' ,
`doc_count`  int(11) NOT NULL COMMENT '文档数量：文档——转换成图片流后文档数量；文件夹——目前实时计算' ,
PRIMARY KEY (`share_id`, `passport_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
CREATE TABLE `tree_share_read_delete` (
`share_id`  int(11) NOT NULL ,
`passport_id`  int(10) NOT NULL ,
`name`  varchar(256) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
`read_time`  int(11) NOT NULL COMMENT '首次查阅时间' ,
`stay_time`  int(11) NOT NULL COMMENT '停留时间' ,
`reading_info`  text CHARACTER SET utf8 COLLATE utf8_general_ci NULL COMMENT '阅读数量：图片——只有图片流才会计算；文件夹——统计文档查阅个数' ,
`doc_count`  int(11) NOT NULL COMMENT '文档数量：文档——转换成图片流后文档数量；文件夹——目前实时计算' ,
PRIMARY KEY (`share_id`, `passport_id`)
)
ENGINE=InnoDB
DEFAULT CHARACTER SET=utf8 COLLATE=utf8_general_ci
ROW_FORMAT=Compact
;
```

## 额外需要同步的数据
- sys_node_id
- sys_tree

```
insert INTO sys_node_id(quqi_id, node_id) SELECT quqi_id, max(node_id) as node_id from tree_node group by quqi_id;

INSERT INTO `sys_tree` VALUES ('1', '1', '1');
```

- company_group由quqi_center中sys_group同步

```
insert into quqi_document1.company_group select * from quqi_center.sys_group;
```

- 不同步：company_permission、tree_dir 