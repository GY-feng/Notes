def Problem_A():
    num=0
    for i in range(10,100):
        a=i//10
        b=i%10
        if a==b:
            num+=1
    for i in range(1000,10000):
        a=i%10#得到最末尾数字
        i=i//10
        b=i%10#十位数字
        i=i//10
        c=i%10#百位数字
        d=i//10#千位数字
        if a+b==c+d:
            num+=1
    for i in range(100000,1000000):
        a = i % 10  # 得到最末尾数字
        i = i // 10
        b = i % 10  # 十位数字
        i = i // 10
        c = i % 10  # 百位数字
        i=i//10
        d=i%10# 千位
        i=i//10
        e=i%10#万位
        f=i//10#十万
        if a+b+c==d+e+f:
            num+=1
    for i in range(10000000,100000000):
        a = i % 10  # 得到最末尾数字
        i = i // 10
        b = i % 10  # 十位数字
        i = i // 10
        c = i % 10  # 百位数字
        i=i//10
        d=i%10# 千位
        i=i//10
        e=i%10#万位
        i=i//10
        f=i%10#十万
        i=i//10
        g=i%10#百万
        h=i//10#千万
        if a+b+c+d==e+f+g+h:
            num+=1
    return num
print(Problem_A())

