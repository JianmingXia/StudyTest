# quqi_document_log

## 新建表
```
DROP TABLE IF EXISTS `log_department_group_opt`;
CREATE TABLE `log_department_group_opt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) DEFAULT NULL,
  `operate_type` int(11) DEFAULT NULL,
  `department_id` int(11) DEFAULT NULL,
  `time` int(10) DEFAULT NULL,
  `param_1` varchar(1024) DEFAULT NULL,
  `param_2` varchar(1024) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for log_group_opt
-- ----------------------------
DROP TABLE IF EXISTS `log_group_opt`;
CREATE TABLE `log_group_opt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `group_id` int(11) DEFAULT NULL,
  `operate_type` int(11) DEFAULT NULL,
  `operate_user_id` int(11) DEFAULT NULL,
  `time` int(10) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `param_1` varchar(1024) DEFAULT NULL,
  `param_2` varchar(1024) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for log_node_opt
-- ----------------------------
DROP TABLE IF EXISTS `log_node_opt`;
CREATE TABLE `log_node_opt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `quqi_id` int(11) unsigned zerofill DEFAULT NULL,
  `tree_id` int(11) unsigned zerofill DEFAULT NULL,
  `node_id` varchar(1024) DEFAULT NULL,
  `operate_user_id` int(11) DEFAULT NULL,
  `operate_type` int(11) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `time` int(10) DEFAULT NULL,
  `dest_quqi_id` int(11) unsigned zerofill DEFAULT NULL,
  `dest_tree_id` int(11) unsigned zerofill DEFAULT NULL,
  `param_1` varchar(1024) DEFAULT NULL,
  `param_2` varchar(1024) DEFAULT NULL,
  `share_id` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for log_permission_opt
-- ----------------------------
DROP TABLE IF EXISTS `log_permission_opt`;
CREATE TABLE `log_permission_opt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `quqi_tree_node_id` varchar(255) DEFAULT NULL,
  `operate_type` int(11) DEFAULT NULL,
  `operate_user_id` int(11) DEFAULT NULL,
  `time` int(10) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `param_1` varchar(1024) DEFAULT NULL,
  `param_2` varchar(1024) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for log_share_opt
-- ----------------------------
DROP TABLE IF EXISTS `log_share_opt`;
CREATE TABLE `log_share_opt` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `share_id` int(11) DEFAULT NULL,
  `operate_type` int(11) DEFAULT NULL,
  `operate_user_id` int(11) DEFAULT NULL,
  `time` int(11) DEFAULT NULL,
  `ip` varchar(255) DEFAULT NULL,
  `param_1` varchar(512) DEFAULT NULL,
  `param_2` varchar(512) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
```