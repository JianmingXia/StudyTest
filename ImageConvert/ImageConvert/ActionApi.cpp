#include "PreCompiled.h"

#include "Setting.h"
#include "Magick++.h"
#include "QuqiIdMap.h"
#include "QuqiCommunicationObject.h"
#include "Utils.h"

#include "Const.h"
#include "Utils/Utils.h"
#include "Sdk/Quqi/DownloadInfo.h"
#include "Sdk/Quqi/DocumentStorageBase.h"
#include "Sdk/Quqi/DocumentStorageManager.h"
#include "Utils/Lang/Lang.h"

USING_NS_QUQI_SDK;
using namespace Magick;

ACTION_CLASS(InnerResizePicture, 0);
AUTO_REGISTER("updown_for_intrant/picture/resize", InnerResizePicture, NO_PREV_ACTION);
ACTION_STEP_FUNC(InnerResizePicture, 0)
{
	const String &file_name = getData("file_name");
	const String &size_str = getData("size");
	const String &quality_str = getData("quality");
	const String &expire_str = getData("expire_time");
	const String &pic_type = getData("pic_type");

	JsonValue ret;
	ret["err"] = 0;
	ret["msg"] = "ok";
	try
	{
		Image image;
		image.read(Blob(getPostString().c_str(), getPostString().size()));

		if (!size_str.empty())
		{
			Int32Vector iv;
			StringUtil::splitInt32(iv, size_str, "x");
			if (iv.size() < 2)
			{
				iv.push_back(iv[0]);
			}

			if (iv[0] == 0 || iv[1] == 0)
			{
				outString("INVALID INPUT");
				return;
			}

			image.resize(Geometry(iv[0], iv[1]));
		}

		if (!quality_str.empty())
		{
			int_32 quality = StringUtil::parseInt32(quality_str);
			if (quality == 0)
			{
				outString("INVALID INPUT");
				return;
			}

			image.quality(quality);
		}
		else
		{
			image.quality(80);
		}

		String ext;
		if (pic_type.empty() || pic_type == "jpeg")
		{
			ext = "JPEG";
		}
		else if (pic_type == "PNG")
		{
			ext = "PNG";
		}

		Blob blob;
		image.write(&blob, ext);
		const String &md5_str = CodecUtil::md5((int_8*)blob.data(), blob.length());

		DocumentStorageBase *storage = DocumentStorageManager::getInstance().getStorage(Setting::getInstance().operator_storage_id());
		DocumentStorageInfo info;
		info.size = blob.length();
		if (expire_str == "0")
		{
			if (file_name.empty())
			{
				info.path = "perpetual";
				info.name = md5_str+"."+ext;
			}
			else
			{
				info.path = "perpetual/"+md5_str;
				info.name = file_name;
			}
		}
		else
		{
			int_32 expire = StringUtil::parseInt32(expire_str);
			if (expire == 0)
			{
				expire = TimeUtil::now();
			}
			Time time;
			TimeUtil::makeTime(expire, time);
			info.path = "expire/"+StringUtil::format("%d/%02d/%02d", time.year, time.month, time.day);

			if (file_name.empty())
			{
				info.name = md5_str+"."+ext;
			}
			else
			{
				info.path.append("/").append(md5_str);
				info.name = file_name;
			}
		}
		
		storage->saveRawContent(info, String((char*)blob.data(), blob.length()));

		ret["path"] = Setting::getInstance().operator_host()+"/"+info.path+"/"+info.name;
	}
	catch (std::exception &e)
	{
		ret["err"] = 1;
		ret["msg"] = e.what();
		llogln("ResizePicture: resize failed error: %s", e.what());
	}

	outString(JsonUtil::ValueToString(ret));
}


ACTION_CLASS(ResizePicture, 0, 1);
AUTO_REGISTER("api/picture/resize", ResizePicture, NO_PREV_ACTION);
ACTION_STEP_FUNC(ResizePicture, 0)
{
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		outString(ServerLib::Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	if (cookie_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(cookie_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str);
	}
	else if (get_quqi_id_str_2.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(get_quqi_id_str_2);
	}

	int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(quqi_id);
	if (server_id == -1)
	{
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

ACTION_STEP_FUNC(ResizePicture, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
	}
	else
	{
		DownloadTokenInfo info;
		info.unpack(obj->data());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			outString(Utils::errorAPIResponse("UPDOWN_UNKNOWN_ERROR"));
		}

		const String &file_name = getData("file_name");
		const String &size_str = getData("size");
		const String &quality_str = getData("quality");
		const String &expire_str = getData("expire_time");
		const String &pic_type = getData("pic_type");

		JsonValue ret;
		ret["err"] = 0;
		ret["msg"] = "ok";
		try
		{
			String cache_file_path = Setting::getInstance().cache_path() + "/" + info.path + "/" + info.name;
			if (info.pic_index > 0)
			{
				// 下载转换后的图片接口;
				String extent_name = "_"+StringUtil::toString(info.pic_index-1);
				/*ServerLib::ClientType client_type = ServerLib::Utils::getClientType(this);
				if (client_type == ServerLib::ClientType::WECHAT_APP_CLIENT || client_type == ServerLib::ClientType::QUQI_APP_CLIENT)
				{
					extent_name += "_m";
				}*/
				cache_file_path.append(extent_name);
				info.name.append(extent_name);
				info.show_name.append(extent_name+".jpg");
			}

			String content;
			if (FileUtil::isFileExist(cache_file_path))
			{
				FileUtil::loadFile(content, cache_file_path);
			}
			else
			{
				DocumentStorageInfo dsi;
				dsi.path = info.path;
				dsi.name = info.name;
				dsi.size = info.size;

				if (info.is_encrypt)
				{
					content = storage->loadContent(dsi, info.key);
				}
				else
				{
					content = storage->loadRawContent(dsi);
				}
				Utils::saveContentCache(content, info.path, info.name);
			}

			Image image;
			image.read(Blob(content.c_str(), content.size()));

			if (!size_str.empty())
			{
				Int32Vector iv;
				StringUtil::splitInt32(iv, size_str, "x");
				if (iv.size() < 2)
				{
					iv.push_back(iv[0]);
				}

				if (iv[0] == 0 || iv[1] == 0)
				{
					outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
					return;
				}

				image.resize(Geometry(iv[0], iv[1]));
			}

			if (!quality_str.empty())
			{
				int_32 quality = StringUtil::parseInt32(quality_str);
				if (quality == 0)
				{
					outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
					return;
				}

				image.quality(quality);
			}
			else
			{
				image.quality(80);
			}

			String ext;
			if (pic_type.empty() || pic_type == "jpeg")
			{
				ext = "JPEG";
			}
			else if (pic_type == "PNG")
			{
				ext = "PNG";
			}

			Blob blob;
			image.write(&blob, ext);
			const String &md5_str = CodecUtil::md5((int_8*)blob.data(), blob.length());

			DocumentStorageBase *storage = DocumentStorageManager::getInstance().getStorage(Setting::getInstance().operator_storage_id());
			DocumentStorageInfo info;
			info.size = blob.length();
			if (expire_str == "0")
			{
				if (file_name.empty())
				{
					info.path = "perpetual";
					info.name = md5_str+"."+ext;
				}
				else
				{
					info.path = "perpetual/"+md5_str;
					info.name = file_name;
				}
			}
			else
			{
				int_32 expire = StringUtil::parseInt32(expire_str);
				if (expire == 0)
				{
					expire = TimeUtil::now();
				}
				Time time;
				TimeUtil::makeTime(expire, time);
				info.path = "expire/"+StringUtil::format("%d/%02d/%02d", time.year, time.month, time.day);

				if (file_name.empty())
				{
					info.name = md5_str+"."+ext;
				}
				else
				{
					info.path.append("/").append(md5_str);
					info.name = file_name;
				}
			}

			storage->saveRawContent(info, String((char*)blob.data(), blob.length()));

			ret["path"] = Setting::getInstance().operator_host()+"/"+info.path+"/"+info.name;
		}
		catch (std::exception &e)
		{
			ret["err"] = 1;
			ret["msg"] = e.what();
			llogln("ResizePicture: resize failed error: %s", e.what());
		}

		outString(JsonUtil::ValueToString(ret));
	}
}

ACTION_CLASS(InnerUpload, 0);
AUTO_REGISTER("updown_for_intrant/upload", InnerUpload, NO_PREV_ACTION);
ACTION_STEP_FUNC(InnerUpload, 0)
{
	const String &expire_str = getData("expire_time");
	const String &file_name = getData("file_name");

	JsonValue ret;
	ret["err"] = 0;
	ret["msg"] = "ok";
	try
	{
		const String &data = getPostString();
		const String &md5_str = CodecUtil::md5(data);
		DocumentStorageBase *storage = DocumentStorageManager::getInstance().getStorage(Setting::getInstance().operator_storage_id());
		DocumentStorageInfo info;
		if (expire_str == "0")
		{
			if (file_name.empty())
			{
				info.path = "perpetual";
				info.name = md5_str;
			}
			else
			{
				info.path = "perpetual/"+md5_str;
				info.name = file_name;
			}
		}
		else
		{
			int_32 expire = StringUtil::parseInt32(expire_str);
			if (expire == 0)
			{
				expire = TimeUtil::now();
			}
			Time time;
			TimeUtil::makeTime(expire, time);
			info.path = "expire/"+StringUtil::format("%d/%02d/%02d", time.year, time.month, time.day);
			if (file_name.empty())
			{
				info.name = md5_str;
			}
			else
			{
				info.path.append("/").append(md5_str);
				info.name = file_name;
			}
		}

		storage->saveRawContent(info, data);

		ret["path"] = Setting::getInstance().operator_host()+"/"+info.path+"/"+info.name;
	}
	catch (std::exception &e)
	{
		ret["err"] = 1;
		ret["msg"] = e.what();
		llogln("InnerUpload: upload failed error: %s", e.what());
	}

	outString(JsonUtil::ValueToString(ret));
}