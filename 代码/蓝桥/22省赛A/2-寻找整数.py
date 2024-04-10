mmax=100000000000000000
l=[0,0,1,2,1,4,5,4,1,2,9,0,5,10,11,14,9,0,11,18,9,11,11,15,17,9,23,20,25,16,29,27,25,11
   ,17,4,29,22,37,23,9,1,11,11,33,29,15,5,41,46]
b=187 # 11*17
def OK(n):
    for i in range(2,50):
        if(n%i !=l[i]):
            return False
        pass
    return True
for i in range(b,mmax,b*2):
    print("Now is",i)
    if OK(i):
        print(i)
        break