# -*- coding:utf-8 -*-


data_directory = "screenshots"

### 1代表灰度处理， 2代表二值化处理，如果需要使用二值化，需要将2放到前面, 0不使用
image_compress_level = (1, 1, 2)
# image_compress_level = (2, 1)

### 0 表示普通识别，配合compress_level 1使用
### 1 标识精确识别，精确识别建议配合image_compress_level 2使用
api_version = (0, 1)
# api_version = (1, 0)

## 设置baidu ocr
app_id = "10681042"
app_key = "oZokCbcX3unqb4CpGvD873Co"
app_secret = "2bNzvBQ4l4HkXAGFc3azMeinQ02ntdf2"
