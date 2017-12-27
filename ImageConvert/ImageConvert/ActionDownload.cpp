#include "PreCompiled.h"
#include "ActionDownload.h"

#include "Utils.h"
#include "Const.h"
#include "QuqiCommunicationObject.h"
#include "QuqiIdMap.h"
#include "Setting.h"
#include "WatermarkUtil.h"
#include "MultiDownloadUtil.h"

#include "Utils/Utils.h"
#include "Sdk/Quqi/DocumentStorageManager.h"
#include "Sdk/Quqi/DownloadInfo.h"
#include "Utils/Lang/Lang.h"

USING_NS_QUQI_SDK;

AUTO_REGISTER("api/doc/download", Download, NO_PREV_ACTION);
ACTION_STEP_FUNC(Download, 0)
{
	Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 0) start", "No Path", "No Name");

	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 0) quqi_id INVALID_INPUT", "No Path", "No Name");

		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	
	if (get_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str);
	}
	else if (get_quqi_id_str_2.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str_2);
	}
	else if (cookie_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(cookie_quqi_id_str);
	}

	int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(quqi_id);
	if (server_id == -1)
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 0) server_id INVALID_INPUT", "No Path", "No Name");

		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const String &token = getData("t");

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_DOWNLOAD_TOKEN_INFO);
	data->writeString(token);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(Download, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) UNKNOWN_ERROR", "", "");
		outString("UNKNOWN_ERROR");
	}
	else
	{
		DownloadTokenInfo info;
		info.unpack(obj->data());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) STORAGE_NOT_FOUND", info.path, info.name);
			return outString("STORAGE_NOT_FOUND");
		}

		if (MultiDownloadUtil::outMultiDownload(this, storage, info))
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) MultiDownloadUtil::outMultiDownload", "Don't know Path", info.show_name);
			return;
		}

		// Begin writing headers
		header ( "Pragma: public" );
		header ( "Expires: 0" );
		header ( "Cache-Control: must-revalidate, post-check=0, pre-check=0" );
		//header ( "Cache-Control: public" );
		setCacheControlType(CCT__PUBLIC);
		header ( "Content-Description: File Transfer" );
		// Use the switch-generated Content-Type
		setContentType(CT__CUSTOM);
		header ( "Content-Type: application/force-download" );
		// Force the download
		header ( "Content-Transfer-Encoding: binary" );

		String cache_file_path = Setting::getInstance().cache_path() + "/" + info.path + "/" + info.name;
		if (info.pic_index > 0)
		{
			// 下载转换后的图片接口;
			String extent_name = "_"+StringUtil::toString(info.pic_index-1);
			if (info.doc_type == 0 && ServerLib::Utils::isMobileClient(this) && !info.download_thumbnail)
			{
				extent_name += "_m";
			}
			if (info.download_thumbnail)
			{
				extent_name += "_t";
				cache_file_path.append(extent_name);
				info.name.append(extent_name);
				info.show_name.append(extent_name+".png");
			}
			else
			{
				cache_file_path.append(extent_name);
				info.name.append(extent_name);
				info.show_name.append(extent_name+".jpg");
			}
		}

		header ( "Content-Disposition: attachment; filename=\"" + CodecUtil::urlEncode(StringUtil::toString(info.show_name)) + "\";" + 
			"filename*=utf-8\'\'" + CodecUtil::urlEncode(StringUtil::toString(info.show_name)));

		if (WatermastUtil::outWatermarkData(this, info, storage, cache_file_path))
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) WatermastUtil::outWatermarkData", info.path, info.name);
			return;
		}

		if (FileUtil::isFileExist(cache_file_path))
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) load from cache", info.path, info.name);
			outFile(cache_file_path);
			FILE *fp = fopen(cache_file_path.c_str(), "rb");
			fseek(fp, 0, SEEK_END);
			int_64 length = ftell(fp);
			header ( "Content-Length: "+ StringUtil::toString(length));
			fclose(fp);
		}
		else
		{
			DocumentStorageInfo dsi;
			dsi.path = info.path;
			dsi.name = info.name;
			dsi.size = info.size;

			String ret;
			if (info.is_encrypt) {
				ret = storage->loadContent(dsi, info.key);
			}
			else {
				ret = storage->loadRawContent(dsi);
			}
			Utils::saveStorageLog("ACTION_STEP_FUNC(Download, 1) load from Storage", info.path, info.name);

			Utils::saveContentCache(ret, info.path, info.name);
			header("Content-Length: " + StringUtil::toString(ret.length()));
			return outString(ret);
		}
	}
}

AUTO_REGISTER("api/doc/officedownload", OfficeDownload, NO_PREV_ACTION);
ACTION_STEP_FUNC(OfficeDownload, 0)
{
	Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 0) start", "No Path", "No Name");

	const String &token = getData("t");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");

	int_32 quqi_id = 0;
	if (get_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str);
	}
	else if (get_quqi_id_str_2.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str_2);
	}
	else if (cookie_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(cookie_quqi_id_str);
	}

	int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(quqi_id);
	if (server_id == -1)
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 0) server_id INVALID_INPUT", "No Path", "No Name");
		outString(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_DOWNLOAD_TOKEN_INFO);
	data->writeString(token);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(OfficeDownload, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	NetData::Ptr data = NetData::create(0);
	do 
	{
		if (obj->is_succ() == false || obj->data()->readInt32() == 0)
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 1) UNKNOWN_ERROR", "", "");

			data->writeInt32(0);
			break;
		}

		DownloadTokenInfo info;
		info.unpack(obj->data());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 1) STORAGE_NOT_FOUND", info.path, info.name);

			data->writeInt32(0);
			break;
		}

		DocumentStorageInfo dsi;
		dsi.path = info.path;
		dsi.name = info.name;
		dsi.size = info.size;

		data->writeInt32(1);
		data->writeString(info.path);
		data->writeString(info.name);
		data->writeString(info.show_name);

		String cache_file_path = Setting::getInstance().cache_path() + "/" + info.path + "/" + info.name;
		if (FileUtil::isFileExist(cache_file_path))
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 1) load from cache", info.path, info.name);

			String content;
			FileUtil::loadFile(content, cache_file_path);
			data->writeLongString(content);
		}
		else
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(OfficeDownload, 1) load from Storage", info.path, info.name);
			
			String content;
			if (info.is_encrypt) {
				content = storage->loadContent(dsi, info.key);
			}
			else
			{
				content = storage->loadRawContent(dsi);
			}

			Utils::saveContentCache(content, info.path, info.name);
			data->writeLongString(content);
		}
	} while (0);
	
	data->makeHead();
	outString(data->getBuffer(), data->getBufferSize());
}

AUTO_REGISTER("api/doc/previewpdf", PdfPreview, NO_PREV_ACTION);
ACTION_STEP_FUNC(PdfPreview, 0)
{
	Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 0) start", "No Path", "No Name");

	const String &token = getData("t");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");

	int_32 quqi_id = 0;
	if (get_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str);
	}
	else if (get_quqi_id_str_2.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str_2);
	}
	else if (cookie_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(cookie_quqi_id_str);
	}

	int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(quqi_id);
	if (server_id == -1)
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 0) server_id INVALID_INPUT", "No Path", "No Name");

		outString(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_DOWNLOAD_TOKEN_INFO);
	data->writeString(token);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(PdfPreview, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 1) UNKNOWN_ERROR", "", "");

		outString(Lang::get("UNKNOWN_ERROR"));
	}
	else
	{
		DownloadTokenInfo info;
		info.unpack(obj->data());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 1) STORAGE_NOT_FOUND", info.path, info.name);

			return outString(Lang::get("UNKNOWN_ERROR"));
		}

		// Begin writing headers
		header ( "Pragma: public" );
		header ( "Expires: 0" );
		header ( "Cache-Control: must-revalidate, post-check=0, pre-check=0" );
		setCacheControlType(CCT__PUBLIC);
		setContentType(CT__PDF);
		header ( "Content-Transfer-Encoding: binary" );

		String cache_file_path = Setting::getInstance().cache_path() + "/" + info.path + "/" + info.name;
		if (FileUtil::isFileExist(cache_file_path))
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 1) load from cache", info.path, info.name);

			outFile(cache_file_path);
			FILE *fp = fopen(cache_file_path.c_str(), "rb");
			fseek(fp, 0, SEEK_END);
			int_64 length = ftell(fp);
			header ( "Content-Length: "+ StringUtil::toString(length));
			fclose(fp);
		}
		else
		{
			Utils::saveStorageLog("ACTION_STEP_FUNC(PdfPreview, 1) load from Storage", info.path, info.name);

			DocumentStorageInfo dsi;
			dsi.path = info.path;
			dsi.name = info.name;
			dsi.size = info.size;

			String ret;
			if (info.is_encrypt) {
				ret = storage->loadContent(dsi, info.key);
			}
			else {
				ret = storage->loadRawContent(dsi);
			}
			Utils::saveContentCache(ret, info.path, info.name);
			header ( "Content-Length: "+ StringUtil::toString(ret.length()));
			return outString(ret);
		}
	}
}