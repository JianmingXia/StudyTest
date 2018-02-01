#include "PreCompiled.h"
#include "Task.h"
#include "Common.h"
#include "TaskManager.h"
#include "Setting.h"
#include "TaskDB.h"

Task::Task()
{
}

Task::~Task()
{
}

void Task::loadFromRow(DataRow::Ptr row)
{
	_admin_passport_id = 0;

	_task_id = row->getInt64("task_id");
	_parent_id = row->getInt64("parent_id");
	_passport_id = row->getInt32("passport_id");
	_name = row->getString("name");
	_create_time = row->getInt32("create_time");
}

bool Task::haveParent()
{
	return _parent_id > 0;
}

void Task::setParent(Task* parent)
{
	_parent_task = parent;
}

void Task::addChild(Task* task)
{
	task->parent_id(_task_id);
	task->setParent(this);
	_children[task->task_id()] = task;
}

void Task::checkMember()
{
	for (Int32Vector::iterator iter = _member_ids.begin(); iter != _member_ids.end(); )
	{
		if (*iter == 0)
		{
			iter = _member_ids.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void Task::getChildTaskMembers(Int32Vector& member_ids)
{
	FOR_EACH_EX(_children, iter)
	{
		Task* child_task = iter->second;

		if (child_task)
		{
			member_ids.insert(member_ids.end(), child_task->member_ids().begin(), child_task->member_ids().end());

			child_task->getChildTaskMembers(member_ids);
		}
	}
}

void Task::mergeChildTaskMembers(Int32Vector& member_ids)
{
	FOR_EACH_EX(member_ids, iter)
	{
		if (false == IN_VECTOR(_member_ids, *iter))
		{
			_member_ids.push_back(*iter);
		}
	}

	sort(_member_ids.begin(), _member_ids.end(), less<Int>());
}

void Task::getChildTaskIds(Int64Vector& task_ids)
{
	FOR_EACH_EX(_children, iter)
	{
		Task* child_task = iter->second;

		if (child_task)
		{
			task_ids.push_back(child_task->task_id());

			child_task->getChildTaskIds(task_ids);
		}
	}
}

void Task::setTaskAdmin()
{
	if (IN_VECTOR(_member_ids, _passport_id))
	{
		_admin_passport_id = _passport_id;
	}
	else
	{
		if (_member_ids.size() > 0)
		{
			_admin_passport_id = _member_ids[0];
		}
	}

	if (_admin_passport_id > 0)
	{
		DBPair cond;
		cond.push("task_id", _task_id);

		DBPair data;
		data.push("admin_passport_id", _admin_passport_id);

		TaskDB::getInstance().query(DBUtil::makeUpdateSql(Setting::getInstance().table__task(), 
			data, cond));
	}
	else
	{
		llogln("Task no admin: task_id: %lld", _task_id);
	}
}

void Task::newTaskMember()
{
	FOR_EACH_EX(_member_ids, iter)
	{
		DBPair data;
		data.push("task_id", _task_id);
		data.push("passport_id", *iter);
		data.push("join_time", _create_time);
		data.push("is_deleted", 0);

		TaskDB::getInstance().query(DBUtil::makeInsertSql(Setting::getInstance().table__task_plugin_member(),
			data));
	}
}

void Task::newPassportViewTask()
{
	Int64Vector task_ids;
	getChildTaskIds(task_ids);
	task_ids.push_back(_task_id);

	FOR_EACH_EX(_member_ids, iter)
	{
		FOR_EACH_EX(task_ids, task_id)
		{
			DBPair data;
			data.push("task_id", *task_id);
			data.push("passport_id", *iter);
			data.push("is_new_task", 0);
			data.push("have_new_update", 0);

			TaskDB::getInstance().query(DBUtil::makeInsertSql(Setting::getInstance().table__task_passport_changed(),
				data));
		}
	}
}
