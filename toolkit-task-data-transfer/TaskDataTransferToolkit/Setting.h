#pragma once
#include "Common.h"

class Setting
{
	DEFINE_PROPERTY_REF(String, db_host);
	DEFINE_PROPERTY(Int, db_port);
	DEFINE_PROPERTY(Int, db_connect);

	DEFINE_PROPERTY_REF(String, task_db_name);
	DEFINE_PROPERTY_REF(String, task_db_user);
	DEFINE_PROPERTY_REF(String, task_db_password);

	DEFINE_PROPERTY_REF(String, task_relay_db_name);
	DEFINE_PROPERTY_REF(String, task_relay_db_user);
	DEFINE_PROPERTY_REF(String, task_relay_db_password);


	DEFINE_PROPERTY_REF(String, table__task);
	DEFINE_PROPERTY_REF(String, table__task_plugin_member);
	DEFINE_PROPERTY_REF(String, table__task_passport_changed);
	DEFINE_PROPERTY_REF(String, table__task_plugin_member_old);

	DEFINE_PROPERTY_REF(String, table__passport_task_list);

	SINGLETON_DECLARATION(Setting);
public:
	Setting(void);
	~Setting(void);
	void init();
};