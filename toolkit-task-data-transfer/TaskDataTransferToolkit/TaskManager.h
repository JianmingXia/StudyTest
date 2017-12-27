#include "Task.h"

typedef UnorderedMap<int_64, Int64Set>	TaskIdChildTaskIdsMap;
typedef UnorderedMap<Int, Int64Vector>	PassportTaskIdsMap;

class TaskManager 
{
	SINGLETON_DECLARATION(TaskManager);
public:
	TaskManager();
	~TaskManager();

	void init();

private:
	void _organizeParentTask(const TaskIdChildTaskIdsMap& task_id_children_map);
	Task *_getTask(int_64 task_id);
	void _initMembers();
	void _mergeToRootTaskMembers();

	// 更新数据
	void _setTaskAdmin();
	void _newTaskMember();
	void _newPassportViewTask();
	void _newPassportTaskList();

private:
	TaskPtrMap _task_ptr_map;
	RwLock _lock;
};
