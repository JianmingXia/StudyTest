# quqi_auth_secret_code

## 新建数据库

```
CREATE TABLE `company_code` (
  `company_id` int(11) NOT NULL,
  `company_code` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`company_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Table structure for passport_code
-- ----------------------------
DROP TABLE IF EXISTS `passport_code`;
CREATE TABLE `passport_code` (
  `passport_id` int(11) NOT NULL,
  `passport_code` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`passport_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;
```

- 保证quqi_auth数据库已同步。passport_code company_code

```
insert into quqi_auth_secret_code.company_code (company_id, company_code) SELECT company_id, company_code from quqi_auth.sys_company;

insert into quqi_auth_secret_code.passport_code (passport_id, passport_code) SELECT passport_id, passport_code from quqi_auth.sys_passport;

update  passport_code set passport_code="1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16" where passport_code = "";
```