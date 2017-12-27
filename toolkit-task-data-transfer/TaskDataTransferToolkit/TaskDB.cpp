#include "PreCompiled.h"
#include "TaskDB.h"

SINGLETON_DEFINITION(TaskDB);

TaskDB::TaskDB()
{

}

TaskDB::~TaskDB(void)
{

}

DataTable::Ptr TaskDB::getTeamInfos(const String& sql)
{
	return TaskDB::getInstance().fetchRows(sql);
}
