#pragma once

class QuqiIdMap
{
	SINGLETON_DECLARATION(QuqiIdMap);

public:
	QuqiIdMap();
	~QuqiIdMap();

	void init();
	int_32 getQuqiServerId(int_32 quqi_id);

private:
	Int32Int32UnorderedMap _id_map;
	Mutex _id_map_lock;
};