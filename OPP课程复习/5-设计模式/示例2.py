# 闭包的应用：修饰器
def decorator(func): #被修饰函数名func
    def defunc(): #装饰后函数
        print('testing') #添加装饰
        func() #运行被装饰的函数
    return defunc #return装饰后的函数名

@decorator   #foo=decorator(foo)
def foo():
    print('foo function')
foo()
