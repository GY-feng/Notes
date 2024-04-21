class Citizen:
    def __init__(self,idn,name):
        self.idn=idn
        self.name=name
        pass
class Student(Citizen):
    def __init__(self,idn,name,stdno):
        super(Student,self).__init__(idn,name)
        # super(Student,self) 首先找 Student 的父类（即 Citizen），
        # 然后把类 Student 的对象转换为类 Citizen 的对象
        # 也可以简化成这样写：
        super().__init__(idn,name)
        self.stdno=stdno
        pass

    pass

def info(*args,**kwargs):
    # *args 表示接受任意数量的位置参数，**kwargs 表示接受任意数量的关键字参数
    for name in args:
        print(args)
        pass
    for i in kwargs:
        print(kwargs)
        pass

info('Andy')
# args 只包含一个元素 'Andy'，而在第二个循环中，kwargs 是空的，因为没有传递关键字参数。因此，输出将是 'Andy'（第一个循环的内容）。
info('Andy', 'Bob', 'Candy')
# args 包含三个元素，而在第二个循环中，kwargs 仍然是空的。因此，输出将是 ('Andy', 'Bob', 'Candy')（第一个循环的内容）。
info(Andy=1, Bob=2, Candy=3)
# 没有位置参数，但有三个关键字参数 'Andy', 'Bob', 'Candy'。因此，在第一个循环中，args 是空的，而在第二个循环中，kwargs 包含了三个键
# 'Andy', 'Bob', 'Candy'。因此，输出将是 {'Andy': 1, 'Bob': 2, 'Candy': 3}（第二个循环的内容）。

# 可变参数在类当中的应用：
class Car_:
    def __init__(self,brand,color,*args,**k):
        self.brand=brand
        self.color=color
class ECars(Car_):
    def __init__(self,power,*args,**kwargs):
        super().__init__(*args,**kwargs)
        # 可变参数->传递参数 无论 Car 类将来如何修改其构造函数，ECars 类都不需要做出相应修改，因为它可以适应父类的任何变化。
        self.power=power
car_obj1=ECars('HUAWEI',"RED",500)
car_obj2=ECars('HUAWEI','Red',500,year=3)
# 虽然 ECars 类本身没有定义 year 参数，但是由于使用了可变参数 **kwargs，它可以接受任意数量的关键字参数。
# 当调用 ECars 类的实例时，传递的所有额外的关键字参数都会被收集到 **kwargs 中。
#
# 在 ECars 类的 __init__ 方法中，使用 **kwargs 来接收这些额外的关键字参数。
# 然后，通过 super().__init__(*args, **kwargs) 调用父类 Car 的 __init__ 方法，将这些参数传递给父类。
# 父类的 __init__ 方法不需要明确地定义这些参数，因为它使用了可变参数 **k 来接收任意数量的关键字参数。
#
# 因此，即使在 ECars 类中没有明确定义 year 参数，但是通过可变参数 **kwargs，
# 依然可以将 year 参数传递给父类的 __init__ 方法，而不会导致错误。

# 类的特性：
class Car:
    all_car=[]

    def __init__(self,ma,mo,yr):
        self.make=ma
        self.model=mo
        self.year=yr
        self.odometer_reading=0
        Car.all_car.append(self)  #每一个Car的实例都会被添加到类当中
    @classmethod
    def print_inventory(cls):
        for item in cls.all_car:
            print(item.get_fullname())

class MyClass:
    @staticmethod
    def static_method(x, y):
        return f"Static method called with {x} and {y}"

# 调用静态方法，不需要创建实例
MyClass.static_method(5, 10)