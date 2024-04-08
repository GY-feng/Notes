import os
import sys
n,x=map(int,input().split())
s=input()
s=sorted(s)

if s[x-1]!=s[0]:# 分配给最后一人的糖果价值>第一人的价值
    print(s[x-1])
    pass
else:# 每个人拿到的开始的相同
    if s[x]==s[-1]:# 后面剩余的糖果一样
        print(s[x-1],end='')
        for i in range(x,n,x):
            print(s[i],end='')
    else:
        for i in s[x-1:]:# s的第x个元素开始，迭代到列表末尾
            print(i,end='') # end=''输出完i后不换行

