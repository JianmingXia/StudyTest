#pragma once

#include "Sdk/Quqi/DocumentStorageBase.h"

struct StorageUploadInfo
{
	StorageUploadInfo();
	StorageUploadInfo(StorageUploadInfo &o);

	StorageUploadInfo &operator=(StorageUploadInfo &o);

	String file_path;
	QuqiSDK::DocumentStorageInfo storage_info;
	int_32 storage_id;
	uint_8 key[16];
	bool is_encrypt;
};

class StorageUploadManager;
class StorageUploadItem
{
	friend class StorageUploadManager;
public:
	StorageUploadItem(StorageUploadInfo &storage_upload_info);
	~StorageUploadItem();

	void upload();
	void doUpload();

protected:
	StorageUploadInfo _storage_upload_info;
	int_32 _insert_time;

	StorageUploadManager *_parent;
};
typedef std::list<StorageUploadItem*> StorageUploadItemQueue;

class StorageUploadManager
{
	friend class StorageUploadItem;

	SINGLETON_DECLARATION(StorageUploadManager);
public:
	StorageUploadManager();
	~StorageUploadManager();

	void addUpload(StorageUploadInfo &storage_upload_info);

	static int_32 s_max_thread_cnt;			// 最大线程数，默认为8;
	static uint_64 s_max_memory_used;		// 最大内存使用量，避免内存过大，默认4G;

protected:
	void onUploadComplete(StorageUploadItem *item);
	void pickOneToUpload();

protected:
	uint_64 _cur_memory_size;
	StorageUploadItemQueue _item_queue;		// 上传队列;
	Mutex _item_queue_lock;
	ThreadPool _thread_pool;				// 上传线程;
};