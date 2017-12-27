#include "PreCompiled.h"
#include "QuqiSocketClient.h"

#include "Const.h"
#include "Setting.h"
#include "ConvertManager.h"

#include "Sdk/Quqi/ConvertToPicInfo.h"

USING_NS_QUQI_SDK;

QuqiSocketClient::QuqiSocketClient()
{
	_server_id = 0;
}

QuqiSocketClient::~QuqiSocketClient()
{

}

void QuqiSocketClient::start( const String &ip, int_32 port, int_32 client_id )
{
	_socket.server_ip(ip);
	_socket.server_port(port);
	_socket.client_id(client_id);

	_socket.setConnectedCallback(boost::bind(&QuqiSocketClient::onConnected, this));
	_socket.setConnectFailedCallback(boost::bind(&QuqiSocketClient::onConnecteFailed, this));
	_socket.setDisconnectCallback(boost::bind(&QuqiSocketClient::onDisconnected, this, _1));

	_socket.registerNotify(::Proc::QS_2_US_CONVERT_TO_PIC, boost::bind(&QuqiSocketClient::onNotifyConvertToPic, this, _1));

#ifdef WIN32
	_socket.call_timeout_limit(99999);
#endif
	_socket.start();
}

void QuqiSocketClient::dispatch( NetData::Ptr data )
{
	_socket.dispatch(data);
}

void QuqiSocketClient::call( NetData::Ptr data, NetCallback succ_callback, NetCallback timeout_callback /*= NetCallback()*/, int_32 timeout_limit /*= -1*/ )
{
	_socket.call(data, succ_callback, timeout_callback, timeout_limit);
}

void QuqiSocketClient::onConnected()
{
	llogln("QuqiSocketClient::onConnected: connect to quqi server: %d ip: %s, port: %d succ", _server_id,
		_socket.server_ip().c_str(), _socket.server_port());

	String time_str = StringUtil::toString(TimeUtil::now());
	NetData::Ptr data = NetData::create(0, PACK_TYPE__DISPATCH, PROC_TYPE__SERVER_VERIFY);
	data->setClientId(Setting::getInstance().server_id());
	data->writeString(time_str);
	data->writeString(CodecUtil::md5(time_str+UPDOWN_TO_QUQI_HOST_KEY));
	_socket.dispatch(data, true);
}

void QuqiSocketClient::onDisconnected(int_32 dr)
{
	llogln("QuqiSocketClient::onDisconnected: quqi server: %d ip: %s, port: %d disconnect reasion", _server_id,
		_socket.server_ip().c_str(), _socket.server_port(), dr);
}

void QuqiSocketClient::onConnecteFailed()
{
	llogln("QuqiSocketClient::onConnected: connect to quqi server: %d ip: %s, port: %d failed", _server_id,
		_socket.server_ip().c_str(), _socket.server_port());
}

void QuqiSocketClient::onNotifyConvertToPic( NetData::Ptr data )
{
	ConvertToPicInfo info;
	info.unpack(data);
	ConvertManager::getInstance().convert(info);
}