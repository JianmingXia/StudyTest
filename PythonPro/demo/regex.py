# -*- coding: UTF-8 -*-
# 正则表达式

import re

# 将匹配的数字乘于 2
def double(matched):
    value = int(matched.group('value'))
    return str(value * 2)

s = 'A23G4HFD567'
print(re.sub('(?P<value>\d+)', double, s))

# phone = "2004-959-559 # 这是一个国外电话号码"
#
# # 删除字符串中的 Python注释
# num = re.sub(r'#.*$', "", phone)
# print ("电话号码是: ", num)
#
# # 删除非数字(-)的字符串
# num = re.sub(r'\D', "", phone)
# print ("电话号码是 : ", num)

# line = "Cats are smarter than dogs";
#
# matchObj = re.match( r'dogs', line, re.M|re.I)
# if matchObj:
#    print ("match --> matchObj.group() : ", matchObj.group())
# else:
#    print ("No match!!")
#
# matchObj = re.search( r'dogs', line, re.M|re.I)
# if matchObj:
#    print ("search --> matchObj.group() : ", matchObj.group())
# else:
#    print ("No match!!")

# line = "Cats are smarter than dogs";
#
# searchObj = re.search( r'(.*) are (.*?) .*', line, re.M|re.I)
#
# if searchObj:
#    print ("searchObj.group() : ", searchObj.group())
#    print ("searchObj.group(1) : ", searchObj.group(1))
#    print ("searchObj.group(2) : ", searchObj.group(2))
# else:
#    print ("Nothing found!!")

# print(re.search('www', 'www.runoob.com').span())  # 在起始位置匹配
# print(re.search('com', 'www.runoob.com').span())         # 不在起始位置匹配

# line = "Cats are smarter than dogs"
#
# matchObj = re.match( r'(.*) are (.*?) .*', line, re.M|re.I)
#
# if matchObj:
#    print ("matchObj.group() : ", matchObj.group())
#    print ("matchObj.group(1) : ", matchObj.group(1))
#    print ("matchObj.group(2) : ", matchObj.group(2))
# else:
#    print ("No match!!")

# print(re.match('www', 'www.runoob.www.com').span())  # 在起始位置匹配
# print(re.match('com', 'www.runoob.com'))         # 不在起始位置匹配
