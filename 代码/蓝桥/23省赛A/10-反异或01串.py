# list1 = [0, 1, 1, 0, 1]
# list2 = [1, 0, 1, 0, 0]

def fanyihuo(list1):
    list2=reversed(list1)
    result = [a ^ b for a, b in zip(list1, list2)]
    # zip() 函数用于将多个可迭代对象（例如列表、元组等）中对应的元素打包成一个元组，并返回一个由这些元组组成的迭代器
    #print("结果:", result)  # 输出结果为 [1, 1, 0, 0, 1]
    return result

def zeroandone(x):# 接受一个字符串的参数
    a=0
    b=0
    for i in x:
        if i=='0':
            a+=1
        if i=='1':
            b+=1
    return a,b


t=input()
a,b=zeroandone(t) #a是0的个数，b是1的个数
min_one=b # 不操作，只添加下的值
print(a,b)
