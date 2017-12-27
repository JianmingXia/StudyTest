/********************************************************************
	Created:	2017-7-6 11:18
	Author:		Drecik Xu;
	Description:
				多文件下载;
*********************************************************************/

#pragma once

#include "Sdk/Quqi/DownloadInfo.h"
#include "Sdk/Quqi/DocumentStorageBase.h"

 class MultiDownloadUtil
 {
 public:
	 static bool outMultiDownload(ActionBase *action, QuqiSDK::DocumentStorageBase *storage, QuqiSDK::DownloadTokenInfo &info);
	 static void timedManageCache();
	 static void _clearZipCachePath();
 };