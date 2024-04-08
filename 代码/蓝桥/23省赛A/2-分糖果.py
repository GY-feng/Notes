import os
import sys

def dic(str1,str2):
    len_min=min(len(str1),len(str2))
    #逐个字符比较直到找到不同的地方：
    for i in range(len_min):
        if str1[i]!=str2[i]:
            return ord(str1[i])-ord(str2[i])
    #如果前面的字符都是相同的话，那么长度大的字符串字典序更大
    return len(str1)-len(str2)

n,x=map(int,input().split())
a=input()
a=sorted(a)
