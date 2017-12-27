#pragma once
#include "Common.h"
#include "DBMySql.h"

class TaskRelayDB : public DBService
{
	SINGLETON_DECLARATION(TaskRelayDB);
public:
	TaskRelayDB();
	~TaskRelayDB(void);
};

