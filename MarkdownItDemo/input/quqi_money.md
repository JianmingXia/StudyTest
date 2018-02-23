# quqi_money

## 新建数据表
```
DROP TABLE IF EXISTS `cfg_holiday`;
CREATE TABLE `cfg_holiday` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `start_date` varchar(50) DEFAULT NULL COMMENT '假期开始日期，格式YYYY-MM-DD',
  `end_date` varchar(50) DEFAULT NULL COMMENT '结束日期',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COMMENT='法定节假日';

-- ----------------------------
-- Table structure for cfg_whitelist
-- ----------------------------
DROP TABLE IF EXISTS `cfg_whitelist`;
CREATE TABLE `cfg_whitelist` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `ip` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for log_change
-- ----------------------------
DROP TABLE IF EXISTS `log_change`;
CREATE TABLE `log_change` (
  `change_id` varchar(50) NOT NULL COMMENT '变化记录号，系统生成唯一',
  `order_id` varchar(50) NOT NULL COMMENT '对应订单号',
  `type` int(11) NOT NULL COMMENT '变化类型，0为余额不变，1为增加，1为余额减少',
  `time` bigint(20) NOT NULL DEFAULT '0' COMMENT '变化时间',
  `quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应quqi账户id',
  `is_company` tinyint(4) DEFAULT NULL COMMENT '是否团队账户',
  `account_id` int(11) DEFAULT NULL COMMENT '对应的passport_id或company_id',
  `name` varchar(50) DEFAULT NULL COMMENT '账户名',
  `coin_num` double NOT NULL DEFAULT '0' COMMENT '变化曲奇币金额',
  `coin_balance` double NOT NULL DEFAULT '0' COMMENT '剩余曲奇币',
  `detail` varchar(255) NOT NULL DEFAULT '0' COMMENT '描述',
  PRIMARY KEY (`change_id`),
  KEY `type` (`type`) USING BTREE,
  KEY `quqi_id` (`quqi_id`) USING BTREE,
  KEY `order_id` (`order_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for order_cost
-- ----------------------------
DROP TABLE IF EXISTS `order_cost`;
CREATE TABLE `order_cost` (
  `cost_id` varchar(50) NOT NULL COMMENT '订单号，系统生成唯一',
  `parent_cost_id` varchar(50) DEFAULT NULL COMMENT '如果是父团队代扣费，父团队消耗订单号',
  `type` int(11) NOT NULL COMMENT '消耗类型，1文档消耗,2代扣消费',
  `time` bigint(20) NOT NULL DEFAULT '0' COMMENT '消耗时间，为0点整数时间戳',
  `quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应消耗quqi账户id',
  `is_company` tinyint(4) DEFAULT NULL COMMENT '是否团队账户',
  `account_id` int(11) DEFAULT NULL COMMENT '对应的passport_id或company_id',
  `name` varchar(50) DEFAULT NULL COMMENT '账户名',
  `cost_doc_num` int(11) DEFAULT '0' COMMENT '文档消耗数，默认为0',
  `cost_coin` double NOT NULL COMMENT '消耗曲奇币金额',
  PRIMARY KEY (`cost_id`),
  KEY `type` (`type`) USING BTREE,
  KEY `quqi_id` (`quqi_id`) USING BTREE,
  KEY `change_id` (`parent_cost_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for order_gift
-- ----------------------------
DROP TABLE IF EXISTS `order_gift`;
CREATE TABLE `order_gift` (
  `gift_id` varchar(50) NOT NULL COMMENT '订单号，系统生成唯一',
  `type` int(11) NOT NULL COMMENT '赠送类型，例如1注册赠送，2为邀请赠送,3充值赠送，4首冲赠送，5后台赠送，6曲奇卷兑换',
  `pay_order_id` varchar(50) DEFAULT NULL COMMENT '若为充值返点，对应的充值订单号',
  `time` bigint(20) NOT NULL DEFAULT '0' COMMENT '赠送时间',
  `status` tinyint(4) NOT NULL DEFAULT '0' COMMENT '是否生效',
  `quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应赠送quqi账户id',
  `is_company` tinyint(4) DEFAULT NULL COMMENT '是否团队账户',
  `account_id` int(11) DEFAULT NULL COMMENT '对应的passport_id或company_id',
  `name` varchar(50) DEFAULT NULL COMMENT '账户名',
  `gift_coin` double NOT NULL DEFAULT '0' COMMENT '赠送曲奇币金额',
  `detail` text COMMENT '备注信息',
  PRIMARY KEY (`gift_id`),
  KEY `quqi_id` (`quqi_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for order_pay
-- ----------------------------
DROP TABLE IF EXISTS `order_pay`;
CREATE TABLE `order_pay` (
  `order_id` varchar(50) NOT NULL COMMENT '订单号，系统生成唯一',
  `type` int(11) NOT NULL COMMENT '充值渠道，例如1为支付宝，2为微信',
  `type_order_id` varchar(50) DEFAULT NULL COMMENT '充值渠道中对应的订单号',
  `time` bigint(20) NOT NULL DEFAULT '0' COMMENT '充值时间',
  `status` tinyint(4) NOT NULL DEFAULT '0' COMMENT '是否生效',
  `quqi_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应充值quqi账户id',
  `is_company` tinyint(4) NOT NULL DEFAULT '0' COMMENT '是否团队账户',
  `account_id` int(11) DEFAULT NULL COMMENT '对应的passport_id或company_id',
  `name` varchar(50) DEFAULT NULL COMMENT '账户名',
  `operate_id` int(11) DEFAULT NULL COMMENT '操作人passport_id',
  `pay_money` double NOT NULL COMMENT '充值现金到帐金额',
  `pay_coin` double NOT NULL COMMENT '充值曲奇币金额',
  `pay_ip` varchar(50) DEFAULT NULL COMMENT '充值ip',
  PRIMARY KEY (`order_id`),
  UNIQUE KEY `type_type_order_id` (`type`,`type_order_id`) USING BTREE,
  KEY `quqi_id` (`quqi_id`) USING BTREE,
  KEY `operate_id` (`operate_id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- ----------------------------
-- Table structure for order_voucher
-- ----------------------------
DROP TABLE IF EXISTS `order_voucher`;
CREATE TABLE `order_voucher` (
  `voucher_id` varchar(50) NOT NULL COMMENT '订单号，系统生成唯一',
  `type` int(11) NOT NULL COMMENT '发放类型，例如1为邀请人注册账号，2为邀请人创建团队，3为邀请人充值20000曲奇币以上，4系统赠送',
  `bind_passport_id` int(11) NOT NULL COMMENT '被邀请人passport_id',
  `status` tinyint(4) NOT NULL COMMENT '是否使用',
  `time` bigint(20) NOT NULL COMMENT '发放时间',
  `quqi_id` int(11) NOT NULL COMMENT '对应发放的quqi账户id',
  `account_id` int(11) NOT NULL COMMENT '对应的passport_id',
  `name` varchar(50) NOT NULL COMMENT '账户名',
  `voucher_coin` double NOT NULL COMMENT '曲奇券金额',
  PRIMARY KEY (`voucher_id`),
  KEY `type` (`type`) USING BTREE,
  KEY `bind_passport_id` (`bind_passport_id`) USING BTREE,
  KEY `quqi_id` (`quqi_id`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for sys_passport_bind
-- ----------------------------
DROP TABLE IF EXISTS `sys_passport_bind`;
CREATE TABLE `sys_passport_bind` (
  `passport_id` int(11) NOT NULL COMMENT '新注册用户',
  `bind_passport_id` int(11) NOT NULL COMMENT '发出邀请的老用户',
  PRIMARY KEY (`passport_id`),
  KEY `bind_passport_id` (`bind_passport_id`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED;

-- ----------------------------
-- Table structure for sys_voucher
-- ----------------------------
DROP TABLE IF EXISTS `sys_voucher`;
CREATE TABLE `sys_voucher` (
  `voucher_id` varchar(50) NOT NULL COMMENT '订单号，系统生成唯一',
  `passport_id` int(11) NOT NULL DEFAULT '0' COMMENT '对应发放的passport账户id',
  `time` bigint(20) NOT NULL DEFAULT '0' COMMENT '发放时间,加一年为过期时间',
  `status` tinyint(4) NOT NULL DEFAULT '0' COMMENT '使用状态，0未使用，1使用，2过期',
  `use_time` bigint(20) NOT NULL DEFAULT '0' COMMENT '使用时间',
  `use_name` varchar(50) DEFAULT NULL COMMENT '充值团队名',
  `voucher_coin` double NOT NULL DEFAULT '0' COMMENT '曲奇券金额',
  PRIMARY KEY (`voucher_id`),
  KEY `passport_id_status` (`passport_id`,`status`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
```