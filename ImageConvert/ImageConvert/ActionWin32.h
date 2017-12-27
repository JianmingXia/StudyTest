#pragma once

#ifdef WIN32
// win32下模拟nginx上传插件功能;
ACTION_CLASS(NginxUpload, 0);
ACTION_CLASS(NginxReupload, 0);
ACTION_CLASS(NginxUploadDir, 0);
#endif