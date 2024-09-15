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


# 创建互斥锁
mutex=threading.Lock()
#上锁
mutex.acquire()

###上锁到解锁之间，锁上加锁，一直卡住
# 解锁
mutex.release()