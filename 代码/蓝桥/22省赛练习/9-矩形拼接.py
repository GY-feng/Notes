t=int(input())
def panduan4(a1,b1,a2,b2,a3,b3):
    # 4边:三边都相等or两边相加等于另一边，两边的另一边相等
    for i in [a1,b1]:
        for j in [a2,b2]:
            for k in[a3,b3]:
                if i==k==j:
                    return True
                if i == j and a1+b1+a2+b2-i-j==k:
                    return True
                if i==k and a1+b1+a3+b3-i-k==j:
                    return True
                if k==j and a3+b3+a2+b2-k-j==i:
                    return True
    return False

def panduan6(a,b,c,d,e,f):
    # 6边:有两边加起来等于另一边or任意两边相等
    for i in [a,b]:
        for j in [c,d]:
            for k in [e,f]:
                if i==j or i==k or j==k:
                    return 1
                if i+j==k or i+k==j or j+k==i:
                    return 1
    return 0
    pass

def al(a1,b1,a2,b2,a3,b3):
    # 4边:三边都相等or两边相加等于另一边，两边的另一边相等
    # 6边:有两边加起来等于另一边or任意两边相等8边:其他
    if panduan4(a1,b1,a2,b2,a3,b3):
        print("4")
        pass
    else:
        if panduan6(a1,b1,a2,b2,a3,b3):
            print("6")
            pass
        else:
            print("8")

# 如果是a1=a2=a3的话，那么结果必然就是4
for i in range(t):
    a1,b1,a2,b2,a3,b3=map(int,input().split())
    al(a1,b1,a2,b2,a3,b3)



