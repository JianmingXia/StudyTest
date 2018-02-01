#include "PreCompiled.h"
#include "Common.h"
#include "TaskManager.h"
#include "Setting.h"
#include "TaskDB.h"
#include "TaskRelayDB.h"

SINGLETON_DEFINITION(TaskManager);
static ThreadPool task_manager_thread_pool(1);

TaskManager::TaskManager()
{

}

TaskManager::~TaskManager()
{

}

void TaskManager::init()
{
	AutoWrLock lock(_lock);

	DBPair cond;
	cond.push("is_deleted", "0");

	auto rows = TaskDB::getInstance().fetchRows(DBUtil::makeSelectSql(Setting::getInstance().table__task(), cond));
	Int cnt = rows->getRowCount();
	if (cnt == 0)
	{
		llogln("TABLE__TASK is empty") ;
	}

	TaskIdChildTaskIdsMap task_id_children_map;
	for (Int i = 0; i < cnt; i++) 
	{
		DataRow::Ptr row = rows->getDataRow(i);

		Task* task = new Task();
		task->loadFromRow(row);
		_task_ptr_map[task->task_id()] = task;
		if (task->haveParent()) 
		{
			task_id_children_map[task->parent_id()].insert(task->task_id());
		}
	}

	// 任务结构
	_organizeParentTask(task_id_children_map);

	// 初始化任务成员
	_initMembers();

	// 合并至根任务成员
	_mergeToRootTaskMembers();

	// 任务管理员
	_setTaskAdmin();

	// 任务成员新建
	_newTaskMember();

	// 默认任务成员看过全部任务
	_newPassportViewTask();

	// 联系人列表重构
	_newPassportTaskList();
}

void TaskManager::_organizeParentTask(const TaskIdChildTaskIdsMap& task_id_children_map)
{
	FOR_EACH_EX(task_id_children_map, iter)
	{
		Task *parent_task = _getTask(iter->first);
		if (parent_task)
		{
			Int64Set task_ids = iter->second;
			FOR_EACH(Int64Set, task_ids, task_id_iter)
			{
				Task *task = _getTask(*task_id_iter);
				if (task)
				{
					parent_task->addChild(task);
				}
			}
		}
	}
}

Task * TaskManager::_getTask(int_64 task_id)
{
	RETURN_FIND_IN_MAP_EX(_task_ptr_map, task_id);
}

void TaskManager::_initMembers()
{
	String sql = DBUtil::makeSelectSql(Setting::getInstance().table__task_plugin_member_old());

	auto rows = TaskDB::getInstance().fetchRows(sql);

	Int cnt = rows->getRowCount();
	if (cnt == 0)
	{
		return;
	}

	for (Int i = 0; i < cnt; i++)
	{
		DataRow::Ptr row = rows->getDataRow(i);
		Task* task = _getTask(row->getInt64("task_id"));

		if (task == NULL)
		{
			continue;
		}

		task->member_ids(StringUtil::splitInt32(row->getString("passport_ids")));

		task->checkMember();
	}
}

void TaskManager::_mergeToRootTaskMembers()
{
	FOR_EACH_EX(_task_ptr_map, iter)
	{
		Task* task = iter->second;

		if (task && false == task->haveParent())
		{
			Int32Vector child_task_members;

			task->getChildTaskMembers(child_task_members);

			task->mergeChildTaskMembers(child_task_members);
		}
	}
}

void TaskManager::_setTaskAdmin()
{
	FOR_EACH_EX(_task_ptr_map, iter)
	{
		Task* task = iter->second;

		if (task && false == task->haveParent())
		{
			task->setTaskAdmin();
		}
	}
}

void TaskManager::_newTaskMember()
{
	FOR_EACH_EX(_task_ptr_map, iter)
	{
		Task* task = iter->second;

		if (task && false == task->haveParent())
		{
			task->newTaskMember();
		}
	}
}

void TaskManager::_newPassportViewTask()
{
	FOR_EACH_EX(_task_ptr_map, iter)
	{
		Task* task = iter->second;

		if (task && false == task->haveParent())
		{
			task->newPassportViewTask();
		}
	}
}

void TaskManager::_newPassportTaskList()
{
	PassportTaskIdsMap passport_tasks_map;

	FOR_EACH_EX(_task_ptr_map, iter)
	{
		Task* task = iter->second;

		if (task && false == task->haveParent())
		{
			FOR_EACH_EX(task->member_ids(), iter)
			{
				Int64Vector& task_ids = passport_tasks_map[*iter];

				if (false == IN_VECTOR(task_ids, task->task_id()))
				{
					task_ids.push_back(task->task_id());
				}
			}
		}
	}

	FOR_EACH_EX(passport_tasks_map, iter)
	{
		DBPair data;
		data.push("passport_id", iter->first);
		data.push("task_ids", StringUtil::joinInt64(iter->second));

		TaskRelayDB::getInstance().query(DBUtil::makeInsertSql(Setting::getInstance().table__passport_task_list(),
			data));
	}
}
