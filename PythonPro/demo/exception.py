# -*- coding: UTF-8 -*-
# 异常

class Networkerror(RuntimeError):
    def __init__(self, arg):
        self.args = arg

try:
    raise Networkerror("Bad hostname")
except Networkerror,e:
    print e.args
    
# 定义函数
# def mye( level ):
#     if level < 1:
#         raise Exception("Invalid level!", level)
#         # 触发异常后，后面的代码就不会再执行
#
# try:
#     mye(0)                // 触发异常
# except "Invalid level!":
#     print 1
# else:
#     print 2

# 定义函数
# def temp_convert(var):
#     try:
#         return int(var)
#     except ValueError, Argument:
#         print "no number\n", Argument
#
# # 调用函数
# temp_convert("xyz");

# try:
#     fh = open("testfile", "r")
#     try:
#         fh.write("这是一个测试文件，用于测试异常!!")
#     finally:
#         print "close"
#         fh.close()
# except IOError:
#     print "Error"

# try:
#     fh = open("testfile", "w")
#     fh.write("这是一个测试文件，用于测试异常!!")
# finally:
#     print "Error"

# try:
#     fh = open("testfile", "r")
#     fh.write("这是一个测试文件，用于测试异常!!")
# except IOError:
#     print "Error"
# else:
#     print "ok"
#     fh.close()

# try:
#     fh = open("testfile", "w")
#     fh.write("这是一个测试文件，用于测试异常!!")
# except IOError:
#     print "Error: 没有找到文件或读取文件失败"
# else:
#     print "内容写入文件成功"
#     fh.close()
