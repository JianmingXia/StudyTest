#include "PreCompiled.h"
#include "QuqiIdMap.h"

#include "Sdk/CenterServer/CenterServerSdk.h"

SINGLETON_DEFINITION(QuqiIdMap);
QuqiIdMap::QuqiIdMap()
{

}


QuqiIdMap::~QuqiIdMap()
{

}

void QuqiIdMap::init()
{
	JsonValue json_data;
	if (false == CenterServerSdk::requestData("center/quqi_to_server_mapping", json_data))
	{
		lerrorln("QuqiIdMap::init: request center/quqi_to_server_mapping failed");
	}

	JsonValue &data = json_data["service_infos"];
	int_32 cnt = data.size();
	for (int_32 i = 0; i < cnt; ++i)
	{
		JsonValue &id_map = data[i];
		_id_map.insert(make_pair(id_map["quqi_id"].asInt(), id_map["server_id"].asInt()));
	}
}

int_32 QuqiIdMap::getQuqiServerId( int_32 quqi_id )
{
	AutoLock lock(_id_map_lock);

	Int32Int32UnorderedMap::iterator find_iter = _id_map.find(quqi_id);
	if (find_iter != _id_map.end())
	{
		return find_iter->second;
	}

	JsonValue json_data;
	StringStringMap param;
	param.insert(make_pair("quqi_id", StringUtil::toString(quqi_id)));
	if (false == CenterServerSdk::requestData("center/query_quqi_to_server_mapping", param, json_data))
	{
		lerrorln("QuqiIdMap::init: request center/query_quqi_to_server_mapping failed");
	}

	int_32 server_id = json_data["server_id"].asInt();
	if (server_id != -1)
	{
		_id_map.insert(make_pair(quqi_id, server_id));
	}
	
	return server_id;
}