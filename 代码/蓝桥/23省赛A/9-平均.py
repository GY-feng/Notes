import os
import sys
from collections import defaultdict

n=int(input())
time=n//10 # 每个数字需要出现的次数
# l=[[]]*10# 如果您希望创建一个包含 10 个独立的空列表的列表，您应该避免使用乘法操作符 *，因为它会创建包含对相同空列表对象的引用的列表。
l=[[]for i in range(10)]
#print("time:",time)
for i in range(n):
    a,b=map(int,input().split())
    l[a].append(b)
    pass


# 列表 l 将会按照每个子列表的第一个元素 a 的升序进行排序。如果有多个子列表的第一个元素相同，则会按照第二个元素 b 的升序进行排序。
s=0
for i in range(10):
    ls=sorted(l[i])
    s+=sum(ls[:-time])
# 除了最后 time 个元素之外的所有元素的和添加到总和 s
print(s)








