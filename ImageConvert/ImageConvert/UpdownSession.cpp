#include "PreCompiled.h"
#include "UpdownSession.h"

#include "Sdk/Monitor/MonitorClientHost.h"

UpdownSession::UpdownSession()
{

}

UpdownSession::~UpdownSession()
{

}

void UpdownSession::onDelete()
{
	NodeSession::onDelete();

	AutoLock lock(_host_lock);
	if (_host)
	{
		if (dynamic_cast<MonitorSDK::MonitorClientHost*>(_host))
		{
			_host->onDelete();
			delete _host;
			_host = NULL;
		}
	}
}

void UpdownSession::checkHost( NetData::Ptr in_data )
{
	NodeSession::checkHost(in_data);

	AutoLock lock(_host_lock);
	if (_host != NULL || in_data->getProcType() != PROC_TYPE__SERVER_VERIFY) return;

	if (MonitorSDK::MonitorClientHost::verify(in_data))
	{
		_host = new MonitorSDK::MonitorClientHost();
	}

	if (_host)
	{
		_host->session(this);
		_host->onCreate();
	}
}