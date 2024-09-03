def R1(n,m):
    if n>=m:
        return n%m
    else:
        return m%n
def R3(array):
    n = len(array)
    for i in range(n):
        # 标记是否发生了交换
        swapped = False
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                # 交换相邻的元素
                array[j], array[j + 1] = array[j + 1], array[j]
                swapped = True
        # 如果没有交换，数组已经排好序
        if not swapped:
            break
    return (array[0],array[n-1])
def C114(arr):
    length=len(arr)
    for i in range(length):
        a=arr[i]
        for k in range(i+1,length):
            b=arr[k]
            if is_even(i,k):
                return True
    return False# 没有找到那就没有咯
def is_even(a,b):
    return (a*b)%2#余数是1=TRUE，余数是0=False
def C115(arr):
    arr=R3(arr)
    for i in range(len(arr)-1,0,-1):
        if arr[i]-arr[i-1]==0:#有相同的元素
            return False
    return True
def C118():
    arr=[0, 2, 6, 12, 20, 30, 42, 56, 72, 90]
    return [x for x in arr]

