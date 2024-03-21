# python基础知识的归纳
# 字符串与数字相乘，结果是字符串*
a='2.5mmmm'
b=2
print(a*b)

#切片：语法：序列[start:stop:step]
#range：左开右闭range(stop)/range(start,stop,step)，range返回的是一个类似序列的对象，而不是列表，但可以采用list()转化成列表
b=list(range(1,100,3))
#赋值语句，一行赋值多个值：
x,y,z=1,2,3

#三元操作符：
age=100
price=30 if age>=18 else 15
#某项是否在列表当中的判断
if 3 in b:
    print("3 is in b")
#字典：
c=dict({"availability":"online"})
#更新或者添加新值
c.update({"Hello":"World"})
#删除字典当中的值
del c["availability"]
print(c)
user={
    "id":1234,
    "age":24,
    "name":"91liu",
}
for key,value in user.items():
    print("key:",key)
#使用字典推导式来获得一个符合要求的新字典：
#dir={key:value for(key,value)in dict.items() if condition}
product_price={
    "appple":100,
    "bannana":30,
    "orange":60,
}
dir={product:price*0.6 for (product,price)in product_price.items()}
print(dir)
#list：
#insrt插入：表示在索引为1的地方插入元素4
l=[1,2,3,22,34,21]
l.insert(1,4)
# 字符串没有append方法，append是list的方法
l.append(99)
#列表的合并：
##添加列表：
r=[10,4,3]
l.extend(r)
##添加元组：
m=(12,122,32)
l.extend(m)
#删除元素：
l.remove(122)
del l[3]#依据下标索引来删除元素，del也可以删除掉整个列表（python将无法找到这个列表）
#l.clear()更温和的删除方法
#list找到最大值：
print(max(l))
#pop方法：
print(l.pop())
#数学运算：
#幂运算：**
print(10**2)
#//是取整，/是真正的除法
a=11.67//2
print(a)#10//-3=-4
#内置函数：
#len()返回对象的长度
a="AAAAxx"
a.capitalize()#第一个字母变成大写，其余小写
#排序函数：
l.sort(reverse=True)