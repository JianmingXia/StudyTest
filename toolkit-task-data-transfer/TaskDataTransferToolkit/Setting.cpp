#include "PreCompiled.h"
#include "Setting.h"

SINGLETON_DEFINITION(Setting);
Setting::Setting(void)
{
}


Setting::~Setting(void)
{
}

void Setting::init()
{
	_db_host = CommandParser::getInstance().getString("db_host", "10.0.3.105");
	_db_port = CommandParser::getInstance().getInt32("db_port", 3306);
	_db_connect = CommandParser::getInstance().getInt32("db_connect", 1);

	_task_db_name = CommandParser::getInstance().getString("task_db_name", "quqi_task1");
	_task_db_user = CommandParser::getInstance().getString("task_db_user", "doc");
	_task_db_password = CommandParser::getInstance().getString("task_db_password", "doc");

	_task_relay_db_name = CommandParser::getInstance().getString("task_relay_db_name", "quqi_task_relay");
	_task_relay_db_user = CommandParser::getInstance().getString("task_relay_db_user", "doc");
	_task_relay_db_password = CommandParser::getInstance().getString("task_relay_db_password", "doc");

	_table__task = CommandParser::getInstance().getString("table__task", "task");
	_table__task_plugin_member = CommandParser::getInstance().getString("table__task_plugin_member", "task_plugin_member");
	_table__task_passport_changed = CommandParser::getInstance().getString("table__task_passport_changed", "task_passport_changed");
	_table__task_plugin_member_old = CommandParser::getInstance().getString("table__task_plugin_member_old", "task_plugin_member_old");

	_table__passport_task_list = CommandParser::getInstance().getString("table__passport_task_list", "passport_task_list");
}