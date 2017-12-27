#pragma once

class QuqiSocketClient
{
public:
	QuqiSocketClient();
	~QuqiSocketClient();

public:
	void start(const String &ip, int_32 port, int_32 client_id);

	void dispatch(NetData::Ptr data);
	void call(NetData::Ptr data, NetCallback succ_callback, NetCallback timeout_callback = NetCallback(), int_32 timeout_limit = -1);

	virtual void onConnected();
	virtual void onDisconnected(int_32 dr);
	virtual void onConnecteFailed();

	void onNotifyConvertToPic(NetData::Ptr data);

	DEFINE_PROPERTY(int_32, server_id);

protected:
	SocketClientService _socket;
};