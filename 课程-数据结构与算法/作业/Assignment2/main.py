# C-5.14 The shuffle method, supported by the random module, takes a Python list and
# rearranges it so that every possible ordering is equally likely. Implement your own
# version of such a function. You may rely on the randrange(n) function of the random
# module, which returns a random number between 0 and n−1 inclusive.
# C-5.14 随机模块支持的 shuffle 方法接受一个 Python 列表，并重新排列其元素，使得每种可能的顺序都是同样可能的。实现你自己的该函数版本。你可以依赖随机模块的 randrange(n) 函数，该函数返回一个介于 0 到 n−1（包含）之间的随机数。
#
import random
def reshuffle(l):
    n=len(l)
    for i in range(n-1,0,-1):#由后向前，避免索引前几轮可能是无效的
        # 生成随机索引：
        k=random.randrange(0,i+1)# 左闭右开的区间
        l[i],l[k]=l[k],l[i]
    return l
    pass

# TEST：
data=[1,2,3,4,5]
print(reshuffle(data))


# C-5.16 Implement a pop method for the DynamicArray class, given in Code Fragment
# 5.3, that removes the last element of the array, and that shrinks the capacity, N, of the
# array by half any time the number of elements in the array goes below N/4
# C-5.16 实现一个 pop 方法，用于动态数组类（DynamicArray），该类在代码片段 5.3 中给出，能够移除数组的最后一个元素，并在数组中元素数量低于 N/4 时将数组的容量 N 减半。


'''

#找不到代码片段5.3啊，DynamicArray类的init,len,str,getitem,append函数的代码网上找的，_resize和pop我自己写的啊

'''

class DynamicArray:
    def __init__(self):
        self._capacity = 1  # 初始容量
        self._size = 0      # 当前元素数量
        self._array = [None] * self._capacity  # 初始化数组

    def __len__(self):
        return self._size  # 返回当前大小

    def __getitem__(self, index):
        if index < 0 or index >= self._size:
            raise IndexError("Index out of bounds")
        return self._array[index]
    def __str__(self):
        return "[" + ", ".join(str(self._array[i]) for i in range(self._size)) + "]"+ " 数组容量：" + str(self._capacity) + " 数组长度：" + str(self._size)

    def append(self, value):
        if self._size == self._capacity:
            self._resize(2 * self._capacity)  # 增加容量
        self._array[self._size] = value
        self._size += 1
    def _resize(self,cap):
        n_arr=[None]*cap
        for i in range(self._size):
            n_arr[i]=self._array[i]
        self._array=n_arr
        self._capacity=cap
    def pop(self):
        if self._array[self._size-1]!=None:# 最后一个元素不为空
            self._array[self._size-1]=None#弹出
            self._size=self._size-1#减去长度
            pass
        if self._size<=self._capacity//4:#小于N//4
            self._resize(self._capacity//2)


# TEST:
darr=DynamicArray()# 初始化一个动态数组
for i in range(10):
    darr.append(i)
    pass
print(darr)# 输出原始的da
for i in range(3):
    darr.pop()
    print(darr)
    pass


# C-5.25 The syntax data.remove(value) for Python list data removes only the first
# occurrence of element value from the list. Give an implementation of a function, with
# signature remove all(data, value), that removes all occurrences of value from the
# given list, such that the worst-case running time of the function is O(n) on a list with n
# elements. Not that it is not efficient enough in general to rely on repeated calls to
# remove.
#
# C-5.25 Python 列表的语法 data.remove(value) 仅移除列表中元素 value 的第一次出现。给出一个函数的实现，签名为 remove_all(data, value)，该函数能够移除给定列表中所有 value 的出现，使得该函数在包含 n 个元素的列表上的最坏情况下运行时间为 O(n)。注意，仅依赖于重复调用 remove 通常效率不高。
#

def remove_all(data,value):
    n_data=[]
    for i in data:
        if i!=value:
            n_data.append(i)
            pass
    return n_data
 # TEST:
data=[1,1,1,2,3,4,5,7]
print(remove_all(data,1))



# R-7.2 Describe a good algorithm for concatenating two singly linked lists L and M,
# given only references to the first node of each list, into a single list L' that contains all
# the nodes of L followed by all the nodes of M.
# R-7.2 描述一个好的算法，用于将两个单向链表 L 和 M 连接起来，仅使用对每个链表第一个节点的引用，生成一个新的链表 L'，该链表包含所有 L 的节点，后面跟着所有 M 的节点。
class Node:
    def __init__(self,value,next=None):
        self.next=next
        self.value=value
        pass
def find_last(l:Node):
    if l.next==None:
        return l
    else:
        return find_last(l.next)
        
def connect(L,M):
    node=find_last(L)
    node.next=M
    return L

# R-7.5 Implement a function that counts the number of nodes in a circularly linked list
#
# R-7.5 实现一个函数，用于计算循环链表中的节点数量。
def getnum(l:Node):
    if l==None:
        return 0
    num=1
    node=l# node记录的就是开始的节点
    while l.next!=node:
        num+=1
        l=l.next
        pass
    return num
