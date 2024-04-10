from collections import defaultdict as d

n = int(input())
nums = list(map(int, input().split()))
m=d(int)

nn=[0]*100000
nn[1]=1
nn[2]=2
nn[3]=6
def jiecheng(a):
    if nn[a]:
        return nn[a]
    else:
        nn[a]=jiecheng(a-1)*a
        return nn[a]

# 将nums的值添加进m当中：
for i in nums:
    m[i]+=1
    pass
co=[]
# 尝试合并n+1个 n! 为(n+1)!
for i in m: #这里的i就是key了
    if m[i]==i+1:#value=key+1,有n+1个n可以合并
        co.append(jiecheng((m[i]+1)))

print(co)

