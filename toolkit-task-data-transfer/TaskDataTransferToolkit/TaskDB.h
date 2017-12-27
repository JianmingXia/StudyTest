#pragma once
#include "Common.h"
#include "DBMySql.h"

class TaskDB : public DBService
{
	SINGLETON_DECLARATION(TaskDB);
public:
	TaskDB();
	~TaskDB(void);

	DataTable::Ptr getTeamInfos(const String& sql);
};