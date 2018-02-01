# quqi_approval

# 新增表

```
DROP TABLE IF EXISTS `passport_donelist`;
CREATE TABLE `passport_donelist` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL DEFAULT '0' COMMENT '待办类型，1文档审批，2权限审批',
  `status` int(11) NOT NULL DEFAULT '0' COMMENT '处理状态，1通过，2驳回',
  `passport_id` int(11) NOT NULL DEFAULT '0' COMMENT '待审批人id',
  `add_time` int(11) NOT NULL DEFAULT '0' COMMENT '添加时间',
  `done_time` int(11) NOT NULL DEFAULT '0' COMMENT '完成时间',
  `quqi_id` int(11) NOT NULL DEFAULT '0',
  `node_id` int(11) NOT NULL DEFAULT '0',
  `node_type` int(11) NOT NULL DEFAULT '0' COMMENT '节点类型',
  `node_name` varchar(50) NOT NULL DEFAULT '',
  `company_name` varchar(50) NOT NULL DEFAULT '' COMMENT '发起团队名称',
  `apply_id` int(11) NOT NULL DEFAULT '0',
  `apply_name` varchar(50) NOT NULL DEFAULT '' COMMENT '申请人名字',
  `config` text COMMENT '其他配置信息，用json字符串存储',
  PRIMARY KEY (`id`),
  KEY `wait_type` (`type`),
  KEY `passport_id` (`passport_id`),
  KEY `quqi_id` (`quqi_id`),
  KEY `status` (`status`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COMMENT='已完成的待办项';

-- ----------------------------
-- Table structure for passport_todolist
-- ----------------------------
DROP TABLE IF EXISTS `passport_todolist`;
CREATE TABLE `passport_todolist` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL DEFAULT '0' COMMENT '待办类型,1文档审批，2权限审批',
  `passport_id` int(11) NOT NULL DEFAULT '0' COMMENT '待审批人id',
  `quqi_id` int(11) NOT NULL DEFAULT '0',
  `add_time` int(11) NOT NULL DEFAULT '0' COMMENT '添加时间',
  `node_id` int(11) NOT NULL DEFAULT '0',
  `node_type` int(11) NOT NULL DEFAULT '0' COMMENT '节点类型',
  `node_name` varchar(50) NOT NULL DEFAULT '',
  `company_name` varchar(50) NOT NULL DEFAULT '' COMMENT '发起团队名称',
  `apply_id` int(11) NOT NULL DEFAULT '0' COMMENT '申请人passport_id',
  `apply_name` varchar(50) NOT NULL DEFAULT '' COMMENT '申请人名字',
  `config` text COMMENT '其他配置信息，用json字符串存储',
  PRIMARY KEY (`id`),
  KEY `passport_id` (`passport_id`),
  KEY `wait_type` (`type`),
  KEY `quqi_id` (`quqi_id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COMMENT='未处理的待办项';
```