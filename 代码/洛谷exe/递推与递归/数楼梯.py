#涉及高精度的东西用python写真的是爽爽爽！！！
n=int(input())
f=[0] * 5010
f[1]=1
f[2]=2
for i in range(3,n+1):
  f[i]=f[i-2]+f[i-1]
print(f[n])