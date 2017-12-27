#include "PreCompiled.h"
#include "ConvertManager.h"

#include "Utils.h"
#include "Magick++.h"
#include "Setting.h"
#include "QuqiIdMap.h"
#include "QuqiSocketClientManager.h"

#include "Sdk/Quqi/DocumentStorageBase.h"
#include "Sdk/Quqi/DocumentStorageManager.h"
#include "Const.h"

USING_NS_QUQI_SDK;
using namespace Magick;

const static int_32 g_thumbnail_size = 200;			// 缩略图尺寸;

static void magickFatalError( const MagickCore::ExceptionType error, const char *reason, const char *description )
{
	lerrorln("MagickFatalError: Magick catch a exception: %d, %s, reason", error, description, reason);
}

SINGLETON_DEFINITION(ConvertManager);
int_32 ConvertManager::s_max_convert_thread_cnt = 4;
ConvertManager::ConvertManager()
	:_thread_pool(s_max_convert_thread_cnt)
{
	MagickCore::SetFatalErrorHandler(magickFatalError);
}

ConvertManager::~ConvertManager()
{

}

void ConvertManager::convert( QuqiSDK::ConvertToPicInfo &convert_info )
{
	AutoLock lock(_info_mul_map_lock);

	const String &key = convert_info.storage_path + convert_info.storage_name + StringUtil::toString(convert_info.convert_type);
	uint_32 count = _info_mul_map.count(key);
	_info_mul_map.insert(make_pair(key, convert_info));

	if (count == 0)
	{
		_thread_pool.run(boost::bind(&ConvertManager::doConvert, this, convert_info));
	}
}

void ConvertManager::doConvert( QuqiSDK::ConvertToPicInfo &info )
{
	switch (info.convert_type)
	{
	case UNKNOWN_TYPE_TO_PIC: return unknownTypeToJpg(info);
	case PDF_TO_PIC: return pdfToJpg(info);
	case HTML_TO_PIC: case WEB_HTML_TO_PIC: return htmlToJpg(info);
	case HTML_TO_MOBILE_PIC: return htmlToMobileJpg(info);
	case PSD_TO_PIC: return psdToJpg(info);
	}
}

void ConvertManager::onConvertComplete( QuqiSDK::ConvertToPicInfo &info )
{
	// 发送到QuqiServer;
	AutoLock lock(_info_mul_map_lock);

	const String &key = info.storage_path + info.storage_name + StringUtil::toString(info.convert_type);
	std::pair<ConvertToPicInfoMulMap::iterator, ConvertToPicInfoMulMap::iterator> range = _info_mul_map.equal_range(key);

	for (ConvertToPicInfoMulMap::iterator iter = range.first; iter != range.second; ++iter)
	{
		ConvertToPicInfo &send_info = iter->second;
		NetData::Ptr data = NetData::create(::Proc::US_2_QS_NOTIFY_CONVERT_TO_PIC_SUCC);
		send_info.status = info.status;
		send_info.pic_size_info = info.pic_size_info;
		send_info.pack(data);
		
		int_32 server_id = QuqiIdMap::getInstance().getQuqiServerId(send_info.quqi_id);
		if (server_id == -1)
		{
			lerrorln("ConvertManager::onConvertComplete: can not find server id with quqi_id: %d", send_info.quqi_id);
			continue;
		}

		QuqiSocketClientManager::getInstance().dispatch(server_id, data);
	}

	_info_mul_map.erase(range.first, range.second);
}

String generatePicSizeInfo(MagickCore::Image *image)
{
	JsonValue ret;
	
	uint_32 last_width = -1, last_height = -1;
	int_32 index = 1;
	while (image)
	{
		if (image->columns != last_width || image->rows != last_height)
		{
			last_width = image->columns;
			last_height = image->rows;
			JsonValue &size = ret.append(JsonValue());
			size["w"] = last_width;
			size["h"] = last_height;
			size["index"] = index;
		}
		++index;
		image = image->next;
	}

	return JsonUtil::ValueToString(ret);
}

void ConvertManager::unknownTypeToJpg( QuqiSDK::ConvertToPicInfo &info )
{
	try
	{
		llogln("ConvertManager::unknownToJpg: begin convert: quqi_id: %d, node_id: %d, %s/%s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			throw runtime_error("can not find storage with id: " + StringUtil::toString(info.storage_id));
		}

		int_64 begin_tick = TimeUtil::tick();

		String path = Setting::getInstance().cache_path()+"/"+info.storage_path;
		if (FileUtil::isFileExist(path) == false)
		{
			FileUtil::mkdir(path);
		}

		String cache_file_path = path+"/"+info.storage_name;
		if (info.file_path.empty())
		{
			if (FileUtil::isFileExist(cache_file_path) == false)
			{
				DocumentStorageInfo dsi;
				dsi.path = info.storage_path;
				dsi.name = info.storage_name;

				String content;
				if (info.is_encrypt)
				{
					content = storage->loadContent(dsi, info.key);
				}
				else
				{
					content = storage->loadRawContent(dsi);
				}
				FileUtil::saveFile(content, cache_file_path);
			}

			info.file_path = cache_file_path;
		}

		Image image;
		image.read(info.file_path);

		String jpg_cache_file_path = cache_file_path+"_0";
		image.magick("JPEG");	
		image.write(jpg_cache_file_path);

		// 缩略图;
		image.magick("PNG");
		image.backgroundColor(Color(0, 0, 0, 0));
		uint_32 width = image.columns();
		uint_32 height = image.rows();
		float_32 ratio = width*1.0f/height;
		if (ratio > 1)
		{
			width = g_thumbnail_size;
			height = (int_32)(width/ratio);
		}
		else
		{
			height = g_thumbnail_size;
			width = (int_32)(g_thumbnail_size*ratio);
		}
		image.resize(Geometry(width, height));
		image.write(jpg_cache_file_path+"_t");

		{
			// 上传到storage;
			DocumentStorageInfo dsi;
			dsi.path = info.storage_path;
			dsi.name = info.storage_name+"_0";

			String content;
			FileUtil::loadFile(content, jpg_cache_file_path);
			if (info.is_encrypt)
			{
				storage->saveContent(dsi, content, info.key);
			}
			else
			{
				storage->saveRawContent(dsi, content);
			}
		}
		
		{
			// 上传缩略图到storage;
			DocumentStorageInfo dsi;
			dsi.path = info.storage_path;
			dsi.name = info.storage_name+"_0_t";

			String content;
			FileUtil::loadFile(content, jpg_cache_file_path+"_t");
			if (info.is_encrypt)
			{
				storage->saveContent(dsi, content, info.key);
			}
			else
			{
				storage->saveRawContent(dsi, content);
			}
		}

		int_64 use_time = TimeUtil::tick()-begin_tick;
		llogln("ConvertManager::unknownTypeToJpg: quqi_id: %d, node_id: %d, %s/%s, succ use time: %lld", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), use_time);

		JsonValue ret;
		JsonValue &size = ret.append(JsonValue());
		size["w"] = (Int)image.size().width();
		size["h"] = (Int)image.size().height();
		size["index"] = 1;

		info.pic_size_info = JsonUtil::ValueToString(ret);
		info.status = 1;
	}
	catch(std::exception &error)   
	{
		info.status = 0;
		llogln("ConvertManager::unknownTypeToJpg: quqi_id: %d, node_id: %d, %s/%s, failed error: %s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), error.what());   	
	}
	onConvertComplete(info);
}

void ConvertManager::pdfToJpg( QuqiSDK::ConvertToPicInfo &info )
{
	ImageInfo *image_info = NULL;
	MagickCore::Image *image = NULL;
	MagickCore::ExceptionInfo *exception = NULL;
	try
	{
		llogln("ConvertManager::pdfToJpg: begin convert: quqi_id: %d, node_id: %d, %s/%s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str());

		int_64 begin_tick = TimeUtil::tick();

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			throw runtime_error("can not find storage with id: " + StringUtil::toString(info.storage_id));
		}

		String path = Setting::getInstance().cache_path()+"/"+info.storage_path;
		if (FileUtil::isFileExist(path) == false)
		{
			FileUtil::mkdir(path);
		}

		String cache_file_path = path+"/"+info.storage_name;
		if (info.file_path.empty())
		{
			if (FileUtil::isFileExist(cache_file_path) == false)
			{
				DocumentStorageInfo dsi;
				dsi.path = info.storage_path;
				dsi.name = info.storage_name;

				String content;
				if (info.is_encrypt)
				{
					content = storage->loadContent(dsi, info.key);
				}
				else
				{
					content = storage->loadRawContent(dsi);
				}

				FileUtil::saveFile(content, cache_file_path);
			}

			info.file_path = cache_file_path;
		}

		image_info = MagickCore::AcquireImageInfo();
		exception = MagickCore::AcquireExceptionInfo();

		strncpy(image_info->filename, info.file_path.c_str(), 4096);
		char desity[] = "150";
		image_info->density = desity;
		image_info->quality = 80;
		image_info->antialias = MagickTrue;
		image = MagickCore::ReadImage(image_info, exception);
		throwException(exception, false);

		// 获取长宽;
		info.pic_size_info = generatePicSizeInfo(image);
	
		String out_img_path = cache_file_path+"_%d";
		if (info.convert_type == ConvertType::HTML_TO_MOBILE_PIC)
		{
			out_img_path += "_m";
		}
		
		int_32 cnt = 0;
		MagickCore::Image *image_list = image;
		while (image)
		{
			MagickCore::Image *next_image = MagickCore::RemoveImageFromList(&image);
			++cnt;
			strncpy(image_info->magick, "JPG", 4096);
			strncpy(next_image->filename, out_img_path.c_str(), 4096);
			WriteImage(image_info, next_image, exception);

			// 缩略图;
			strncpy(image_info->magick, "PNG", 4096);
			strncpy(next_image->filename, (out_img_path+"_t").c_str(), 4096);
			next_image->background_color.red = 0;
			next_image->background_color.green = 0;
			next_image->background_color.black = 0;
			next_image->background_color.blue = 0;
			next_image->background_color.alpha = 0;
			next_image->background_color.alpha_trait=BlendPixelTrait;

			uint_32 width = next_image->columns;
			uint_32 height = next_image->rows;
			float_32 ratio = width*1.0f/height;
			if (ratio > 1)
			{
				width = g_thumbnail_size;
				height = (int_32)(width/ratio);
			}
			else
			{
				height = g_thumbnail_size;
				width = (int_32)(g_thumbnail_size*ratio);
			}
			MagickCore::Image *resize_image = ResizeImage(next_image, width, height, next_image->filter, exception);
			WriteImage(image_info, resize_image, exception);

			MagickCore::DestroyImage(next_image);
			MagickCore::DestroyImage(resize_image);
			// throwException(exception, false);
		}

		// 上传到storage;
		for (int_32 i = 0; i < cnt; ++i)
		{
			{
				DocumentStorageInfo dsi;
				dsi.path = info.storage_path;
				dsi.name = info.storage_name+"_"+StringUtil::toString(i);
				if (info.convert_type == ConvertType::HTML_TO_MOBILE_PIC)
				{
					dsi.name += "_m";
				}

				String content;
				FileUtil::loadFile(content, Setting::getInstance().cache_path()+"/"+dsi.path+"/"+dsi.name);
				if (info.is_encrypt)
				{
					storage->saveContent(dsi, content, info.key);
				}
				else
				{
					storage->saveRawContent(dsi, content);
				}
			}
			
			{
				DocumentStorageInfo dsi;
				dsi.path = info.storage_path;
				dsi.name = info.storage_name+"_"+StringUtil::toString(i);
				if (info.convert_type == ConvertType::HTML_TO_MOBILE_PIC)
				{
					dsi.name += "_m";
				}
				dsi.name += "_t";

				String content;
				FileUtil::loadFile(content, Setting::getInstance().cache_path()+"/"+dsi.path+"/"+dsi.name);
				if (info.is_encrypt)
				{
					storage->saveContent(dsi, content, info.key);
				}
				else
				{
					storage->saveRawContent(dsi, content);
				}
			}
		}

		int_64 use_time = TimeUtil::tick()-begin_tick;
		info.status = cnt;
		llogln("ConvertManager::pdfToJpg: quqi_id: %d node_id: %d, %s/%s, succ use time: %lld, page cnt: %d", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), use_time, cnt);
	}   
	catch(std::exception &error)   
	{
		exception = NULL;
		info.status = 0;
		llogln("ConvertManager::pdfToJpg: quqi_id: %d, node_id: %d, %s/%s, failed error: %s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), error.what());   	
	}

	if (image)
	{
		MagickCore::DestroyImageList(image);
	}

	if (image_info)
	{
		image_info->density = NULL;
		MagickCore::DestroyImageInfo(image_info);
	}
	
	if (exception)
	{
		MagickCore::DestroyExceptionInfo(exception);
	}
	
	onConvertComplete(info);
}

void ConvertManager::htmlToJpg( QuqiSDK::ConvertToPicInfo &info )
{
	try
	{
		llogln("ConvertManager::htmlToJpg: begin convert: quqi_id: %d, node_id: %d, %s/%s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			throw runtime_error("can not find storage with id: " + StringUtil::toString(info.storage_id));
		}

		int_64 begin_tick = TimeUtil::tick();

		DocumentStorageInfo dsi;
		dsi.path = info.storage_path;
		dsi.name = info.storage_name;

		String raw_content;
		if (info.is_encrypt)
		{
			raw_content = storage->loadContent(dsi, info.key);
		}
		else
		{
			raw_content = storage->loadRawContent(dsi);
		}

		String content = StringUtil::replace(raw_content, "\"/api/doc/getDownload?", 
			"\""+Setting::getInstance().inner_quqi_host()+"/api_for_intrant/doc/getDownload?");
		String format;
		if (info.convert_type == HTML_TO_PIC)
		{
			format = "wkhtmltopdf --cookie quqiid %d \"%s\" \"%s\" >> convert_log 2>&1";
			content = "<head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"ueditor.css\" type=\"text/css\" /></head><div class=\"ueditor\" style=\"padding: 100px;\">"+
				content+"</div>";
		}
		else if (info.convert_type == WEB_HTML_TO_PIC)
		{
			format = "wkhtmltopdf --page-width 325 --page-height 183 --cookie quqiid %d \"%s\" \"%s\" >> convert_log 2>&1";
			content = "<head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"ueditor.css\" type=\"text/css\" /></head><div class=\"ueditor\">"+
				content+"</div>";
		}

		// 存为临时文件;
		String temp_html_full_path =  Setting::getInstance().tmp_path()+"/"+Utils::randomName(16)+".html";
		FileUtil::saveFile(content, temp_html_full_path);

		String temp_pdf_full_path = Setting::getInstance().tmp_path()+"/"+Utils::randomName(16)+".pdf";

		String command = StringUtil::format(format.c_str(), info.quqi_id, temp_html_full_path.c_str(), temp_pdf_full_path.c_str());

		int_32 ret = ::system(command.c_str());
		if (ret != 0)
		{
			throw runtime_error("convert failed!");
		}
		
		// 删除文件;
		FileUtil::remove(temp_html_full_path);

		info.file_path = temp_pdf_full_path;
		pdfToJpg(info);

		FileUtil::remove(temp_pdf_full_path);
		
		int_64 use_time = TimeUtil::tick()-begin_tick;
		llogln("ConvertManager::htmlToJpg: quqi_id: %d, node_id: %d, %s/%s, succ use time: %lld", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), use_time);
	}
	catch(std::exception &error)   
	{
		info.status = 0;
		onConvertComplete(info);
		llogln("ConvertManager::htmlToJpg: quqi_id: %d, node_id: %d, %s/%s, failed error: %s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), error.what());   	
	}
}


void ConvertManager::htmlToMobileJpg( QuqiSDK::ConvertToPicInfo &info )
{
	try
	{
		llogln("ConvertManager::htmlToMobileJpg: begin convert: quqi_id: %d, node_id: %d, %s/%s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			throw runtime_error("can not find storage with id: " + StringUtil::toString(info.storage_id));
		}

		int_64 begin_tick = TimeUtil::tick();

		DocumentStorageInfo dsi;
		dsi.path = info.storage_path;
		dsi.name = info.storage_name;

		String raw_content;
		if (info.is_encrypt)
		{
			raw_content = storage->loadContent(dsi, info.key);
		}
		else
		{
			raw_content = storage->loadRawContent(dsi);
		}

		String content = StringUtil::replace(raw_content, "\"/api/doc/getDownload?", 
			"\""+Setting::getInstance().inner_quqi_host()+"/api_for_intrant/doc/getDownload?");
		content = "<head><meta charset=\"utf-8\"><link rel=\"stylesheet\" href=\"ueditor.tcss\" type=\"text/css\" /></head><div class=\"ueditor\">"+
			content+"</div>";

		// 存为临时文件;
		String temp_html_full_path =  Setting::getInstance().tmp_path()+"/"+Utils::randomName(16)+".html";
		FileUtil::saveFile(content, temp_html_full_path);

		String temp_pdf_full_path = Setting::getInstance().tmp_path()+"/"+Utils::randomName(16)+".pdf";

		String command = StringUtil::format("wkhtmltopdf --page-size A6 --cookie quqiid %d \"%s\" \"%s\" >> convert_log 2>&1", info.quqi_id, temp_html_full_path.c_str(), temp_pdf_full_path.c_str());

		int_32 ret = ::system(command.c_str());
		if (ret != 0)
		{
			throw runtime_error("convert failed!");
		}

		// 删除文件;
		FileUtil::remove(temp_html_full_path);

		info.file_path = temp_pdf_full_path;
		pdfToJpg(info);

		FileUtil::remove(temp_pdf_full_path);

		int_64 use_time = TimeUtil::tick()-begin_tick;
		llogln("ConvertManager::htmlToMobileJpg: quqi_id: %d, node_id: %d, %s/%s, succ use time: %lld", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), use_time);
	}
	catch(std::exception &error)   
	{
		info.status = 0;
		onConvertComplete(info);
		llogln("ConvertManager::htmlToMobileJpg: quqi_id: %d, node_id: %d, %s/%s, failed error: %s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), error.what());   	
	}
}

void ConvertManager::psdToJpg( QuqiSDK::ConvertToPicInfo &info )
{
	try
	{
		llogln("ConvertManager::psdToJpg: begin convert: quqi_id: %d, node_id: %d, %s/%s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str());

		DocumentStorageBase* storage = DocumentStorageManager::getInstance().getStorage(info.storage_id);
		if (!storage)
		{
			throw runtime_error("can not find storage with id: " + StringUtil::toString(info.storage_id));
		}

		int_64 begin_tick = TimeUtil::tick();

		String path = Setting::getInstance().cache_path()+"/"+info.storage_path;
		if (FileUtil::isFileExist(path) == false)
		{
			FileUtil::mkdir(path);
		}

		String cache_file_path = path+"/"+info.storage_name+".psd";
		if (info.file_path.empty())
		{
			if (FileUtil::isFileExist(cache_file_path) == false)
			{
				DocumentStorageInfo dsi;
				dsi.path = info.storage_path;
				dsi.name = info.storage_name;

				String content;
				if (info.is_encrypt)
				{
					content = storage->loadContent(dsi, info.key);
				}
				else
				{
					content = storage->loadRawContent(dsi);
				}

				FileUtil::saveFile(content, cache_file_path);
			}

			info.file_path = cache_file_path;
		}

		Image image;
		image.read(info.file_path+"[0]");

		String jpg_cache_file_path = path+"/"+info.storage_name+"_0";
		image.magick("JPEG");
		image.quality(80);
		image.write(jpg_cache_file_path);

		// 缩略图;
		image.magick("PNG");
		image.backgroundColor(Color(0, 0, 0, 0));
		uint_32 width = image.columns();
		uint_32 height = image.rows();
		float_32 ratio = width*1.0f/height;
		if (ratio > 1)
		{
			width = g_thumbnail_size;
			height = (int_32)(width/ratio);
		}
		else
		{
			height = g_thumbnail_size;
			width = (int_32)(g_thumbnail_size*ratio);
		}
		image.resize(Geometry(width, height));
		image.write(jpg_cache_file_path+"_t");

		{
			// 上传到storage;
			DocumentStorageInfo dsi;
			dsi.path = info.storage_path;
			dsi.name = info.storage_name+"_0";

			String content;
			FileUtil::loadFile(content, jpg_cache_file_path);
			if (info.is_encrypt)
			{
				storage->saveContent(dsi, content, info.key);
			}
			else
			{
				storage->saveRawContent(dsi, content);
			}
		}

		{
			// 上传缩略图到storage;
			DocumentStorageInfo dsi;
			dsi.path = info.storage_path;
			dsi.name = info.storage_name+"_0_t";

			String content;
			FileUtil::loadFile(content, jpg_cache_file_path+"_t");
			if (info.is_encrypt)
			{
				storage->saveContent(dsi, content, info.key);
			}
			else
			{
				storage->saveRawContent(dsi, content);
			}
		}

		int_64 use_time = TimeUtil::tick()-begin_tick;
		llogln("ConvertManager::psdToJpg: quqi_id: %d, node_id: %d, %s/%s, succ use time: %lld", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), use_time);

		JsonValue ret;
		JsonValue &size = ret.append(JsonValue());
		size["w"] = (Int)image.size().width();
		size["h"] = (Int)image.size().height();
		size["index"] = 1;

		info.pic_size_info = JsonUtil::ValueToString(ret);
		info.status = 1;
	}
	catch(std::exception &error)   
	{
		info.status = 0;
		llogln("ConvertManager::psdToJpg: quqi_id: %d, node_id: %d, %s/%s, failed error: %s", info.quqi_id, info.node_id, info.storage_path.c_str(), info.storage_name.c_str(), error.what());
	}
	onConvertComplete(info);
}
