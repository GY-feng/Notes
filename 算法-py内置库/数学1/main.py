#当前项向右找第一个比自己大的位置 —— 从左向右维护一个单调递减栈。

def nextGreaterElement_011(nums: list):
    length = len(nums)
    res, stack = [-1] * length, []

    for i in range(length):
        while stack and nums[stack[-1]] < nums[i]:# 栈顶的元素小于遍历到的元素
            idx = stack.pop() #栈顶元素的索引
            res[idx] = nums[i]
        stack.append(i)

    return res

l=[1,3,5,7,9,11,13,99,12]
print(nextGreaterElement_011(l))
