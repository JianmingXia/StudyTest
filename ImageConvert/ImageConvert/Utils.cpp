#include "PreCompiled.h"
#include "Utils.h"
#include "Sdk/Auth/QuqiAuthSdk.h"

#include "Setting.h"

String Utils::errorAPIResponse( const String& msg, Int error_code/*=1*/ )
{
	JsonValue ret;
	return handleAPIResponse(1, msg, ret);
}

String Utils::handleAPIResponse( int err, const String& msg,JsonValue& ret )
{
	//输出响应;
	ret["err"] = err;
	ret["msg"] = msg;
#ifdef WIN32
	return JsonUtil::ValueToString(ret, true);
#endif
#ifdef LINUX
	return JsonUtil::ValueToString(ret, false);
#endif
}

String Utils::succAPIResponse( const String& msg, JsonValue& data )
{
	return handleAPIResponse(0, msg, data);
}