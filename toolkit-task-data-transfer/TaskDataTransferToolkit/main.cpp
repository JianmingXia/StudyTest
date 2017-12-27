#include "PreCompiled.h"
#include "Setting.h"
#include "TaskDB.h"
#include "TaskRelayDB.h"
#include "TaskManager.h"

int main(int argc, char **argv)
{
	CommandParser::getInstance().init(argc, argv);
	Setting::getInstance().init();

	String db_host = Setting::getInstance().db_host();
	int_32 db_port = Setting::getInstance().db_port();
	int_32 db_connect = Setting::getInstance().db_connect();

	if (false == TaskDB::getInstance().start<DBMysql>(db_host, db_port,
		Setting::getInstance().task_db_user(),
		Setting::getInstance().task_db_password(),
		Setting::getInstance().task_db_name(),
		db_connect))
	{
		llogln("TaskDB start fail");
		exit(1);
	}

	if (false == TaskRelayDB::getInstance().start<DBMysql>(db_host, db_port,
		Setting::getInstance().task_relay_db_user(),
		Setting::getInstance().task_relay_db_password(),
		Setting::getInstance().task_relay_db_name(),
		db_connect))
	{
		llogln("TaskRelayDB start fail");
		exit(1);
	}

	TaskManager::getInstance().init();

	llogln("TaskDataTransfer end");

	Signal s;
	s.wait();
}