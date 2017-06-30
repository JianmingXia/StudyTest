# -*- coding: UTF-8 -*-
# 面向对象

class JustCounter:
    __secretCount = 0  # 私有变量
    publicCount = 0    # 公开变量
    def count(self):
        self.__secretCount += 1
        self.publicCount += 1
        print self.__secretCount
    def printCount(self):
        print self.__secretCount

counter = JustCounter()
counter.count()
# 在类的对象生成后,调用含有类私有属性的函数时就可以使用到私有属性.
counter.count()
#第二次同样可以.
print counter.publicCount
print counter._JustCounter__secretCount  # 不改写报错，实例不能访问私有变量
try:
    #counter.printCount()
    print counter.__secretCount
except IOError:
    print "不能调用非公有属性!"
else:
    print "ok!" #现在呢!证明是滴!

# class JustCounter:
#     __secretCount = 0  # 私有变量
#     publicCount = 0    # 公开变量
#
#     def count(self):
#         self.__secretCount += 1
#         self.publicCount += 1
#         print self.__secretCount
#
# counter = JustCounter()
# counter.count()
# counter.count()
# print counter.publicCount
# # print counter.__secretCount  # 报错，实例不能访问私有变量
# print counter._JustCounter__secretCount

# class Vector:
#    def __init__(self, a, b):
#       self.a = a
#       self.b = b
#
#    def __str__(self):
#       return 'Vector (%d, %d)' % (self.a, self.b)
#
#    def __add__(self,other):
#       return Vector(self.a + other.a, self.b + other.b)
#
# v1 = Vector(2,10)
# v2 = Vector(5,-2)
# print v1 + v2

# class Parent:        # 定义父类
#    def myMethod(self):
#       print 'parent'
#
# class Child(Parent): # 定义子类
#    def myMethod(self):
#       print 'child'
#
# c = Child()          # 子类实例
# c.myMethod()         # 子类调用重写方法

# class Parent:        # 定义父类
#    parentAttr = 100
#    def __init__(self):
#       print "parent init"
#
#    def parentMethod(self):
#       print 'parentMethod'
#
#    def setAttr(self, attr):
#       Parent.parentAttr = attr
#
#    def getAttr(self):
#       print "parentAttr :", Parent.parentAttr
#
# class Child(Parent): # 定义子类
#    def __init__(self):
#       print "child init"
#
#    def childMethod(self):
#       print 'childMethod child method'
#
# c = Child()          # 实例化子类
# c.childMethod()      # 调用子类的方法
# c.parentMethod()     # 调用父类方法
# c.setAttr(200)       # 再次调用父类的方法
# c.getAttr()          # 再次调用父类的方法

# class Point:
#    def __init__( self, x=0, y=0):
#       self.x = x
#       self.y = y
#    def __del__(self):
#       class_name = self.__class__.__name__
#       print class_name, "销毁"
#
# pt1 = Point()
# pt2 = pt1
# pt3 = pt1
# print id(pt1), id(pt2), id(pt3) # 打印对象的id
# del pt1
# del pt2
# del pt3

# class Employee:
#    '所有员工的基类'
#    empCount = 0
#
#    def __init__(self, name, salary):
#       self.name = name
#       self.salary = salary
#       Employee.empCount += 1
#
#    def displayCount(self):
#      print "Total Employee %d" % Employee.empCount
#
#    def displayEmployee(self):
#       print "Name : ", self.name,  ", Salary: ", self.salary
#
# print "Employee.__doc__:", Employee.__doc__
# print "Employee.__name__:", Employee.__name__
# print "Employee.__module__:", Employee.__module__
# print "Employee.__bases__:", Employee.__bases__
# print "Employee.__dict__:", Employee.__dict__

# class Employee:
#    '所有员工的基类'
#    empCount = 0
#
#    def __init__(self, name, salary):
#       self.name = name
#       self.salary = salary
#       Employee.empCount += 1
#
#    def displayCount(self):
#      print "Total Employee %d" % Employee.empCount
#
#    def displayEmployee(self):
#       print "Name : ", self.name,  ", Salary: ", self.salary
#
# "创建 Employee 类的第一个对象"
# emp1 = Employee("Zara", 2000)
# "创建 Employee 类的第二个对象"
# emp2 = Employee("Manni", 5000)
# emp1.displayEmployee()
# emp2.displayEmployee()
# print "Total Employee %d" % Employee.empCount
#
# print "emp2 Name : ", emp2.name,  ", Salary: ", emp2.salary

# class Test:
#     def prt(runoob):
#         print(runoob)
#         print(runoob.__class__)
#
# t = Test()
# t.prt()

# class Test:
#     def prt(self):
#         print(self)
#         print(self.__class__)
#
# t = Test()
# t.prt()

# class Employee:
#    '所有员工的基类'
#    empCount = 0
#
#    def __init__(self, name, salary):
#       self.name = name
#       self.salary = salary
#       Employee.empCount += 1
#
#    def displayCount(self):
#      print "Total Employee %d" % Employee.empCount
#
#    def displayEmployee(self):
#       print "Name : ", self.name,  ", Salary: ", self.salary
