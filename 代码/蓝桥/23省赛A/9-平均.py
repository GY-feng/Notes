import os
import sys

class Num:
    def __init__(self,a,b):
        self.a=a
        self.b=b

n=int(input())
l=[]
def count(j):
    b_max=0
    for h in l:
        if h.a!=j:
            b_max+=h.b
    return b_max

for i in range(n):
    a,b=(input().split())
    a=int(a)
    b=int(b)
    x=Num(a,b)
    l.append(x)

b_max=count(0)
print(b_max)
for i in range(1,10):
    c=count(i)
    print(c)
    if c<b_max:
        b_max=c
print(c)






