#include "PreCompiled.h"
#include "MultiDownloadUtil.h"

#include "Setting.h"
#include "Utils.h"
#include "Common.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"

#include "Sdk/Quqi/DownloadInfo.h"
#include "Sdk/Quqi/DocumentStorageBase.h"
#include "Sdk/Quqi/DocumentStorageManager.h"

namespace fs = boost::filesystem;
USING_NS_QUQI_SDK;

void MultiDownloadUtil::timedManageCache() 
{
	ScheduleService::getInstance().addCycle(TimeUtil::now(), ONE_HOUR, boost::bind(&MultiDownloadUtil::_clearZipCachePath));
}	

//删除昨天的打包缓存文件
void MultiDownloadUtil::_clearZipCachePath() 
{
	Int now = TimeUtil::now();

	const String &zip_cache_path = Setting::getInstance().multi_download_cache_path();

	for (fs::directory_iterator iter(zip_cache_path), end_iter; iter != end_iter; ++iter)
	{
		FileInfo file_info;
		const String &full_file_name = iter->path().string();
		if(!FileUtil::getFileInfo(file_info, full_file_name)) {
			lerrorln("MultiDownloadUtil::getZipCachePath fail in %s", full_file_name.c_str());
		}

		if(now - file_info.last_access_time > ONE_DAY) {
			if(!FileUtil::remove(full_file_name)) {
				lerrorln("MultiDownloadUtil::clearZipCachePath fail in %s", full_file_name.c_str());
			} else {
				llogln("MultiDownloadUtils::clearZipCachePath succ in %s", full_file_name.c_str());
			}
		}
	}
}

bool MultiDownloadUtil::outMultiDownload( ActionBase *action, DocumentStorageBase *storage, QuqiSDK::DownloadTokenInfo &info )
{
	if (info.multi_download_info.use == false)
	{
		return false;
	}

	const String &show_name = info.show_name+".zip";
	Time time;
	TimeUtil::now(time);
	const String &zip_cache_path = Setting::getInstance().multi_download_cache_path();
	if (FileUtil::isFileExist(zip_cache_path) == false)
	{
		FileUtil::mkdir(zip_cache_path);
	}

	Zipper zipper(zip_cache_path+"/"+MathUtil::randomString(20)+".zip", Zipper::OVER_WRITE);

	FOR_EACH_EX(info.multi_download_info.items, iter)
	{
		MultiDownloadInfoItem &item = *iter;

		String cache_file_path = Setting::getInstance().cache_path() + "/" + item.path + "/" + item.name;

		if (FileUtil::isFileExist(cache_file_path) == false)
		{
			DocumentStorageInfo dsi;
			dsi.path = item.path;
			dsi.name = item.name;
			dsi.size = info.size;

			if (item.is_encrypt) {
				Utils::saveContentCache(storage->loadContent(dsi, info.key), item.path, item.name);
			}
			else {
				Utils::saveContentCache(storage->loadRawContent(dsi), item.path, item.name);
			}
		}
		
		if(item.name == QUQI_EMPTY_FILE) {
			zipper.addFile(ZipperFile("", CodecUtil::utf8ToGbk(item.show_name)));
		} else {
			zipper.addFile(ZipperFile(cache_file_path, CodecUtil::utf8ToGbk(item.show_name)));
		}
	}

	if (false == zipper.write())
	{
		action->outString("ZIP_CREATE_FAILED");
		return true;
	}

	FileInfo file_info;
	if (false == FileUtil::getFileInfo(file_info, zipper.file_name()))
	{
		action->outString("ZIP_CREATE_FAILED");
		return true;
	}

	// Begin writing headers
	action->header ( "Pragma: public" );
	action->header ( "Expires: 0" );
	action->header ( "Cache-Control: must-revalidate, post-check=0, pre-check=0" );
	//header ( "Cache-Control: public" );
	action->setCacheControlType(CCT__PUBLIC);
	action->header ( "Content-Description: File Transfer" );
	// Use the switch-generated Content-Type
	action->setContentType(CT__CUSTOM);
	action->header ( "Content-Type: application/force-download" );
	// Force the download
	action->header ( "Content-Transfer-Encoding: binary" );
	action->header ( "Content-Disposition: attachment; filename=\"" + show_name+ "\";" );
	action->header ( "Content-Length: "+ StringUtil::toString(file_info.file_size));

	action->outFile(zipper.file_name());
	return true;
}