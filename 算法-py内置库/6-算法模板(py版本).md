# 深度搜索基本模板DFS：
```python
def search(t):
    if 满足条件:
        输出解
    else:
        for i in range(尝试方法数):
            if 满足搜索条件:
                为进一步搜索需要的状态打上标记
                search(t+1)
                回复到打标记前的状态# 回溯一步
```
# 单调栈：
1，使用列表模拟栈的功能：
```python
# 创建一个空栈
stack = []
# 压栈操作（push）
stack.append(1)
stack.append(2)
stack.append(3)
# 获取栈顶元素（top）
top_element = stack[-1]
print("栈顶元素：", top_element)
# 出栈操作（pop）
popped_element = stack.pop()
print("出栈元素：", popped_element)
# 再次获取栈顶元素
top_element = stack[-1]
print("栈顶元素：", top_element)
```
2,单调栈：
```python
stack=[]#模拟栈的运行
nums=[]#某个数组
for i in nums:#遍历这个数组
    if(栈空||栈顶的元素大于等于当前比较的元素):
        入栈
    else:
        while(栈不为空&&栈顶的元素小于当前的元素):
            栈顶元素出栈
            更新结果
        当前数据入栈
```
```python
# 模拟栈的运行
stack = []  # 栈，存储元素索引
nums = [3, 1, 4, 2, 5]  # 某个数组

result = [-1] * len(nums)  # 存储结果，默认为-1

# 遍历这个数组
for i in range(len(nums)):
    # 如果栈为空或栈顶的元素大于等于当前比较的元素，则入栈当前元素索引
    if not stack or nums[stack[-1]] >= nums[i]:
        stack.append(i)
    else:
        # 如果栈不为空且栈顶的元素小于当前的元素，则栈顶元素出栈，更新结果
        while stack and nums[stack[-1]] < nums[i]:
            top = stack.pop()
            result[top] = nums[i]  # 更新结果为当前元素
        # 当前数据入栈
        stack.append(i)

# 输出结果
print("每个元素右边第一个比它大的元素为：", result)
```
# 二分答案：
单调性判别的问题：
另外的一种二分代码写法，不必考虑+1和-1的问题！：
只需要想清楚程序当中的答案是否需要更新（是否要记下ans)
并且要想清楚可能的答案在哪一册（改L还是R即可

使用二分条件技巧的条件：
1，命题可以归纳成为找到使得命题P(x)成立/不成立的最大/最小的x
2，将P(x)看做一个真或者假的函数，那么它一定在某个分界线的一侧全为真，另一侧全为假
3，可以找到一个复杂度优秀的算法检验P(x)的真假
```python
def Find(l,r):
    ans,mid=0,0
    while l<=r: # 闭区间上的二分条件
        mid=(l+r)//2 #py当中不能时使用>>优化
        if P(mid):# 条件成立
            ans=mid
            r=mid-1
            # 只需要记录满足条件的mid，最后循环一定会结束，也一定会在ans当中保留正确的答案
        else:
            l=mid+1 #L和R不用考虑+1和-1，全部写上去
    return ans
```
    