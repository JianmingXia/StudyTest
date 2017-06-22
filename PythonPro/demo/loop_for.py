#coding=utf-8
#循环语句

# 输出 Python 的每个字母
for letter in 'Python':
   if letter == 'h':
      pass
      print '这是 pass 块'
   print '当前字母 :', letter

print "Good bye!"

# for letter in 'Python':     # 第一个实例
#    if letter == 'h':
#       continue
#    print '当前字母 :', letter
#
# var = 10                    # 第二个实例
# while var > 0:
#    var = var -1
#    if var == 5:
#       continue
#    print '当前变量值 :', var
# print "Good bye!"

# for letter in 'Python':     # 第一个实例
#    if letter == 'h':
#       break
#    print '当期字母 :', letter
#
# var = 10                    # 第二个实例
# while var > 0:
#    print '当期变量值 :', var
#    var = var -1
#    if var == 5:   # 当变量 var 等于 5 时退出循环
#       break
#
# print "Good bye!"

# i = 2
# while(i < 100):
#    j = 2
#    while(j <= (i/j)):
#       if not(i%j): break
#       j = j + 1
#    if (j > i/j) : print i, " 是素数"
#    i = i + 1
#
# print "Good bye!"

# for num in range(10,20):  # 迭代 10 到 20 之间的数字
#    for i in range(2,num): # 根据因子迭代
#       if num%i == 0:      # 确定第一个因子
#          j=num/i          # 计算第二个因子
#          print '%d 等于 %d * %d' % (num,i,j)
#          break            # 跳出当前循环
#    else:                  # 循环的 else 部分
#       print num, '是一个质数'

# fruits = ['banana', 'apple',  'mango']
# for index in range(len(fruits)):
#    print 'index :', index, fruits[index]
#
# print "Good bye!"

# for letter in 'Python':     # 第一个实例
#    print '当前字母 :', letter
#
# fruits = ['banana', 'apple',  'mango']
# for fruit in fruits:        # 第二个实例
#    print '当前水果 :', fruit
#
# print "Good bye!"
