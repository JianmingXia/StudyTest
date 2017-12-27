#include "PreCompiled.h"
#include "QuqiCommunicationObject.h"

#include "QuqiSocketClientManager.h"

QuqiCommunicationObject::QuqiCommunicationObject( ActionRunner runner )
{
	_runner = runner;
	_is_succ = false;
}

QuqiCommunicationObject::~QuqiCommunicationObject()
{

}


void QuqiCommunicationObject::communicate( int_32 server_id, NetData::Ptr data )
{
	QuqiSocketClientManager::getInstance().call(server_id, data, boost::bind(&QuqiCommunicationObject::onSucc, this, _1),
		boost::bind(&QuqiCommunicationObject::onTimeout, this, _1));
}


void QuqiCommunicationObject::dispatch( int_32 server_id, NetData::Ptr data )
{
	QuqiSocketClientManager::getInstance().dispatch(server_id, data);
}

void QuqiCommunicationObject::onSucc( NetData::Ptr data )
{
	_is_succ = true;
	_data = data;
	_runner.run();
}

void QuqiCommunicationObject::onTimeout( NetData::Ptr data )
{
	_is_succ = false;
	_runner.run();
}
