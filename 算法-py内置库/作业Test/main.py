# 作业总述：实现优先队列根据任务的优先级和截止日期对任务进行排序来管理任务。
# 每个任务都会被定义为一个具有描述、优先级、截止时间等属性的对象，可以将其添加到优先级队列中，并根据其优先级和截止时间顺序执行。
# 如果存在具有相同优先级的任务，任务调度程序将对具有最早截止日期的任务进行优先级排序，以确保其及时完成。为了在任务管理中提供灵活性，
# 实现还应允许用户修改任务的优先级或截止日期。这包括从队列中删除任务，对其优先级和/或截止时间进行必要的更新，然后根据其新的优先级和截止时间将其重新插入队列中的适当位置。
from datetime import datetime

class Task:
    def __init__(self, description, priority, deadline):
        self.__description = description
        self.__priority = priority
        self.__deadline = deadline

    def get_description(self):
        return self.__description

    def set_description(self, stri):
        self.__description = stri

    def get_priority(self):
        return self.__priority

    def set_priority(self, a):
        self.__priority = a

    def get_deadline(self):
        return self.__deadline

    def set_deadline(self, a):
        self.__deadline = a

    def __str__(self):
        return f"Description: {self.__description}, Priority: {self.__priority}, Deadline: {self.__deadline}"
    ### 注意：这个地方的“标签label不知道形式如何！！！”


class PriorityQueue:
    def __init__(self):
        self.__task = []

    def add_task(self, ta):
        self.__task.append(ta)
        self.__task.sort(key=lambda t: (-t.get_priority(), t.get_deadline()))

    def remove_task(self):
        if not self.__task:
            t = self.__task.pop()
            return t
        else:
            return None

    def peek_task(self):
        if not self.__task:
            t = self.__task[0]
            return t
        else:
            return None

    def get_tasks(self):
        return self.__task


class Scheduler:
    def __init__(self):
        self.__queue = PriorityQueue()
        ## self.__queue.append(PriorityQueue())

    def add_task(self, t):
        self.__queue.add_task(t)

    def remove_task(self):
        return self.__queue.remove_task()

task1 = Task("Task 1", 1, datetime(2023, 5, 1))
task2 = Task("Task 2", 2, datetime(2023, 4, 20))
print(task2)
print(task1)

s=Scheduler()
s.add_task(task1)
s.add_task(task2)

print(s.remove_task())
print(s.remove_task())