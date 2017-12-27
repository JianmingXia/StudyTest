#include "PreCompiled.h"
#include "ActionUpload.h"

#include "Const.h"
#include "Sdk/Quqi/ConvertToPicInfo.h"
#include "Sdk/Quqi/UploadInfo.h"
#include "Sdk/Quqi/DocumentStorageManager.h"
#include "Utils/Utils.h"

#include "Utils.h"
#include "QuqiIdMap.h"
#include "QuqiCommunicationObject.h"
#include "OfficeUtils.h"
#include "Setting.h"
#include "StorageUploadManager.h"
#include "ConvertManager.h"
#include "Utils/Lang/Lang.h"

USING_NS_QUQI_SDK;

static bool uploadFile(ActionBase *action, UploadTokenQS2USInfo &info, UploadTokenUS2QSInfo &trans_info)
{
	String file_name;
	String file_path;
	String file_md5;
	uint_64 file_size;
	{
		const PostInfo *post_info = action->getPostInfo("file_name");
		if (post_info == NULL)
		{
			action->outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
			action->setNextActionStep(ACTION_COMPLETE);
			return false;
		}
		file_name = post_info->content();

		post_info = action->getPostInfo("file_path");
		if (post_info == NULL)
		{
			action->outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
			action->setNextActionStep(ACTION_COMPLETE);
			return false;
		}
		file_path = post_info->content();

		post_info = action->getPostInfo("file_md5");
		if (post_info == NULL)
		{
			action->outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
			action->setNextActionStep(ACTION_COMPLETE);
			return false;
		}
		file_md5 = post_info->content();

		post_info = action->getPostInfo("file_size");
		if (post_info == NULL)
		{
			action->outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
			action->setNextActionStep(ACTION_COMPLETE);
			return false;
		}
		file_size = StringUtil::parseInt64(post_info->content());
	}

	String path = Setting::getInstance().cache_path()+"/"+info.storage_path;
	if (FileUtil::isFileExist(path) == false)
	{
		FileUtil::mkdir(path);
	}

	StorageUploadInfo storage_upload_info;
	storage_upload_info.storage_info.path = info.storage_path;
	storage_upload_info.storage_info.name = StringUtil::toString(info.quqi_id) + "_" +
		StringUtil::toString(info.tree_id) + "_" + StringUtil::toString(info.node_id) + "_" + StringUtil::toString(info.version) + "_" + file_md5;
	storage_upload_info.storage_info.size = file_size;
	storage_upload_info.storage_id = info.storage_id;
	storage_upload_info.file_path = path+"/"+storage_upload_info.storage_info.name;
	memcpy(storage_upload_info.key, info.key, sizeof(info.key));
	storage_upload_info.is_encrypt = info.is_encrypt;

	if (false == FileUtil::moveFile(file_path, storage_upload_info.file_path) && FileUtil::isFileExist(storage_upload_info.file_path) == false)
	{
		action->outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		action->setNextActionStep(ACTION_COMPLETE);
		return false;
	}

	StorageUploadManager::getInstance().addUpload(storage_upload_info);
	trans_info.token = action->getData("t");
	trans_info.node_id = info.node_id;
	trans_info.file_name = file_name;
	trans_info.storage_name = storage_upload_info.storage_info.name;
	trans_info.content_md5 = file_md5;
	trans_info.content_size = file_size;
	trans_info.ip = action->getServer("REMOTE_ADDR");

	return true;
}

//////////////////////////////////////////////////////////////////////////
// Upload
AUTO_REGISTER("api/doc/upload_backend", Upload, NO_PREV_ACTION);
ACTION_STEP_FUNC(Upload, 0)
{
	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (header_quqi_id_str.empty() && cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const String &token = getData("t");

	saveInt32("server_id", server_id);

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_TOKEN_INFO);
	data->writeString(token);

	const PostInfo *post_info = getPostInfo("file_size");
	if (post_info == NULL)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}
	data->writeInt64(StringUtil::parseInt64(post_info->content()));

	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(Upload, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}
	
	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	UploadTokenUS2QSInfo trans_info;
	if (false == uploadFile(this, info, trans_info))
	{
		return;
	}

	// 通知quqi上传成功;
	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(Upload, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	JsonValue data;
	JsonValue &ret = data["data"];
	ret["quqi_id"] = obj->data()->readInt32();
	ret["tree_id"] = obj->data()->readInt32();
	ret["node_id"] = obj->data()->readInt32();
	ret["parent_id"] = obj->data()->readInt32();
	ret["node_name"] = obj->data()->readString();
	outString(Utils::succAPIResponse("ok", data));
}


//////////////////////////////////////////////////////////////////////////
// UploadDirFiles
AUTO_REGISTER("api/doc/uploadDir_backend", UploadDirFiles, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadDirFiles, 0)
{
	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (header_quqi_id_str.empty() && cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	const PostInfo *post_info = getPostInfo("file_size");
	if (post_info == NULL)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}	
	const PostInfo *post_info_path = getPostInfo("path");
	if (post_info_path == NULL)
	{
		outString(Utils::errorAPIResponse("UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	UploadTokenUS2QSInfo trans_info;
	trans_info.token = getData("t");
	trans_info.file_name = post_info_path->content();
	trans_info.content_size = StringUtil::parseInt64(post_info->content());

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_DIR_TOKEN_INFO);
	trans_info.pack(data);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadDirFiles, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	const PostInfo *post_info = getPostInfo("path");
	if (post_info == NULL)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return ;
	}

	UploadTokenUS2QSInfo trans_info;
	if (false == uploadFile(this, info, trans_info))
	{
		return;
	}

	trans_info.file_name = post_info->content();

	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_DIR_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadDirFiles, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	JsonValue data;
	JsonValue &ret = data["data"];
	ret["quqi_id"] = obj->data()->readInt32();
	ret["tree_id"] = obj->data()->readInt32();
	ret["node_id"] = obj->data()->readInt32();
	ret["parent_id"] = obj->data()->readInt32();
	ret["node_name"] = obj->data()->readString();
	outString(Utils::succAPIResponse("ok", data));
}


//////////////////////////////////////////////////////////////////////////
// UploadOffice
AUTO_REGISTER("api/doc/officeupload", UploadOffice, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadOffice, 0)
{
	int_32 quqi_id = StringUtil::parseInt32(getData("quqi_id"));
	int_32 tree_id = StringUtil::parseInt32(getData("tree_id"));
	int_32 node_id = StringUtil::parseInt32(getData("node_id"));
	int_32 version = StringUtil::parseInt32(getData("version"));

	int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(quqi_id);
	if (server_id == -1)
	{
		Utils::errorAPIResponse(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);
	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_OFFICE_DOC_INFO);
	data->writeInt32(quqi_id);
	data->writeInt32(tree_id);
	data->writeInt32(node_id);
	data->writeInt32(version);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadOffice, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 storage_id = obj->data()->readInt32();
	bool is_encrypt = obj->data()->readBool();
	uint_8 key[16];
	memcpy(key, obj->data()->popData(NULL, sizeof(key)), sizeof(key));

	OfficeUploadInfo info;
	info.quqi_id = StringUtil::parseInt32(getData("quqi_id"));
	info.tree_id = StringUtil::parseInt32(getData("tree_id"));
	info.node_id = StringUtil::parseInt32(getData("node_id"));
	info.version = StringUtil::parseInt32(getData("version"));
	info.type	= StringUtil::parseInt32(getData("type"));
	info.status	= StringUtil::parseInt32(getData("status"));
	info.passport_ids = getData("passport_ids");
	info.client_id = StringUtil::toString(getData("client_id"));
	info.extension = StringUtil::toString(getData("extension"));
	info.path = StringUtil::toString(getData("path"));
	info.updown_host = Utils::getUpdownHost(this);

	int_32 server_id = loadInt32("server_id");

	do 
	{
		if (info.status != OfficeConvertStatus::CONVERT_SUCCESS_STATUS)
		{
			break;
		}

		int_32 content_length = StringUtil::parseInt32(getServer("CONTENT_LENGTH"));
		const String &raw_content = getPostString();
		String content;
		if (content_length > 0 && static_cast<int_32>(raw_content.length()) > content_length)
		{
			content = raw_content.substr(0,content_length);
		}
		else
		{
			content = raw_content;
		}

		switch (info.type)
		{
		case WORD_TO_PDF:
		case PPT_TO_PDF:
		case HTML_TO_PDF:
		case XLS_TO_XLSX:
		case HTML_TO_DOCX:
		case XLSX_TO_SHEET:
		case SHEET_TO_XLSX:
			OfficeUtils::saveContent(info, storage_id, content, key, is_encrypt);
			break;

		case WORD_TO_HTML:
			{
				// TODO: 暂时直接发送到曲奇进行转换;
				String url = Setting::getInstance().quqi_host()+"/api/doc/officeupload";
				url += "?quqi_id=" + StringUtil::toString(info.quqi_id);
				url += "&tree_id=" + StringUtil::toString(info.tree_id);
				url += "&node_id=" + StringUtil::toString(info.node_id);
				url += "&version=" + StringUtil::toString(info.version);
				url += "&type=" + StringUtil::toString(info.type);
				url += "&passport_ids=" + StringUtil::toString(info.passport_ids);
				url += "&client_id=" + info.client_id;
				url += "&quqiid=" + StringUtil::toString(info.quqi_id);
				url += "&status=" + info.status;
				url += "&path="+info.path;
				url += "&extension="+info.extension;
				String result;
				HttpService::getInstance().post(url, content, result);
				setNextActionStep(ACTION_COMPLETE);
				return;
			} break;
		}
	} while (0);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_OFFICE);
	info.pack(data);
	obj->dispatch(server_id, data);
}

//////////////////////////////////////////////////////////////////////////
// UploadInDoc
AUTO_REGISTER("api/doc/uploadindoc", UploadInDoc, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadInDoc, 0)
{
	const String &id = getData("id");
	String share_code = getData("share_code");
	saveString("share_code", share_code);
	saveString("client_type", getData("client_type"));

	const String &passport_id = getCookie("passport_id");
	const String &session = getCookie("session_key");

	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (header_quqi_id_str.empty() && cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	Int32Vector iv;
	int_32 tree_id, parent_id;
	StringUtil::splitInt32(iv, id, "_");
	if (iv.size() > 0) quqi_id = iv[0];
	if (iv.size() > 1) tree_id = iv[1];
	if (iv.size() > 2) parent_id = iv[2];
	saveInt32("quqi_id", quqi_id);
	saveInt32("tree_id", tree_id);
	saveInt32("parent_id", parent_id);

	const PostInfo *upfile = getPostInfo("upfile");
	if (upfile == NULL)
	{
		Utils::errorAPIResponse(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	Int content_length = upfile->content().length();

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);
	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_IN_DOC_INFO);
	data->writeString(share_code);
	data->writeInt32(quqi_id);
	data->writeInt32(tree_id);
	data->writeInt32(parent_id);
	data->writeInt32(StringUtil::parseInt32(passport_id));
	data->writeString(session);
	data->writeInt32(ServerLib::Utils::getClientType(this));
	data->writeInt32(content_length);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadInDoc, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	String token = obj->data()->readString();
	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
	if (!storage)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const PostInfo *upfile = getPostInfo("upfile");

	DocumentStorageInfo dsi;
	const String &md5 = CodecUtil::md5(upfile->content());
	dsi.path = info.storage_path;
	dsi.name = StringUtil::toString(info.quqi_id) + "_" + StringUtil::toString(info.tree_id) +
		"_" + StringUtil::toString(info.node_id) + "_" + StringUtil::toString(info.version) + "_" + md5;
	bool save_result;
	if (info.is_encrypt)
	{
		save_result = storage->saveContent(dsi, upfile->content(), info.key);
	}
	else
	{
		save_result = storage->saveRawContent(dsi, upfile->content());
	}
	if (false == save_result)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	// 通知quqi上传成功;
	UploadTokenUS2QSInfo trans_info;
	trans_info.token = token;
	trans_info.node_id = info.node_id;
	trans_info.file_name = upfile->file_name();
	trans_info.storage_name = dsi.name;
	trans_info.content_md5 = md5;
	trans_info.content_size = upfile->content().length();

	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);
	saveInt32("node_id", info.node_id);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_IN_DOC_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadInDoc, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const PostInfo *upfile = getPostInfo("upfile");
	JsonValue ret;
	ret["original"] = upfile->file_name();
	ret["size"] = (int_32)upfile->content().length();
	ret["state"] = "SUCCESS";
	ret["title"] = "in_doc_file";
	ret["type"] = "png";

	String share_code = loadString("share_code");
	String client_type = loadString("client_type");
	String url = share_code.size() > 0 ? "/api/share/doc/getDownload" : "/api/doc/getDownload";
	if (share_code.size() > 0) {
		url += "?share_code=" + share_code + "&";
	}
	else if (client_type.size() > 0) {
		url += "?client_type=" + client_type + "&";
	}
	else {
		url += "?";
	}

	url += "id=" + StringUtil::toString(loadInt32("quqi_id")) + "_" +
		StringUtil::toString(loadInt32("tree_id"))+"_"+StringUtil::toString(loadInt32("node_id"));


	ret["url"] = url;
	outString(JsonUtil::ValueToString(ret));
}



//////////////////////////////////////////////////////////////////////////
// UploadOffice
AUTO_REGISTER("api/doc/uploadinsheet", UploadInSheet, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadInSheet, 0)
{
	int_32 tree_id = StringUtil::parseInt32(getData("tree_id"));
	int_32 parent_id = StringUtil::parseInt32(getData("node_id"));
	String share_code = getData("share_code");
	saveString("share_code", share_code);
	saveString("client_type", getData("client_type"));

	const String &passport_id = getCookie("passport_id");
	const String &session = getCookie("session_key");

	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");
	if (header_quqi_id_str.empty() && cookie_quqi_id_str.empty() && get_quqi_id_str.empty() && get_quqi_id_str_2.empty())
	{
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		Utils::errorAPIResponse(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	saveInt32("quqi_id", quqi_id);
	saveInt32("tree_id", tree_id);
	saveInt32("parent_id", parent_id);

	const PostInfo *upfile = getPostInfo("upfile");
	if (upfile == NULL)
	{
		Utils::errorAPIResponse(Lang::get("INVALID_INPUT"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	Int content_length = upfile->content().length();

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);
	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_IN_DOC_INFO);
	data->writeString(share_code);
	data->writeInt32(quqi_id);
	data->writeInt32(tree_id);
	data->writeInt32(parent_id);
	data->writeInt32(StringUtil::parseInt32(passport_id));
	data->writeString(session);
	data->writeInt32(ServerLib::Utils::getClientType(this));
	data->writeInt32(content_length);
	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadInSheet, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	String token = obj->data()->readString();
	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
	if (!storage)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const PostInfo *upfile = getPostInfo("upfile");

	DocumentStorageInfo dsi;
	const String &md5 = CodecUtil::md5(upfile->content());
	dsi.path = info.storage_path;
	dsi.name = StringUtil::toString(info.quqi_id) + "_" + StringUtil::toString(info.tree_id) +
		"_" + StringUtil::toString(info.node_id) + "_" + StringUtil::toString(info.version) + "_" + md5;
	bool save_result;
	if (info.is_encrypt)
	{
		save_result = storage->saveContent(dsi, upfile->content(), info.key);
	}
	else
	{
		save_result = storage->saveRawContent(dsi, upfile->content());
	}
	if (false == save_result)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	// 通知quqi上传成功;
	UploadTokenUS2QSInfo trans_info;
	trans_info.token = token;
	trans_info.node_id = info.node_id;
	trans_info.file_name = upfile->file_name();
	trans_info.storage_name = dsi.name;
	trans_info.content_md5 = md5;
	trans_info.content_size = upfile->content().length();

	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);
	saveInt32("node_id", info.node_id);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_IN_DOC_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadInSheet, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR"));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(ACTION_COMPLETE);
		return;
	}

	const PostInfo *upfile = getPostInfo("upfile");
	JsonValue data;
	JsonValue &ret = data["data"];
	ret["original"] = upfile->file_name();
	ret["size"] = (int_32)upfile->content().length();
	ret["state"] = "SUCCESS";
	ret["title"] = "in_doc_file"; 
	ret["type"] = "png";
	
	String share_code = loadString("share_code");
	String client_type = loadString("client_type");
	String url = share_code.size() > 0 ? "/api/share/doc/getDownload" : "/api/doc/getDownload";
	if (share_code.size() > 0) {
		url += "?share_code=" + share_code + "&";
	}
	else if (client_type.size() > 0) {
		url += "?client_type=" + client_type + "&";
	}
	else {
		url += "?";
	}

	url += "id=" + StringUtil::toString(loadInt32("quqi_id")) + "_" +
		StringUtil::toString(loadInt32("tree_id")) + "_" + StringUtil::toString(loadInt32("node_id"));
	ret["url"] = url;

	outString(Utils::succAPIResponse("ok", data));
}


//////////////////////////////////////////////////////////////////////////
// UploadWechat
AUTO_REGISTER("api/doc/uploadwechat", UploadWechat, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadWechat, 0)
{
	const String &token = getData("t");
	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_TOKEN_INFO);
	data->writeString(token);
	data->writeInt64(0);

	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadWechat, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}
	
	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
	if (!storage)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	String file_name = getData("files");
	const String &media_id = getData("server_id");
	Int wechat_app_id = StringUtil::parseInt32(getGetData("wechat_app_id"));

	Int content_length = 0;
	String raw_content = EMPTY_STR;
	String ext = EMPTY_STR;
	if(!Utils::getWechatMedia(media_id, content_length, raw_content, ext, wechat_app_id))
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	if(!ext.empty())
	{
		file_name = file_name.substr(0, file_name.find_last_of(".")) + "." + ext;
	}

	String content = "";
	if (content_length > 0 && static_cast<int_32>(raw_content.length()) > content_length)
	{
		content = raw_content.substr(0, content_length);
	}
	else
	{
		content = raw_content;
	}

	DocumentStorageInfo dsi;
	const String &md5 = CodecUtil::md5(content);
	dsi.path = info.storage_path;
	dsi.name = StringUtil::toString(info.node_id) + "_" + StringUtil::toString(info.version) + "_" + md5;
	bool save_result;
	if (info.is_encrypt)
	{
		save_result = storage->saveContent(dsi, content, info.key);
	}
	else
	{
		save_result = storage->saveRawContent(dsi, content);
	}
	if (false == save_result)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	// 通知quqi上传成功;
	UploadTokenUS2QSInfo trans_info;
	trans_info.token = getData("t");
	trans_info.node_id = info.node_id;
	trans_info.file_name = file_name;
	trans_info.storage_name = dsi.name;
	trans_info.content_md5 = md5;
	trans_info.content_size = content_length;

	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadWechat, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	JsonValue data;
	JsonValue &ret = data["data"];
	ret["quqi_id"] = obj->data()->readInt32();
	ret["tree_id"] = obj->data()->readInt32();
	ret["node_id"] = obj->data()->readInt32();
	ret["parent_id"] = obj->data()->readInt32();
	ret["node_name"] = obj->data()->readString();
	outString(Utils::succAPIResponse("ok", data));
}


//////////////////////////////////////////////////////////////////////////
// uploadding
AUTO_REGISTER("api/doc/uploadding", UploadDing, NO_PREV_ACTION);
ACTION_STEP_FUNC(UploadDing, 0)
{
	const String &token = getData("t");
	const String &header_quqi_id_str = getServer("HTTP_QUQIID");
	const String &cookie_quqi_id_str = getCookie("quqiid");
	const String &get_quqi_id_str = getData("quqiid");
	const String &get_quqi_id_str_2 = getData("quqi_id");

	int_32 quqi_id = 0;
	if (header_quqi_id_str.empty() == false)
	{
		quqi_id = StringUtil::parseInt32(header_quqi_id_str);
	}
	else if (get_quqi_id_str.empty() == false)
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
		outString(Utils::errorAPIResponse(Lang::get("INVALID_INPUT")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	saveInt32("server_id", server_id);

	QuqiCommunicationObject::Ptr obj(new QuqiCommunicationObject(ActionRunner(getRequestId(), 1, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_FETCH_UPLOAD_TOKEN_INFO);
	data->writeString(token);
	data->writeInt64(0);

	obj->communicate(server_id, data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadDing, 1)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false || obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}
	
	UploadTokenQS2USInfo info;
	info.unpack(obj->data());

	DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
	if (!storage)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	String file_name = getData("files");
	const String &img_path = getData("img_path");

	Int content_length = 0;
	String raw_content = EMPTY_STR;
	String ext = EMPTY_STR;
	if(!Utils::getDingImage(img_path, content_length, raw_content))
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	String content = "";
	if (content_length > 0 && static_cast<int_32>(raw_content.length()) > content_length)
	{
		content = raw_content.substr(0, content_length);
	}
	else
	{
		content = raw_content;
	}

	DocumentStorageInfo dsi;
	const String &md5 = CodecUtil::md5(content);
	dsi.path = info.storage_path;
	dsi.name = StringUtil::toString(info.node_id) + "_" + StringUtil::toString(info.version) + "_" + md5;
	bool save_result;
	if (info.is_encrypt)
	{
		save_result = storage->saveContent(dsi, content, info.key);
	}
	else
	{
		save_result = storage->saveRawContent(dsi, content);
	}
	if (false == save_result)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	// 通知quqi上传成功;
	UploadTokenUS2QSInfo trans_info;
	trans_info.token = getData("t");
	trans_info.node_id = info.node_id;
	trans_info.file_name = file_name;
	trans_info.storage_name = dsi.name;
	trans_info.content_md5 = md5;
	trans_info.content_size = content_length;

	obj.reset(new QuqiCommunicationObject(ActionRunner(getRequestId(), 2, this)));
	setPointer("communication_object", obj);

	NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_UPLOAD_SUCC);
	trans_info.pack(data);
	obj->communicate(loadInt32("server_id"), data);
	setNextActionStep(ACTION_ASYNC);
}

ACTION_STEP_FUNC(UploadDing, 2)
{
	QuqiCommunicationObject::Ptr obj = boost::static_pointer_cast<QuqiCommunicationObject>(getPointer("communication_object"));

	if (obj->is_succ() == false)
	{
		outString(Utils::errorAPIResponse(Lang::get("UPDOWN_UNKNOWN_ERROR")));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	if (obj->data()->readInt32() == 0)
	{
		outString(Utils::errorAPIResponse(obj->data()->readString()));
		setNextActionStep(REQUEST_COMPLETE);
		return;
	}

	JsonValue data;
	JsonValue &ret = data["data"];
	ret["quqi_id"] = obj->data()->readInt32();
	ret["tree_id"] = obj->data()->readInt32();
	ret["node_id"] = obj->data()->readInt32();
	ret["parent_id"] = obj->data()->readInt32();
	ret["node_name"] = obj->data()->readString();
	outString(Utils::succAPIResponse("ok", data));
}

