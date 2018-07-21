/*
Navicat MySQL Data Transfer

Source Server         : LocalHost
Source Server Version : 50505
Source Host           : localhost:3306
Source Database       : todo

Target Server Type    : MYSQL
Target Server Version : 50505
File Encoding         : 65001

Date: 2018-07-21 16:52:51
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for user
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `user_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT '主键',
  `username` varchar(32) NOT NULL COMMENT '用户名（唯一）',
  `password` char(32) NOT NULL COMMENT '密码',
  `register_at` int(10) NOT NULL COMMENT '注册时间',
  `updated_at` int(10) NOT NULL COMMENT '更新时间',
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('1', 'ryoma', '60b0e0c61e977cc8d38dc0f125098220', '1500000000', '0');