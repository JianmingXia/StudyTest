#pragma once

class Task;
typedef UnorderedMap<int_64, Task*> TaskMap;

class Task 
{
	DEFINE_PROPERTY(int_64, task_id);
	DEFINE_PROPERTY(int_64, parent_id);
	DEFINE_PROPERTY(Int, passport_id);
	DEFINE_PROPERTY_REF(String, name);
	DEFINE_PROPERTY(Int, admin_passport_id);
	DEFINE_PROPERTY(Int, create_time);

	// 任务成员
	DEFINE_PROPERTY_REF(Int32Vector, member_ids);

	Task *_parent_task;
	TaskMap _children;

public : 
	Task();
	~Task();

	void loadFromRow(DataRow::Ptr row);

	bool haveParent();
	void setParent(Task* parent);
	void addChild(Task* task);

	void getChildTaskMembers(Int32Vector& member_ids);
	void mergeChildTaskMembers(Int32Vector& member_ids);
	void getChildTaskIds(Int64Vector& task_ids);

	void setTaskAdmin();
	void newTaskMember();
	void newPassportViewTask();
};

typedef UnorderedMap<int_64, Task*> TaskPtrMap;
