#pragma once

namespace QuqiSDK
{
	struct OfficeUploadInfo;
};

class OfficeUtils
{
public:
	static bool saveContent(QuqiSDK::OfficeUploadInfo &info, int_32 storage_id, const String& content, uint_8 key[16], bool is_encrypt);

private:
	static String formatTimeForPath();
};