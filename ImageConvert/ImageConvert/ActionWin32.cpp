#include "PreCompiled.h"
#include "ActionWin32.h"

#ifdef WIN32

//////////////////////////////////////////////////////////////////////////
// NginxUpload
AUTO_REGISTER("api/doc/upload", NginxUpload, NO_PREV_ACTION);
ACTION_STEP_FUNC(NginxUpload, 0)
{
	const String &token = getData("t");

	String file_save_path = "E:\\nginx_cache";
	if (!FileUtil::isFileExist(file_save_path))
	{
		FileUtil::mkdir(file_save_path);
	}

	const PostInfo *info = getPostInfo("files");
	if (info == NULL) return;

	int_32 content_length = info->content().size();
	String md5 = CodecUtil::md5(info->content());
	String file_path = file_save_path + "\\" + md5;
	StringStringMap param;
	param.insert(make_pair("file_name", info->file_name()));
	param.insert(make_pair("file_path", file_path));
	param.insert(make_pair("file_md5", md5));
	param.insert(make_pair("file_size", StringUtil::toString(content_length)));

	FileUtil::saveFile(info->content(), file_path);

	String out;
	StringVector headers;
	headers.push_back(String("Cookie: quqiid=")+getCookie("quqiid"));
	HttpService::getInstance().post("file.quqi.com/api/doc/upload_backend?t="+getData("t"), param, headers, out);
	outString(out);
}

// NginxReupload
AUTO_REGISTER("api/doc/reupload", NginxReupload, NO_PREV_ACTION);
ACTION_STEP_FUNC(NginxReupload, 0)
{
	const String &token = getData("t");

	String file_save_path = "E:\\nginx_cache";
	if (!FileUtil::isFileExist(file_save_path))
	{
		FileUtil::mkdir(file_save_path);
	}

	const PostInfo *info = getPostInfo("reuploadfile");
	if (info == NULL) return;

	int_32 content_length = info->content().size();
	String md5 = CodecUtil::md5(info->content());
	String file_path = file_save_path + "\\" + md5;
	StringStringMap param;
	param.insert(make_pair("file_name", info->file_name()));
	param.insert(make_pair("file_path", file_path));
	param.insert(make_pair("file_md5", md5));
	param.insert(make_pair("file_size", StringUtil::toString(content_length)));

	FileUtil::saveFile(info->content(), file_path);

	String out;
	StringVector headers;
	headers.push_back(String("Cookie: quqiid=")+getCookie("quqiid"));
	HttpService::getInstance().post("file.quqi.com/api/doc/upload_backend?t="+getData("t"), param, headers, out);
	outString(out);
}

//////////////////////////////////////////////////////////////////////////
// NginxUploadDir
AUTO_REGISTER("api/doc/uploadDir", NginxUploadDir, NO_PREV_ACTION);
ACTION_STEP_FUNC(NginxUploadDir, 0)
{
	const String &token = getData("t");

	String file_save_path = "E:\\nginx_cache";
	if (!FileUtil::isFileExist(file_save_path))
	{
		FileUtil::mkdir(file_save_path);
	}

	const PostInfo *info = getPostInfo("folder");
	if (info == NULL) return;

	size_t index = info->file_name().rfind('/');
	String file_name = info->file_name();
	if (index != String::npos)
	{
		file_name = info->file_name().substr(index+1);
	}

	int_32 content_length = info->content().size();
	String md5 = CodecUtil::md5(info->content());
	String file_path = file_save_path + "\\" + md5;
	StringStringMap param;
	param.insert(make_pair("file_name", file_name));
	param.insert(make_pair("file_path", file_path));
	param.insert(make_pair("file_md5", md5));
	param.insert(make_pair("file_size", StringUtil::toString(content_length)));

	FileUtil::saveFile(info->content(), file_path);

	info = getPostInfo("path");
	if (info == NULL) return;
	param.insert(make_pair("path", info->content()));

	String out;
	StringVector headers;
	headers.push_back(String("Cookie: quqiid=")+getCookie("quqiid"));
	HttpService::getInstance().post("file.quqi.com/api/doc/uploadDir_backend?t="+getData("t"), param, headers, out);
	outString(out);
}

#endif