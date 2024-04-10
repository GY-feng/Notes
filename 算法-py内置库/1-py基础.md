# py基础

# 基础知识-数字&字符串

## 三元操作符：

```py
age=100
price=30 if age>=18 else 15
```
## 赋值语句，一行赋值多个值：
x,y,z=1,2,3
## 字符串与数字相乘，结果是字符串*
```py
a='2.5mmmm'
b=2
print(a*b)
```
## 内置函数：
## len()返回对象的长度
```py
a="AAAAxx"
a.capitalize()#第一个字母变成大写，其余小写
```
## 排序函数：
l.sort(reverse=True)
## 可以有cmp，用法和C++差不多

# 切片
切片：语法：序列[start:stop:step]
range：左开右闭range(stop)/range(start,stop,step)，range返回的是一个类似序列的对象，而不是列表，但可以采用list()转化成列表
b=list(range(1,100,3))

# 列表list：
## 某项是否在列表当中的判断
``` py
if 3 in b:
    print("3 is in b")
```
## insrt插入：表示在索引为1的地方插入元素4
```py
l=[1,2,3,22,34,21]
l.insert(1,4)
```
## 字符串没有append方法，append是list的方法
l.append(99)
## 列表的合并：
## 添加列表：
```py
r=[10,4,3]
l.extend(r)
```
## 添加元组：
```py
m=(12,122,32)
l.extend(m)
```
## 删除元素：
```py
l.remove(122)
del l[3] ## 依据下标索引来删除元素，del也可以删除掉整个列表（python将无法找到这个列表）
```
## l.clear()更温和的删除方法
## 2.list找到最大值：
print(max(l))
## pop方法：
print(l.pop())

## 交换位置：
## 最大/小值：max(list)
## 列表的删除，不必采用下标，直接删除元素就可以了
```py
l=['r','p','g','ff','i','j','k','l']
l.remove('ff')
```
#如果要根据索引删除的话，采用下面的方法：
```py
del l[2]
print(l)
```
#pop函数：弹出最后一个（默认）
#也可以弹出指定的元素：
l.pop(2)
#清空列表：
l.clear()

# 字典：
```py
c=dict({"availability":"online"})
```
## 更新或者添加新值
```py
c.update({"Hello":"World"})
```

## 删除字典当中的值
```py
del c["availability"]
print(c)
user={
    "id":1234,
    "age":24,
    "name":"91liu",
}
for key,value in user.items():
    print("key:",key)
```
## 使用字典推导式来获得一个符合要求的新字典：
## dir={key:value for(key,value)in dict.items() if condition}
```py
product_price={
    "appple":100,
    "bannana":30,
    "orange":60,
}
dir={product:price*0.6 for (product,price)in product_price.items()}
print(dir)
```
# 数学：
## 数学运算：
## 幂运算：
```py
print(10**2)
```
//是取整，/是真正的除法
```py
a=11.67//2
print(a)#10//-3=-4
```