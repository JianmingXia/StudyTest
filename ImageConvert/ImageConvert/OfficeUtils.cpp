#include "PreCompiled.h"
#include "OfficeUtils.h"

#include "Sdk/Quqi/UploadInfo.h"
#include "Sdk/Quqi/DocumentStorageBase.h"
#include "Sdk/Quqi/DocumentStorageManager.h"

USING_NS_QUQI_SDK;

bool OfficeUtils::saveContent( QuqiSDK::OfficeUploadInfo &info, int_32 storage_id, const String& content, uint_8 key[16], bool is_encrypt )
{
	info.content_md5 = CodecUtil::md5(content);
	info.content_size = content.size();
	info.storage_path = formatTimeForPath();
	info.storage_name = StringUtil::toString(info.quqi_id) +"_"+ StringUtil::toString(info.tree_id) +"_"+ 
		StringUtil::toString(info.node_id) +"_"+ StringUtil::toString(info.version) + "_" + 
		StringUtil::toString(info.type) + "_" + info.content_md5;

	DocumentStorageInfo dsi;
	dsi.path = info.storage_path;
	dsi.name = info.storage_name;

	DocumentStorageBase *storage = DocumentStorageManager::getInstance().getStorage(storage_id);
	if (storage == NULL)
	{
		return false;
	}
	if (is_encrypt)
	{
		storage->saveContent(dsi, content, key);
	}
	else
	{
		storage->saveRawContent(dsi, content);
	}
	return true;
}

String OfficeUtils::formatTimeForPath()
{
	std::time_t t= std::time(NULL);
	char mbstr[100];
	if(std::strftime(mbstr,sizeof(mbstr),"%y/%m/%d",std::localtime(&t))){
		return StringUtil::toString(mbstr);
	}
	return "";
}
