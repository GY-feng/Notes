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
