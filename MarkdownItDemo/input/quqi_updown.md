# quqi_updown

## 同步表结构
```
DROP TABLE IF EXISTS `node_vod`;
CREATE TABLE `node_vod` (
  `quqi_id` int(11) NOT NULL,
  `node_id` int(11) NOT NULL,
  `version` int(11) NOT NULL,
  `file_id` varchar(255) NOT NULL DEFAULT '' COMMENT '腾讯云fileid',
  `vod_url` varchar(255) NOT NULL DEFAULT '' COMMENT '原始视频播放链接',
  `vod_edk` varchar(255) NOT NULL DEFAULT '' COMMENT '加密后的数据秘钥',
  `vod_dk` varchar(255) NOT NULL DEFAULT '' COMMENT 'base64编码的数据密钥',
  `add_time` int(11) NOT NULL DEFAULT '0' COMMENT '上传时间',
  `update_time` int(11) NOT NULL DEFAULT '0' COMMENT '状态更新时间',
  `status` int(11) NOT NULL DEFAULT '0' COMMENT '转码状态，1正在转码，2转码完成，3转码失败',
  PRIMARY KEY (`quqi_id`,`node_id`,`version`),
  UNIQUE KEY `file_id` (`file_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='点播视频上传转码记录';
```