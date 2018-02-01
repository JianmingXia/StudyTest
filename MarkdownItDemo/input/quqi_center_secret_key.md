# quqi_center_secret_key

# 同步数据表
```
-- ----------------------------
-- Table structure for cfg_approval_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_approval_db`;
CREATE TABLE `cfg_approval_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of cfg_approval_db
-- ----------------------------
INSERT INTO `cfg_approval_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_approval', 'doc', 'doc', '8');

-- ----------------------------
-- Table structure for cfg_auth_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_auth_db`;
CREATE TABLE `cfg_auth_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_auth_db
-- ----------------------------
INSERT INTO `cfg_auth_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_auth', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_auth_secret_code_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_auth_secret_code_db`;
CREATE TABLE `cfg_auth_secret_code_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_auth_secret_code_db
-- ----------------------------
INSERT INTO `cfg_auth_secret_code_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_auth_secret_code', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_center_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_center_db`;
CREATE TABLE `cfg_center_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_center_db
-- ----------------------------
INSERT INTO `cfg_center_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_center', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_chat_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_chat_db`;
CREATE TABLE `cfg_chat_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_chat_db
-- ----------------------------
INSERT INTO `cfg_chat_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_chat', 'doc', 'doc', '8');

-- ----------------------------
-- Table structure for cfg_log_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_log_db`;
CREATE TABLE `cfg_log_db` (
  `server` varchar(255) NOT NULL,
  `host` char(16) DEFAULT NULL,
  `port` int(11) DEFAULT NULL,
  `username` varchar(32) DEFAULT NULL,
  `password` varchar(64) DEFAULT NULL,
  `dbname` varchar(64) DEFAULT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`server`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of cfg_log_db
-- ----------------------------
INSERT INTO `cfg_log_db` VALUES ('auth', '127.0.0.1', '3306', 'doc', 'doc', 'quqi_auth_log', '1');
INSERT INTO `cfg_log_db` VALUES ('doc', '127.0.0.1', '3306', 'doc', 'doc', 'quqi_document_log', '1');

-- ----------------------------
-- Table structure for cfg_log_operate_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_log_operate_db`;
CREATE TABLE `cfg_log_operate_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_log_operate_db
-- ----------------------------
INSERT INTO `cfg_log_operate_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_log', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_message_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_message_db`;
CREATE TABLE `cfg_message_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  `character` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_message_db
-- ----------------------------
INSERT INTO `cfg_message_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_message', 'doc', 'doc', '2', 'utf8mb4');

-- ----------------------------
-- Table structure for cfg_money_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_money_db`;
CREATE TABLE `cfg_money_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_money_db
-- ----------------------------
INSERT INTO `cfg_money_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_money', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_monitor_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_monitor_db`;
CREATE TABLE `cfg_monitor_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_monitor_db
-- ----------------------------
INSERT INTO `cfg_monitor_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_backend', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_notify_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_notify_db`;
CREATE TABLE `cfg_notify_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_notify_db
-- ----------------------------
INSERT INTO `cfg_notify_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_notify', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_push_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_push_db`;
CREATE TABLE `cfg_push_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of cfg_push_db
-- ----------------------------
INSERT INTO `cfg_push_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_push', 'doc', 'doc', '8');

-- ----------------------------
-- Table structure for cfg_quqi_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_quqi_db`;
CREATE TABLE `cfg_quqi_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_quqi_db
-- ----------------------------
INSERT INTO `cfg_quqi_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_document1', 'doc', 'doc', '2');
INSERT INTO `cfg_quqi_db` VALUES ('3', '127.0.0.1', '3306', 'quqi_server', 'doc', 'doc', '2');
INSERT INTO `cfg_quqi_db` VALUES ('4', '127.0.0.1', '3306', 'quqi_report_1', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_sdk_proxy_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_sdk_proxy_db`;
CREATE TABLE `cfg_sdk_proxy_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_sdk_proxy_db
-- ----------------------------
INSERT INTO `cfg_sdk_proxy_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_sdk_proxy', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_session_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_session_db`;
CREATE TABLE `cfg_session_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Records of cfg_session_db
-- ----------------------------
INSERT INTO `cfg_session_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_session', 'doc', 'doc', '2');

-- ----------------------------
-- Table structure for cfg_task_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_task_db`;
CREATE TABLE `cfg_task_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of cfg_task_db
-- ----------------------------
INSERT INTO `cfg_task_db` VALUES ('1', '10.0.3.105', '3306', 'quqi_task_relay', 'doc', 'doc', '8');
INSERT INTO `cfg_task_db` VALUES ('2', '10.0.3.105', '3306', 'quqi_task_router', 'doc', 'doc', '8');
INSERT INTO `cfg_task_db` VALUES ('3', '10.0.3.105', '3306', 'quqi_task1', 'doc', 'doc', '8');
INSERT INTO `cfg_task_db` VALUES ('4', '10.0.3.105', '3306', 'quqi_task2', 'doc', 'doc', '8');

-- ----------------------------
-- Table structure for cfg_updown_db
-- ----------------------------
DROP TABLE IF EXISTS `cfg_updown_db`;
CREATE TABLE `cfg_updown_db` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `host` varchar(255) NOT NULL,
  `port` int(11) NOT NULL,
  `dbname` varchar(255) NOT NULL,
  `username` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `connect_cnt` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of cfg_updown_db
-- ----------------------------
INSERT INTO `cfg_updown_db` VALUES ('1', '127.0.0.1', '3306', 'quqi_updown', 'doc', 'doc', '8');
```
