class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        # 通常使用头部指针 head 来表示链表的起始节点，而尾部指针 tail 表示链表的最后一个节点。
        self.head = None
        self.tail = None

    def add_first(self, data):
        new_node = Node(data)
        if not self.head: #如果链表为空的时候
            self.head = new_node
            self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node

    def remove_first(self):
        if self.head:
            removed_data = self.head.data
            if self.head.next:
                self.head = self.head.next
                self.head.prev = None
            else:
                self.head = None
                self.tail = None
            return removed_data
        else: mn                                                              
            return None

    def add_last(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node

    def remove_last(self):
        if self.tail:
            removed_data = self.tail.data
            if self.tail.prev:
                self.tail = self.tail.prev
                self.tail.next = None
            else:
                self.head = None
                self.tail = None
            return removed_data
        else:
            return None

    def remove(self, data):
        current = self.head
        while current:
            if current.data == data:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next

                if current.next:
                    current.next.prev = current.prev
                else:
                    self.tail = current.prev

                return True
            current = current.next
        return False

    def remove_at(self, position):
        if position < 0:
            return False
        if position == 0:
            return self.remove_first()

        current = self.head
        count = 0
        while current and count < position:
            current = current.next
            count += 1

        if not current:
            return False

        if current == self.tail:
            return self.remove_last()

        current.prev.next = current.next
        current.next.prev = current.prev

        return True


# Example usage:
dllist = DoublyLinkedList()
dllist.add_first(1)
dllist.add_first(2)
dllist.add_last(3)

print("Initial list:")
current = dllist.head
while current:
    print(current.data)
    current = current.next

print("Removing from the head:", dllist.remove_first())

print("List after removing from the head:")
current = dllist.head
while current:
    print(current.data)
    current = current.next

dllist.add_last(4)
print("List after adding at the tail:")
current = dllist.head
while current:
    print(current.data)
    current = current.next

dllist.remove(3)
print("List after removing 3:")
current = dllist.head
while current:
    print(current.data)
    current = current.next

dllist.add_last(5)
dllist.add_last(6)
print("List after adding 5 and 6 at the tail:")
current = dllist.head
while current:
    print(current.data)
    current = current.next

dllist.remove_at(1)
print("List after removing node at position 1:")
current = dllist.head
while current:
    print(current.data)
    current = current.next
