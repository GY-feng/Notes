file=input()
file=open(file,'r')

# 按照行读取文件：
for l in file:
    print(l)

# pickle模块实现序列化：
import pickle
l=[1,2,3,4,5,6,67]
with open('l.pickle','rb') as f:
    pickle.dump(l,f)#保存
    l=pickle.load(f)#使用

# json模块实现序列化：
import json
l=[1,2,3,4,5,6,67]
with open('l.json','r',encoding='utf-8') as f:
    l=json.load(f)

