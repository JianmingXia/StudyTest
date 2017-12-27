#pragma once

class Utils
{
public:
	static String errorAPIResponse(const String& msg, Int error_code = 1);
	static String handleAPIResponse(int err, const String& msg, JsonValue& ret);
	static String succAPIResponse(const String& msg, JsonValue& data);
};