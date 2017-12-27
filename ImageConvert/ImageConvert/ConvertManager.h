#pragma once

#include "Sdk/Quqi/ConvertToPicInfo.h"

class ConvertManager
{
	SINGLETON_DECLARATION(ConvertManager);

public:
	ConvertManager();
	~ConvertManager();

	void convert(QuqiSDK::ConvertToPicInfo &convert_info);

	static int_32 s_max_convert_thread_cnt;			// 最大线程数量;

protected:
	void doConvert(QuqiSDK::ConvertToPicInfo &info);
	void onConvertComplete(QuqiSDK::ConvertToPicInfo &info);

	void unknownTypeToJpg(QuqiSDK::ConvertToPicInfo &info);
	void pdfToJpg(QuqiSDK::ConvertToPicInfo &info);
	void htmlToJpg(QuqiSDK::ConvertToPicInfo &info);
	void htmlToMobileJpg(QuqiSDK::ConvertToPicInfo &info);
	void psdToJpg(QuqiSDK::ConvertToPicInfo &info);

private:
	Mutex _info_mul_map_lock;
	QuqiSDK::ConvertToPicInfoMulMap _info_mul_map;

	ThreadPool _thread_pool;
};