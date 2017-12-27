#pragma once

class UpdownSession : public NodeSession
{
public:
	UpdownSession();
	virtual ~UpdownSession();

	virtual void onDelete();
	virtual void checkHost(NetData::Ptr in_data);
};