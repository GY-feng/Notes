import os
import sys
n,x=map(int,input().split())
s=input()
s=sorted(s)
str_l=[""]*x
init=0
for i in s:
    if init==x:
        init=0
        pass
    # 不能采用append，而应该采用+=，因为初始化的时候这是一个空的列表
    # str_l[init].append(i)
    str_l[init]+=i
    init+=1
    pass
print(str_l)

