# quqi_push

## 新增数据表
```
DROP TABLE IF EXISTS `passport_client`;
CREATE TABLE `passport_client` (
  `passport_id` int(11) NOT NULL,
  `disk_app_client_id` varchar(255) NOT NULL,
  `office_app_client_id` varchar(255) NOT NULL,
  PRIMARY KEY (`passport_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='passport对应个推client_id';

-- ----------------------------
-- Table structure for passport_wechat_open_id
-- ----------------------------
DROP TABLE IF EXISTS `passport_wechat_open_id`;
CREATE TABLE `passport_wechat_open_id` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app_id` int(11) DEFAULT NULL,
  `passport_id` int(11) DEFAULT NULL,
  `open_id` varchar(255) DEFAULT NULL,
  `create_time` int(10) DEFAULT NULL,
  `is_delete` tinyint(3) DEFAULT NULL,
  `delete_time` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for wechat_mina_template_message
-- ----------------------------
DROP TABLE IF EXISTS `wechat_mina_template_message`;
CREATE TABLE `wechat_mina_template_message` (
  `app_id` int(10) NOT NULL,
  `quqi_template_id` int(10) NOT NULL,
  `template_id` varchar(255) DEFAULT NULL,
  `description` text,
  `emphasis_keyword` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`app_id`,`quqi_template_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Table structure for wechat_mina_tm_form_id
-- ----------------------------
DROP TABLE IF EXISTS `wechat_mina_tm_form_id`;
CREATE TABLE `wechat_mina_tm_form_id` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `app_id` int(10) NOT NULL,
  `passport_id` int(11) NOT NULL,
  `form_id` varchar(255) DEFAULT NULL,
  `create_time` int(10) DEFAULT NULL,
  `status` tinyint(3) DEFAULT NULL,
  `update_time` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;
```