# R-5.1 Execute the experiment from Code Fragment 5.1 and compare the results on your system to those we report in Code Fragment 5.2 
# 
# 
# R-5.3 Modify the following code in order to demonstrate that Python’s list class occasionally shrinks the size of its underlying array when elements are popped from a list.
'''
ANSWER:
import sys # provides getsizeof function
data = [1,2,3,4,5,6 ]
n = 100
for k in range(n):
    data.pop()  # 从列表中移除最后一个元素
    a = len(data)  # 更新元素数量
    b = sys.getsizeof(data)  # 更新实际字节大小
    print("Length after pop: {0:3d}; Size in bytes: {1:4d}".format(a, b))
'''
# C-5.14 The shuffle method, supported by the random module, takes a Python list and rearranges it so that every possible ordering is equally likely. Implement your own version of such a function. You may rely on the randrange(n) function of the random module, which returns a random number between 0 and n−1 inclusive. 
# C-5.14 random 模块支持的 shuffle 方法采用 Python 列表并重新排列它，以便每个可能的排序可能性相等。实现您自己的此类函数版本。您可以依赖 random 模块的 randrange（n） 函数，该函数返回一个介于 0 和 n−1 之间（包括 0 和 n−1）的随机数。
import random
def reshuffle(l):
    n=len(l)
    for i in range(n-1,0,-1):#由后向前，避免索引前几轮可能是无效的
        # 生成随机索引：
        k=random.randrange(0,i+1)# 左闭右开的区间
        l[i],l[k]=l[k],l[i]
    pass
data=[1,2,3,4,5]
print(reshuffle(data))
# 
# C-5.16 Implement a pop method for the DynamicArray class, given in Code Fragment 5.3, that removes the last element of the array, 
# and that shrinks the capacity, N, of the array by half any time the number of elements in the array goes below N/4

# C-5.16 为代码片段 5.3 中给出的 DynamicArray 类实现一个 pop 方法，该方法删除数组的最后一个元素，并在数组中的元素数量低于 N/4 时将数组的容量 N 缩小一半
'''
C-5.16 为代码片段 5.3 中给出的 DynamicArray 类实现一个 pop 方法，该方法删除数组的最后一个元素，
并在数组中的元素数量低于 N/4 时将数组的容量 N 缩小一半
'''