#include "PreCompiled.h"
#include "QuqiSocketClientManager.h"

#include "QuqiSocketClient.h"

SINGLETON_DEFINITION(QuqiSocketClientManager);
QuqiSocketClientManager::QuqiSocketClientManager()
{

}

QuqiSocketClientManager::~QuqiSocketClientManager()
{

}

void QuqiSocketClientManager::addClient( QuqiSocketClient *client )
{
	AutoLock lock(_socket_client_map_lock);
	_socket_client_map[client->server_id()] = client;
}

void QuqiSocketClientManager::removeClient( QuqiSocketClient *client )
{
	AutoLock lock(_socket_client_map_lock);
	REMOVE_ELEM_IN_MAP_OR_SET_EX(_socket_client_map, client->server_id());
}

void QuqiSocketClientManager::call( int_32 server_id, NetData::Ptr data, NetCallback succ_callback, NetCallback timeout_callback /*= NetCallback()*/, int_32 timeout_limit /*= -1*/ )
{
	AutoLock lock(_socket_client_map_lock);

	QuqiSocketClient *client = getClient(server_id);
	if (client == NULL)
	{
		timeout_callback(NetData::Ptr());
	}
	else
	{
		client->call(data, succ_callback, timeout_callback, timeout_limit);
	}
}

void QuqiSocketClientManager::dispatch( int_32 server_id, NetData::Ptr data )
{
	AutoLock lock(_socket_client_map_lock);

	QuqiSocketClient *client = getClient(server_id);
	if (client != NULL)
	{
		client->dispatch(data);
	}
}

QuqiSocketClient * QuqiSocketClientManager::getClient(int_32 server_id)
{
	RETURN_FIND_IN_MAP_EX(_socket_client_map, server_id);
}