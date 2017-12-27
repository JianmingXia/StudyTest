#pragma once

class WechatAccessTokenManager
{
	SINGLETON_DECLARATION(WechatAccessTokenManager)
	DEFINE_PROPERTY(Int, expire_time);
	String _access_token;
	
	RwLock _lock;
public:
	WechatAccessTokenManager(void);
	~WechatAccessTokenManager(void);

	bool getAccessToken(String& access_token);

	bool refreshAccessToken(String& access_token);
};

