from datetime import datetime
import unittest
from unittest.mock import patch
import io


from main import Task, PriorityQueue, Scheduler

class TestTaskScheduler(unittest.TestCase):

    def setUp(self):
        self.scheduler = Scheduler()

    def test_add_remove_task(self):
        task1 = Task("Task 1", 1, datetime(2023, 5, 1))
        task2 = Task("Task 2", 2, datetime(2023, 4, 20))
        self.scheduler.add_task(task1)
        self.scheduler.add_task(task2)
        self.assertEqual(self.scheduler.remove_task(), task2)
        self.assertEqual(self.scheduler.remove_task(), task1)
        self.assertIsNone(self.scheduler.remove_task())

    def test_reorder_task(self):
        task1 = Task("Task 1", 1, datetime(2023, 5, 1))
        task2 = Task("Task 2", 2, datetime(2023, 4, 20))
        self.scheduler.add_task(task1)
        self.scheduler.add_task(task2)
        self.scheduler.reorder_task(task1, 3, datetime(2023, 5, 10))
        self.scheduler.reorder_task(task2, 4, datetime(2023, 5, 5))
        self.assertEqual(self.scheduler.remove_task(), task2)
        self.assertEqual(self.scheduler.remove_task(), task1)

    def test_execute_task(self):
        task1 = Task("Task 1", 1, datetime(2023, 5, 1))
        task2 = Task("Task 2", 2, datetime(2023, 4, 20))
        task3 = Task("Task 3", 3, datetime(2023, 4, 30))
        self.scheduler.add_task(task1)
        self.scheduler.add_task(task2)
        self.scheduler.add_task(task3)
        with patch('sys.stdout', new=io.StringIO()) as fake_output:
            self.scheduler.execute_task()
            self.assertEqual(fake_output.getvalue().strip(), "Executing task: Description: Task 3, Priority: 3, Deadline: 2023-04-30 00:00:00")
        with patch('sys.stdout', new=io.StringIO()) as fake_output:  
            self.scheduler.execute_task()
            self.assertEqual(fake_output.getvalue().strip(), "Executing task: Description: Task 2, Priority: 2, Deadline: 2023-04-20 00:00:00")
        with patch('sys.stdout', new=io.StringIO()) as fake_output:    
            self.scheduler.execute_task()
            self.assertEqual(fake_output.getvalue().strip(), "Executing task: Description: Task 1, Priority: 1, Deadline: 2023-05-01 00:00:00")
        with patch('sys.stdout', new=io.StringIO()) as fake_output:
            self.scheduler.execute_task()
            self.assertEqual(fake_output.getvalue().strip(), "No tasks to execute")

    def test_display_tasks(self):
        task1 = Task("Task 1", 1, datetime(2023, 5, 1))
        task2 = Task("Task 2", 2, datetime(2023, 4, 20))
        task3 = Task("Task 3", 3, datetime(2023, 4, 30))
        self.scheduler.add_task(task1)
        self.scheduler.add_task(task2)
        self.scheduler.add_task(task3)
        with patch('sys.stdout', new=io.StringIO()) as fake_output:
            self.scheduler.display_tasks()
        self.assertEqual(fake_output.getvalue().strip(), "Current tasks:\nDescription: Task 3, Priority: 3, Deadline: 2023-04-30 00:00:00\nDescription: Task 2, Priority: 2, Deadline: 2023-04-20 00:00:00\nDescription: Task 1, Priority: 1, Deadline: 2023-05-01 00:00:00")

if __name__ == '__main__':
    unittest.main()