#判断一个数是否是质数：
def iszhi(n):
    if n<=1:
        return 0
    elif n<=3:
        return 1
    elif n%2==0 or n%3==0:
        return 0
    i=5
    while i*i<=n:
        if n%i==0 or n%(i+2)==0:
            return 0
        i+=6
    return 1
# 求逆元：
def mod_inverse(a, m):
    return pow(a, -1, m)

# 示例用法
a = 5
m = 11
inverse = mod_inverse(a, m)
print(f"The multiplicative inverse of {a} modulo {m} is: {inverse}")

# 全排列：
from itertools import permutations

# 定义列表
my_list = [1, 2, 3]
# 获取全排列
permutations_list = list(permutations(my_list))
# 打印结果
print("全排列列表：", permutations_list)



