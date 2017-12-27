#pragma once

class QuqiCommunicationObject
{
public:
	typedef boost::shared_ptr<QuqiCommunicationObject> Ptr;

public:
	QuqiCommunicationObject(ActionRunner runner);
	~QuqiCommunicationObject();

	void communicate(int_32 server_id, NetData::Ptr data);
	void dispatch(int_32 server_id, NetData::Ptr data);

protected:
	void onSucc(NetData::Ptr data);
	void onTimeout(NetData::Ptr data);

	DEFINE_PROPERTY_REF(NetData::Ptr, data);
	DEFINE_PROPERTY_READONLY(bool, is_succ);

private:
	ActionRunner _runner;
};