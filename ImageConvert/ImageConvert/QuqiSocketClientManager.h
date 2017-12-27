#pragma once

class QuqiSocketClient;
class QuqiSocketClientManager
{
	SINGLETON_DECLARATION(QuqiSocketClientManager);

public:
	QuqiSocketClientManager();
	~QuqiSocketClientManager();

	void addClient(QuqiSocketClient *client);
	void removeClient(QuqiSocketClient *client);

	void call(int_32 server_id, NetData::Ptr data, NetCallback succ_callback, NetCallback timeout_callback = NetCallback(), int_32 timeout_limit = -1);
	void dispatch(int_32 server_id, NetData::Ptr data);

private:
	QuqiSocketClient *getClient(int_32 server_id);

private:
	typedef UnorderedMap<int_32, QuqiSocketClient*> QuqiSocketClientMap;

	Mutex _socket_client_map_lock;
	QuqiSocketClientMap _socket_client_map;
};