n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
# 计算每个国家在经历了n个事件之后剩余的兵力
winA=[A[i]-B[i]-C[i] for i in range(n)]
winB=[B[i]-A[i]-C[i] for i in range(n)]
winC=[C[i]-B[i]-A[i] for i in range(n)]
# 比如发生了X个事件之后魏国获胜，那么要求的就是X的最大值
# 再比如Y个事件之后吴国获胜，那么要求Y的最大值
# Z个事件之后蜀国获胜，求Z的最大值
# 然后再去求max(X,Y,Z)
def win(a):#这个地方就是A获胜
    a=sorted(a,reverse=True)
    ans=0
    summ=0
    for i in range(n):
        summ+=a[i]
        if(summ>0):
            ans+=1
            pass
        else:
            break
    if ans==0:
        return -1
    else:
        return ans
    pass
ans=max(win(winA),win(winB),win(winC))
print(ans)