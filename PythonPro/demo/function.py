#coding=utf-8
#函数

total = 0; # 这是一个全局变量
# 可写函数说明
def sum( arg1, arg2 ):
   #返回2个参数的和."
   total = arg1 + arg2; # total在这里是局部变量.
   print "函数内是局部变量 : ", total
   return total;

#调用sum函数
sum( 10, 20 );
print "函数外是全局变量 : ", total

# 可写函数说明
# def sum( arg1, arg2 ):
#    # 返回2个参数的和."
#    total = arg1 + arg2
#    print "函数内 : ", total
#    return total;
#
# # 调用sum函数
# total = sum( 10, 20 );
# print total;

# 可写函数说明
# sum = lambda arg1, arg2: arg1 + arg2;
#
# # 调用sum函数
# print "相加后的值为 : ", sum( 10, 20 )
# print "相加后的值为 : ", sum( 20, 20 )

# 可写函数说明
# def printinfo( arg1, *vartuple ):
#    "打印任何传入的参数"
#    print "输出: "
#    # print arg1
#    for var in vartuple:
#       print var
#    return;
#
# # 调用printinfo 函数
# printinfo( 10 );
# printinfo( 70, 60, 50 );

#可写函数说明
# def printinfo( name, age = 35 ):
#    "打印任何传入的字符串"
#    print "Name: ", name;
#    print "Age ", age;
#    return;
#
# #调用printinfo函数
# printinfo( age=50, name="miki" );
# printinfo( name="miki" );

#可写函数说明
# def printinfo( name, age ):
#    "打印任何传入的字符串"
#    print "Name: ", name;
#    print "Age ", age;
#    return;
#
# #调用printinfo函数
# printinfo( age=50, name="miki" );

#可写函数说明
# def printme( str ):
#    "打印任何传入的字符串"
#    print str;
#    return;
#
# #调用printme函数
# printme( str = "My string");

#可写函数说明
# def printme( str ):
#    "打印任何传入的字符串"
#    print str;
#    return;
#
# #调用printme函数
# a = "aaa"
# printme(a);
# printme();

# 可写函数说明
# def changeme( mylist ):
#    "修改传入的列表"
#    mylist.append([1,2,3,4]);
#    print "函数内取值: ", mylist
#    return
#
# # 调用changeme函数
# mylist = [10,20,30];
# changeme( mylist );
# print "函数外取值: ", mylist

# def ChangeInt( a ):
#     a = 10
#
# b = 2
# ChangeInt(b)
# print b # 结果是 2

# 定义函数
# def printme( str ):
#    "打印任何传入的字符串"
#    print str;
#    return;
#
# # 调用函数
# printme("xx!");
# printme("xxxxxx");
