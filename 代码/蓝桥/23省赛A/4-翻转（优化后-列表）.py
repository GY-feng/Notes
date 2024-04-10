"""
要优化避免超时，您可以尝试以下方法：

减少字符串拼接操作： 在循环中避免多次执行字符串拼接操作，因为字符串是不可变的，每次拼接都会创建一个新的字符串对象。
取而代之的是，您可以使用列表来动态构建字符串，然后在循环结束时使用 join() 方法将它们连接起来。
使用更高效的数据结构： 考虑使用其他数据结构来存储和处理字符串，例如列表或数组，这样可以提高操作的效率。
避免不必要的函数调用： 您可以减少对 turn() 函数的调用次数，例如通过存储已计算过的结果来避免重复计算。
尽量避免使用递归： 递归在某些情况下可能导致栈溢出或超时，尤其是对于大量数据输入。

"""

import os
import sys

def turn(s):
    if s == "101":
        return "111"
    if s == "010":
        return "000"
    else:
        return "FUCK"

def al(s, t):
    length = len(s)
    ans = 0
    s = list(s)  # 将字符串转换为列表，以便后续操作
    if s[0] != t[0] or s[length - 1] != t[length - 1]:
        return "-1"
    else:
        for i in range(1, length):
            if s[i] != t[i]:
                str_tmp = s[i - 1:i + 2]  # 使用切片获取子字符串
                str_tmp = turn(''.join(str_tmp))  # 将子字符串转换为字符串后调用turn函数
                if str_tmp == "FUCK":
                    return "-1"
                else:
                    s[i - 1:i + 2] = str_tmp  # 将转换后的子字符串替换回原列表中
                    ans += 1
        return ans

n = int(input())
for i in range(n):
    t = input()
    s = input()
    print(al(s, t))
