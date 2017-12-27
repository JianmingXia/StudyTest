#include "PreCompiled.h"
#include "StorageUploadManager.h"

#include "Sdk/Quqi/DocumentStorageManager.h"
#include "Utils.h"

USING_NS_QUQI_SDK;


//////////////////////////////////////////////////////////////////////////
// StorageUploadInfo
StorageUploadInfo::StorageUploadInfo()
{
	is_encrypt = true;
}

StorageUploadInfo::StorageUploadInfo( StorageUploadInfo &o )
	:file_path(o.file_path), storage_info(o.storage_info)
{
	storage_id = o.storage_id;
	is_encrypt = o.is_encrypt;
	memcpy(key, o.key, sizeof(key));
}

StorageUploadInfo & StorageUploadInfo::operator=( StorageUploadInfo &o )
{
	file_path = o.file_path;
	storage_info = o.storage_info;
	storage_id = o.storage_id;
	is_encrypt = o.is_encrypt;
	memcpy(key, o.key, sizeof(key));
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// StorageUploadItem
StorageUploadItem::StorageUploadItem( StorageUploadInfo &storage_upload_info )
	:_storage_upload_info(storage_upload_info)
{
}

StorageUploadItem::~StorageUploadItem()
{

}

void StorageUploadItem::upload()
{
	_parent->_thread_pool.run(boost::bind(&StorageUploadItem::doUpload, this));
}

void StorageUploadItem::doUpload()
{
	Utils::saveStorageLog("StorageUploadItem::doUpload start", _storage_upload_info.storage_info.path, 
		_storage_upload_info.storage_info.name);

	DocumentStorageBase *storage = DocumentStorageManager::getInstance().getStorage(_storage_upload_info.storage_id);
	if (storage)
	{
		String content;
		FileUtil::loadFile(content, _storage_upload_info.file_path);
		bool save_ret;
		if (_storage_upload_info.is_encrypt) {
			save_ret = storage->saveContent(_storage_upload_info.storage_info, content, _storage_upload_info.key);
		}
		else {
			save_ret = storage->saveRawContent(_storage_upload_info.storage_info, content);
		}

		if (save_ret) {
			Utils::saveStorageLog("StorageUploadItem::doUpload success", _storage_upload_info.storage_info.path, 
				_storage_upload_info.storage_info.name);
		}
		else{
			Utils::saveStorageLog("StorageUploadItem::doUpload fail", _storage_upload_info.storage_info.path, 
				_storage_upload_info.storage_info.name);
		}
	}
	else
	{
		Utils::saveStorageLog("StorageUploadItem::doUpload: get storage failed for storage id: " + 
			StringUtil::toString(_storage_upload_info.storage_id), _storage_upload_info.storage_info.path, 
			_storage_upload_info.storage_info.name);

		lerrorln("StorageUploadItem::doUpload: get storage failed for storage id: %d", _storage_upload_info.storage_id);
	}

	//_parent->onUploadComplete(this);
}



//////////////////////////////////////////////////////////////////////////
// StorageUploadManager
SINGLETON_DEFINITION(StorageUploadManager);
int_32 StorageUploadManager::s_max_thread_cnt = 0;
uint_64 StorageUploadManager::s_max_memory_used = (uint_64)4*1024*1024*1024;
StorageUploadManager::StorageUploadManager()
{
	_cur_memory_size = 0;
}

StorageUploadManager::~StorageUploadManager()
{

}

void StorageUploadManager::addUpload( StorageUploadInfo &storage_upload_info )
{
	/*StorageUploadItem *item = new StorageUploadItem(storage_upload_info);
	item->_parent = this;
	item->_insert_time = TimeUtil::now();

	AutoLock lock(_item_queue_lock);
	_item_queue.push_back(item);
	pickOneToUpload();*/
	StorageUploadItem item(storage_upload_info);
	item.doUpload();
}

void StorageUploadManager::onUploadComplete( StorageUploadItem *item )
{
	AutoLock lock(_item_queue_lock);
	_cur_memory_size -= item->_storage_upload_info.storage_info.size;
	delete item;

	pickOneToUpload();
}

void StorageUploadManager::pickOneToUpload()
{
	if (_item_queue.empty())
	{
		return;
	}

	StorageUploadItem *front_item = _item_queue.front();
	
	// 只往后找3个;
	int_32 i = 0;
	for (StorageUploadItemQueue::iterator iter = _item_queue.begin(); iter != _item_queue.end() && i < 3; ++i)
	{
		StorageUploadItem *item = *iter;

		// 内存符合要求，并且插入时间与front元素相差在1分钟内的进行插入;
		if (_cur_memory_size + item->_storage_upload_info.storage_info.size < s_max_memory_used &&
			item->_insert_time - front_item->_insert_time < 60)
		{
			_item_queue.erase(iter);
			item->upload();
			_cur_memory_size += item->_storage_upload_info.storage_info.size;
			break;
		}
	}
}
