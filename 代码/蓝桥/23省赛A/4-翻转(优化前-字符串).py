import os
import sys
n=int(input())
def turn(s):
    if s=="101":
        return "111"
    if s=="010":
        return "000"
    else:
        return "FUCK"
    pass

def al(s, t):
    length=len(s)
    ans=0
    if s[0]!=t[0] or s[length-1]!=t[length-1]:
        #print("LINE 17")
        return "-1"
    else:
        for i in range(1,length):
            if s[i]!=t[i]:
                str_tmp=""
                str_tmp+=s[i-1:i+2]
                #print("str_tmp:",str_tmp)
                str_tmp=turn(str_tmp)
                if str_tmp=="FUCK":
                    #print("LINE 26")
                    return "-1"
                else:
                    str_new=""
                    str_new+=s[0:i-1]
                    str_new+=str_tmp
                    str_new+=s[i+2:]
                    s=str_new
                    ans+=1
                pass
        return ans

    pass

for i in range(n):
    #t,s=map(str,input().split())
    t=input()
    s=input()
    print(al(s,t))