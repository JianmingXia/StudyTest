#pragma once

#include "Sdk/Quqi/DownloadInfo.h"
#include "Sdk/Quqi/DocumentStorageBase.h"

class WatermastUtil
{
public:
	static bool outWatermarkData(ActionBase* action, QuqiSDK::DownloadTokenInfo &info, QuqiSDK::DocumentStorageBase *storage, const String &cache_file_path);
};