total=0
def add_num(num):
    ans=0
    while num>0:
        ans+=num%10
        num//=10
    return ans

longmonth=[1,3,5,7,8,10,12]
shortmonth=[2,4,6,9,11]
for i in range(1900,10000):
    if (i%4 == 0 and i%100!=0)or (i%400==0):#闰年捏
        year=add_num(i)
        for j in range (1,13):
            month=add_num(j)
            if j in longmonth:#长月份
                for k in range(1,32):
                    day=add_num(k)
                    if month+day==year:
                        total+=1
            else:
                if j==2:#闰年的二月：
                    for k in range(1,30):
                        day=add_num(k)
                        if day+month==year:
                            total+=1
                else:#闰年的短月份但不是2月
                    for k in range(1,31):
                        day=add_num(k)
                        if day+month==year:
                            total+=1
                    pass
    else:#不是闰年
        year=add_num(i)
        for j in range(1,13):
            month=add_num(j)
            if j in longmonth:#长月份
                for k in range (1,32):
                    day=add_num(k)
                    if month+day==year:
                        total+=1
            else:#短月份
                if j==2:#非闰年的二月：
                    for k in range(1,29):
                        day=add_num(k)
                        if day+month==year:
                            total+=1
                else:#短月份但不是2月
                    for k in range(1,31):
                        day=add_num(k)
                        if day+month==year:
                            total+=1
                    pass
print("满足的天数是：",total)

