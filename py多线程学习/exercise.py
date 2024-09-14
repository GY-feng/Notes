import threading 
import time

def sing(num):
    for i in range(num):
        print("sing")
        time.sleep(1)
        pass
def dance(count):
    for i in range(count):
        print("Dance")
        time.sleep(1)
    return 333

# 元组传递参数
sing_thread=threading.Thread(target=sing,args=(3,))
# 字典传递参数
dance_thread=threading.Thread(target=dance,kwargs={"count":2})
sing_thread.start()
dance_thread.start()