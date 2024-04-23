def firstn(n):
    num=0
    while num<n:
        yield num
        # 每次调用生成器函数时，它都会在 yield 语句处暂停执行，然后返回一个值，并在下次调用时从上次暂停的地方继续执行
        num+=1
gen=firstn(3)
# 返回了一个生成器对象 gen。这个生成器对象表示从 0 到 2 的整数序列
print(next(gen))
print(next(gen))
print(next(gen))
print(next(gen))
# 在第四次调用时，由于生成器只生成了 0、1、2 三个值，所以会触发 StopIteration 异常，表示生成器已经没有更多的值可供获取。

# 一般的面向对象的方法:
class role:
    def show(self):
        print("Unkown!")
class player(role):
    def show(self):
        print("player!")
class enemy(role):
    def show(self):
        print("enemy!")
class factory:
    def build(self):
        pass
class player_factory(factory):
    def build(self):
        return player()
class enemy_factory(factory):
    def build(self):
        return enemy()
factory1=player_factory()
r1=factory1.build()
r1.show()
r2=factory1.build()
r2.show()
# 工厂类抽象化——派生出player工厂、enemy工厂


def foo():
    print('foo func')
def new_foo():
    print('test')
    print('foo dunction')
def decorator(func):# 函数名-传参
    print('testing')
    func() # 函数名-调用
decorator(foo) #简单修饰

class person:
    def __init__(self,name):
        self.name=name
        self.clothes=None
def Finery(obj):# 函数用于输出一个人的穿着情况。
    if not obj.clothes:
        print(obj.name,"is wearing",obj.clothes)
    else:
        print(obj.name, "is wearing Nothing!!!")
def decorator(func,clothes):
    # 用于给一个人对象添加特定的服装,func 表示要装饰的函数（这里是 Finery 函数），clothes 表示要添加的服装
    def deco(obj):# 参数obj表示要添加服装的人对象。
        obj.clothes=clothes
        func(obj)# 调用原始的 func 函数来输出穿着情况
    return deco
Andy=person('Andy')
Finery(Andy)
Tshirt=decorator(Finery,'Tshirts')
Tshirt(Andy)
Suit=decorator(Finery,'Suit')
Suit(Andy)
# 装饰器模式的应用，它可以动态地给对象添加新的行为或功能，而不需要改变对象的结构。


# 闭包的概念：当某个函数被当成对象返回时，夹带了外部变量，就形成了一个闭包

def make(msg):
    def printer():
        print(msg)# 外部变量
    return printer #返回函数
printer=make("hello")
printer()

# 闭包的应用：修饰器
def decorator(func): #被修饰函数名func
    def defunc(): #装饰后函数
        print('testing') #添加装饰
        func() #运行被装饰的函数
    return defunc #return装饰后的函数名
def foo():
    return ('foo function')
foo=decorator(foo)
foo()


