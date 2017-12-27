#include "PreCompiled.h"
#include "WechatAccessTokenManager.h"
#include "Sdk/Auth/QuqiAuthSdk.h"

SINGLETON_DEFINITION(WechatAccessTokenManager);
WechatAccessTokenManager::WechatAccessTokenManager(void)
{
	_expire_time = 0;
	_access_token = "";
}


WechatAccessTokenManager::~WechatAccessTokenManager(void)
{
}

bool WechatAccessTokenManager::getAccessToken(String& access_token)
{
	AutoWrLock lock(_lock);
	if(_access_token.empty() || _expire_time <= TimeUtil::now())
	{
		JsonValue ret_json;
		if (false == QuqiAuthSdk::requestData("auth_for_intrant/wechatPublicAccessToken", ret_json))
		{
			lerrorln("getAccessToken: get accesstoken failed");
			return false;
		}

		Int status = JsonUtil::ValueToInt32(ret_json["status"]);
		if(status)
		{
			lerrorln("getAccessToken: get accesstoken failed, %s", JsonUtil::ValueToString(ret_json["msg"]).c_str());
			return false;
		}

		access_token = _access_token = JsonUtil::ValueToString(ret_json["access_token"]);
		_expire_time = JsonUtil::ValueToInt32(ret_json["expire_time"]);
		return true;
	}
	else
	{
		access_token = _access_token;
		return true;
	}
}

bool WechatAccessTokenManager::refreshAccessToken(String& access_token)
{
	AutoWrLock lock(_lock);

	JsonValue ret_json;
	if (false == QuqiAuthSdk::requestData("auth_for_intrant/refreshWechatPublicAccessToken", ret_json))
	{
		lerrorln("refreshAccessToken: refresh accesstoken failed");
		return false;
	}
	Int status = JsonUtil::ValueToInt32(ret_json["status"]);
	if(status)
	{
		lerrorln("refreshAccessToken: refresh accesstoken failed, %s", JsonUtil::ValueToString(ret_json["msg"]).c_str());
		return false;
	}

	access_token = _access_token = JsonUtil::ValueToString(ret_json["access_token"]);
	_expire_time = JsonUtil::ValueToInt32(ret_json["expire_time"]);
	return true;
}
