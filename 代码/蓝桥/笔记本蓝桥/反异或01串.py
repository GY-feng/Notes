list1 = [0, 1, 1, 0, 1]
list2 = [1, 0, 1, 0, 0]

result = [a ^ b for a, b in zip(list1, list2)]

print("结果:", result)  # 输出结果为 [1, 1, 0, 0, 1]
