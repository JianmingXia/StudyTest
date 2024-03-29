# quqi_chat

# 同步表结构
```
DROP TABLE IF EXISTS `cfg_error`;
CREATE TABLE `cfg_error` (
  `error_id` int(11) NOT NULL,
  `error_desc` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`error_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for cfg_group_stored_message
-- ----------------------------
DROP TABLE IF EXISTS `cfg_group_stored_message`;
CREATE TABLE `cfg_group_stored_message` (
  `group_id` char(48) NOT NULL,
  `begin_id` int(20) DEFAULT NULL,
  `end_id` int(20) DEFAULT NULL,
  `storage_id` int(11) DEFAULT NULL,
  `storage_path` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for cfg_message_table
-- ----------------------------
DROP TABLE IF EXISTS `cfg_message_table`;
CREATE TABLE `cfg_message_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `table_name` varchar(64) DEFAULT NULL,
  `begin_id` bigint(20) DEFAULT NULL,
  `end_id` bigint(20) DEFAULT NULL,
  `is_stored` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_message_table
-- ----------------------------
INSERT INTO `cfg_message_table` VALUES ('1', 'message_1', '0', '0', '0');

-- ----------------------------
-- Table structure for chat_group
-- ----------------------------
DROP TABLE IF EXISTS `chat_group`;
CREATE TABLE `chat_group` (
  `group_id` char(36) NOT NULL,
  `creator_passport_id` int(11) DEFAULT NULL,
  `created_time` int(11) DEFAULT NULL,
  `group_type` int(11) DEFAULT NULL,
  `is_delete` tinyint(4) DEFAULT NULL,
  `deleted_time` int(11) DEFAULT NULL,
  `last_message_send_id` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`group_id`),
  UNIQUE KEY `group_not_delete` (`group_id`,`is_delete`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

-- ----------------------------
-- Table structure for chat_group_member
-- ----------------------------
DROP TABLE IF EXISTS `chat_group_member`;
CREATE TABLE `chat_group_member` (
  `passport_id` int(11) NOT NULL,
  `group_id` char(36) NOT NULL,
  `name` varchar(64) DEFAULT NULL,
  `last_read_message_id` bigint(20) DEFAULT NULL,
  `token` char(36) DEFAULT NULL,
  `token_invalid_time` int(11) DEFAULT NULL,
  PRIMARY KEY (`passport_id`,`group_id`),
  KEY `group_id` (`group_id`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for chat_member_at_status
-- ----------------------------
DROP TABLE IF EXISTS `chat_member_at_status`;
CREATE TABLE `chat_member_at_status` (
  `group_id` char(36) NOT NULL,
  `members` varchar(255) DEFAULT NULL,
  `at_status` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for chat_member_unread_cnt
-- ----------------------------
DROP TABLE IF EXISTS `chat_member_unread_cnt`;
CREATE TABLE `chat_member_unread_cnt` (
  `group_id` char(36) NOT NULL,
  `member_unread_cnt_members` varchar(255) DEFAULT NULL,
  `member_unread_cnt_cnt` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for doc_chat_group
-- ----------------------------
DROP TABLE IF EXISTS `doc_chat_group`;
CREATE TABLE `doc_chat_group` (
  `group_id` char(36) NOT NULL,
  `quqi_id` int(11) DEFAULT NULL,
  `tree_id` int(11) DEFAULT NULL,
  `node_id` int(11) DEFAULT NULL,
  `node_type` int(11) DEFAULT NULL,
  `node_name` varchar(255) DEFAULT NULL,
  `quqi_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for doc_chat_group_member
-- ----------------------------
DROP TABLE IF EXISTS `doc_chat_group_member`;
CREATE TABLE `doc_chat_group_member` (
  `passport_id` int(11) NOT NULL,
  `group_id` char(36) NOT NULL,
  `recv_notify` tinyint(4) DEFAULT '0' COMMENT '是否接收动态',
  `notify_app` tinyint(4) DEFAULT '0' COMMENT '是否推送到app',
  PRIMARY KEY (`passport_id`,`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

-- ----------------------------
-- Table structure for message_1
-- ----------------------------
DROP TABLE IF EXISTS `message_1`;
CREATE TABLE `message_1` (
  `group_id` char(48) NOT NULL,
  `id` bigint(20) NOT NULL,
  `message_level` smallint(6) DEFAULT NULL,
  `sender` int(11) DEFAULT NULL,
  `name` varchar(60) DEFAULT NULL,
  `content` varchar(10240) CHARACTER SET utf8mb4 DEFAULT NULL,
  PRIMARY KEY (`group_id`,`id`),
  KEY `time` (`id`) USING BTREE,
  KEY `group_id` (`group_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for task_chat_group
-- ----------------------------
DROP TABLE IF EXISTS `task_chat_group`;
CREATE TABLE `task_chat_group` (
  `group_id` char(36) NOT NULL,
  `task_id` bigint(15) DEFAULT NULL,
  `task_name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`group_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for task_wechat_mina_tm_sendable
-- ----------------------------
DROP TABLE IF EXISTS `task_wechat_mina_tm_sendable`;
CREATE TABLE `task_wechat_mina_tm_sendable` (
  `task_id` bigint(15) NOT NULL,
  `passport_id` int(11) NOT NULL,
  `sendable` tinyint(3) NOT NULL,
  `create_time` int(10) DEFAULT NULL,
  `update_time` int(10) DEFAULT NULL,
  PRIMARY KEY (`task_id`,`passport_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
```