n=int(input())
ll=list(map(int,input().split()))
print(ll)
l=[0]
l.extend(ll)
#print(l)
m=int(input())
bianjie=[[]for i in range(m)]
for i in range(m):
    left,right=map(int,input().split())
    bianjie[i]=[left,right]
    pass

chuxia=[0]*(n+2) # 这个数字用于记录某个点被扫描过的次数
chuxian=[0]
chuxian.extend(chuxia)

newl=[0]*(n+1) #排序之后的列表
# 计算不操作下的范围内的值,记录某个点出现的次数：
yuan_ans=0
print(l)
for k in bianjie:
    left=k[0]
    right=k[1]
    for i in range(left,right+1):
        yuan_ans += l[i]
        chuxian[i]+=1
    pass
#print("出现列表：",chuxian)
# 重新排序列表
for i in range(n):
    #print("第",i,"次循环")
    max_chuxian=(max(chuxian))
    max_chuxian_index=chuxian.index(max_chuxian)# 找到出现次数最多的那个点的下标
    chuxian[max_chuxian_index]=0
    #print("出现次数最多的那个点的下标:",max_chuxian_index)
    #print("出现的列表")
    max_value=max(l) #获得列表当中的最大值
    #print("当前列表的最大值",max_value)
    max_value_index=l.index(max_value)# 找到列表最大值所对应的下标
    #print("最大值所对应的下标:",max_value_index)
    newl[max_chuxian_index]=max_value
    #print("新的列表：",newl)
    l[max_value_index]=0
    #print("旧的列表",l)
    #print()
    pass
after_ans=0
for k in bianjie:
    left=k[0]
    right=k[1]
    for i in range(left,right+1):
        after_ans += newl[i]
    pass

print(newl)
print(yuan_ans)
print(bianjie)
print(after_ans)
"""
实际上这道题可以采用dp/前缀和代码进行优化
dp优化略
前缀和优化：
基于排序和前缀和的优化思路：

首先，对原始列表进行排序，以便后续操作。
然后，计算原始列表和排序后列表的前缀和数组，以便快速计算任意区间的和。
对于每个区间，找到其中出现次数最多的元素，并将其与最大值进行交换。
最后，计算交换后的列表与原始列表之间的差值，即为结果。
这种方法的时间复杂度取决于排序的时间复杂度，通常为O(n log n)，适用于中等规模的输入
"""