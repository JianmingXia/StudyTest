# -*- coding: UTF-8 -*-
# 文件IO

import os

# 删除”test”目录
os.rmdir( "test"  )

# print os.getcwd()
# os.chdir("F:\\web\\StudyTest\\PythonPro\\demo\\test")
# print os.getcwd()

# 创建目录test
# os.mkdir("test")

# 删除一个已经存在的文件test2.txt
# os.remove("test2.txt")

# # 重命名文件test1.txt到test2.txt。
# os.rename( "foo.txt", "test2.txt" )

# 打开一个文件
# fo = open("foo.txt", "rb")
# str = fo.read(12);
# print "读取的字符串是 : ", str
#
# # 查找当前位置
# position = fo.tell();
# print "当前文件位置 : ", position
#
# # 把指针再次重新定位到文件开头
# position = fo.seek(2, 1);
# str = fo.read(10);
# print "重新读取字符串 : ", str
# # 关闭打开的文件
# fo.close()

# 打开一个文件
# fo = open("foo.txt", "r+")
# str = fo.read(10);
# print "读取的字符串是 : ", str
# # 关闭打开的文件
# fo.close()

# 打开一个文件
# fo = open("foo.txt", "wb")
# fo.write( "www.runoob.com!\nVery good site!\n");
#
# # 关闭打开的文件
# fo.close()

# 打开一个文件
# fo = open("foo.txt", "wb")
# print "文件名: ", fo.name
#
# # 关闭打开的文件
# fo.close()
# print "文件名: ", fo.name

# 打开一个文件
# fo = open("foo.txt", "wb")
# print "文件名: ", fo.name
# print "是否已关闭 : ", fo.closed
# print "访问模式 : ", fo.mode
# print "末尾是否强制加空格 : ", fo.softspace

# str = input("请输入：");
# print "你输入的内容是: ", str

# str = raw_input("please input: ");
# print "your input: ", str
