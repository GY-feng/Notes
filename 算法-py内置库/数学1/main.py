import math as m

# 求最大公约数
c = m.gcd(10, 100)
print(c)
# 求最小公倍数
lcm = (10 * 100) // c  # 最小公倍数可以通过两个数的乘积除以它们的最大公约数来获得。

# 埃氏筛
def num(n):
    
