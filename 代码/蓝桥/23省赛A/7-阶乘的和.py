n = int(input())
nums = list(map(int, input().split()))

# 计算阶乘并存储在字典中
factorials = {0: 1, 1: 1, 2: 2, 3: 6}
def jiecheng(a):
    if a in factorials:
        return factorials[a]
    else:
        result = jiecheng(a - 1) * a
        factorials[a] = result
        return result

# 计算总和
total_sum = sum(jiecheng(num) for num in nums)

# 寻找满足条件的值
for i in range(total_sum, 0, -1):
    m_jiecheng = jiecheng(i)
    if total_sum % m_jiecheng == 0:  # 如果m的阶乘是sum的因数的话
        print(i)
        break

