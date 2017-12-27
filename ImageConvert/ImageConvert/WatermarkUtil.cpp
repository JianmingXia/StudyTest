#include "PreCompiled.h"
#include "WatermarkUtil.h"

#include "Setting.h"
#include "Magick++.h"

USING_NS_QUQI_SDK;
using namespace Magick;

bool WatermastUtil::outWatermarkData( ActionBase* action, DownloadTokenInfo &info, DocumentStorageBase *storage, const String &cache_file_path )
{
	if (info.watermark_info.use == false)
	{
		return false;
	}

	// 是否是图片;
	try
	{
		// 源图片;
		Image image_source;
		if (FileUtil::isFileExist(cache_file_path))
		{
			image_source.read(cache_file_path);
		}
		else
		{
			DocumentStorageInfo dsi;
			dsi.path = info.path;
			dsi.name = info.name;
			dsi.size = info.size;

			String ret;
			if (info.is_encrypt)
			{
				ret = storage->loadContent(dsi, info.key);
			}
			else
			{
				ret = storage->loadRawContent(dsi);
			}

			FileUtil::saveFile(ret, cache_file_path);
			Blob blob(ret.c_str(), ret.length());
			image_source.read(blob);
		}

		int_64 begin_time = TimeUtil::tick();

		int_32 width = image_source.size().width();
		int_32 height = image_source.size().height();

		Image image_watermark(Geometry(width, height), Color(0, 0, 0, 0));

		// 生成水印图片;
		StringVector watermark_texts;
		if (info.watermark_info.type & WatermarkType::QUQI_NAME && !info.watermark_info.quqi_name.empty())
		{
			watermark_texts.push_back(info.watermark_info.quqi_name);
		}
		if (info.watermark_info.type & WatermarkType::CUSTOM_TEXT && !info.watermark_info.custom_text.empty())
		{
			watermark_texts.push_back(info.watermark_info.custom_text);
		}
		if (info.watermark_info.type & WatermarkType::USER_NAME && !info.watermark_info.user_name.empty())
		{
			watermark_texts.push_back(info.watermark_info.user_name);
		}
		if (info.watermark_info.type & WatermarkType::TIME && info.watermark_info.time != 0)
		{
#ifdef WIN32
			static String s_time_format = CodecUtil::gbkToUtf8("{year}/{month}/{day} {hour}:{minute}");
#endif
#ifdef LINUX
			static String s_time_format = "{year}/{month}/{day} {hour}:{minute}";
#endif
			watermark_texts.push_back(TimeUtil::makeTimeString(s_time_format, info.watermark_info.time));
		}

#ifdef WIN32 
		image_watermark.fontFamily("Microsoft YaHei Bold & Microsoft YaHei UI");
#endif
#ifdef LINUX
		image_watermark.font("/usr/share/fonts/local/msyhbd.ttc");
#endif
		image_watermark.fontWeight(700);

		// 根据图片分辨率来分配;
		float_32 font_size = 30.0f*width/1000;
		font_size = font_size < 20? 20:font_size;
		uint_32 watermark_text_cnt = watermark_texts.size();
		float_32 height_begin = 200.0f*width/1000;
		height_begin = height_begin>200? 200:height_begin;
		float_32 height_interval = 225.0f*width/1000;
		float_32 height_max = height+width*tanf(3.1415926f/9);
		uint_32 row_text_interval = watermark_text_cnt>2? 2:1;

		image_watermark.fontPointsize(font_size);

		int_32 line_cnt = 0;
		if (watermark_text_cnt > 0)
		{
			image_watermark.fillColor(Color(0x33/255.0*65535, 0x93/255.0*65535, 0xE7/255.0*65535, 0.2*65535));
			{
				float_32 y = height_begin;
				uint_32 row_index = 0;
				while (true)
				{
					// 一行;
					uint_32 col_index = row_index;

					String text;
					float_32 length = 0;
					while (length < width+100)
					{
						text += watermark_texts[col_index] + "                ";
						length += (StringUtil::utf8StringLength(watermark_texts[col_index])+4)*font_size;
						if (++col_index >= watermark_text_cnt)
						{
							col_index = 0;
						}
					}

					image_watermark.annotate(text, Geometry(0, 0, 0, (int_32)y), NorthWestGravity, -20);
					++line_cnt;

					y += height_interval;
					row_index += row_text_interval;
					if (row_index >= watermark_text_cnt)
					{
						row_index = row_index%watermark_text_cnt;
					}

					if (y > height_max)
					{
						break;
					}
				}
			}
		}

		image_source.composite(image_watermark, 0, 0, CompositeOperator::SrcOverCompositeOp);
		Blob blob;
		image_source.magick("JPEG");
		image_source.write(&blob);

		int_64 end_time = TimeUtil::tick();
		llogln("WatermastUtil::outWatermarkData: pic size: %dx%d, watermark line cnt: %d, convert succ use time: %lld", width, height, line_cnt, end_time-begin_time);

		action->header("Content-Length: "+ StringUtil::toString(blob.length()));

		action->outString((char*)blob.data(), blob.length());
	}
	catch (std::exception &e)
	{
		lerrorln("WatermastUtil::outWatermarkData: catch exception: %s", e.what());
	}
	return true;
}
