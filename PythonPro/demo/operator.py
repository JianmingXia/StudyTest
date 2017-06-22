#coding=utf-8
#运算符

a = 10
b = 20
list = [1, 2, 3, 4, 5 ];

if ( a in list ):
   print "1 - 变量 a 在给定的列表中 list 中"
else:
   print "1 - 变量 a 不在给定的列表中 list 中"

if ( b not in list ):
   print "2 - 变量 b 不在给定的列表中 list 中"
else:
   print "2 - 变量 b 在给定的列表中 list 中"

# 修改变量 a 的值
a = 2
if ( a in list ):
   print "3 - 变量 a 在给定的列表中 list 中"
else:
   print "3 - 变量 a 不在给定的列表中 list 中"
   
# a = 10
# b = 20
#
# if ( a and b ):
#    print "1 - 变量 a 和 b 都为 true"
# else:
#    print "1 - 变量 a 和 b 有一个不为 true"
#
# if ( a or b ):
#    print "2 - 变量 a 和 b 都为 true，或其中一个变量为 true"
# else:
#    print "2 - 变量 a 和 b 都不为 true"
#
# # 修改变量 a 的值
# a = 0
# if ( a and b ):
#    print "3 - 变量 a 和 b 都为 true"
# else:
#    print "3 - 变量 a 和 b 有一个不为 true"
#
# if ( a or b ):
#    print "4 - 变量 a 和 b 都为 true，或其中一个变量为 true"
# else:
#    print "4 - 变量 a 和 b 都不为 true"
#
# if not( a and b ):
#    print "5 - 变量 a 和 b 都为 false，或其中一个变量为 false"
# else:
#    print "5 - 变量 a 和 b 都为 true"

# a = 60            # 60 = 0011 1100
# b = 13            # 13 = 0000 1101
# c = 0
#
# c = a & b;        # 12 = 0000 1100
# print "1 - c =", c
#
# c = a | b;        # 61 = 0011 1101
# print "2 - c =", c
#
# c = a ^ b;        # 49 = 0011 0001
# print "3 - c =", c
#
# c = ~a;           # -61 = 1100 0011
# print "4 - c =", c
#
# c = a << 2;       # 240 = 1111 0000
# print "5 - c =", c
#
# c = a >> 2;       # 15 = 0000 1111
# print "6 - c =", c

# a = 21
# b = 10
# c = 0
#
# c = a + b
# print "1 - c =", c
#
# c += a
# print "2 - c =", c
#
# c *= a
# print "3 - c =", c
#
# c /= a
# print "4 - c =", c
#
# c = 2
# c %= a
# print "5 - c =", c
#
# c **= a
# print "6 - c =", c
#
# c //= a
# print "7 - c =", c

# a = 21
# b = 10
# c = 0
#
# if ( a == b ):
#    print "1 - a 等于 b"
# else:
#    print "1 - a 不等于 b"
#
# if ( a != b ):
#    print "2 - a 不等于 b"
# else:
#    print "2 - a 等于 b"
#
# if ( a <> b ):
#    print "3 - a 不等于 b"
# else:
#    print "3 - a 等于 b"
#
# if ( a < b ):
#    print "4 - a 小于 b"
# else:
#    print "4 - a 大于等于 b"
#
# if ( a > b ):
#    print "5 - a 大于 b"
# else:
#    print "5 - a 小于等于 b"
#
# # 修改变量 a 和 b 的值
# a = 5;
# b = 20;
# if ( a <= b ):
#    print "6 - a 小于等于 b"
# else:
#    print "6 - a 大于  b"
#
# if ( b >= a ):
#    print "7 - b 大于等于 a"
# else:
#    print "7 - b 小于 a"

# a = 22.0
# b = 10
# c = 0
#
# c = a + b
# print "a + b =", c
#
# c = a - b
# print "a - b =", c
#
# c = a * b
# print "a * b =", c
#
# c = a / b
# print "a / b =", c
#
# c = a % b
# print "a % b =", c
#
# # 修改变量 a 、b 、c
# a = 2
# b = 3
# c = a**b
# print "a**b =", c
#
# a = 11
# b = 5
# c = a//b
# print "a//b =", c
