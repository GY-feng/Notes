#include <iostream>

template <typename T>
class DNode
{
public:
    T data;
    DNode *next;
    DNode *prev;

    DNode(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList
{
private:
    DNode<T> *head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // 在链表头部插入新节点
    void insertAtHead(T value)
    {
        DNode<T> *newNode = new DNode<T>(value);
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        newNode->next = head;
        head = newNode;
    }

    // 删除链表中的指定值
    void deleteNode(T value)
    {
        if (head == nullptr)
            return;

        DNode<T> *current = head;
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }

        if (current == nullptr)
            return;

        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        else
        {
            head = current->next;
        }

        if (current->next != nullptr)
        {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // 打印链表
    void printList() const
    {
        DNode<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 打印链表的反向顺序
    void printReverse() const
    {
        if (head == nullptr)
            return;

        DNode<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }

        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->prev;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 销毁链表，释放内存
    ~DoublyLinkedList()
    {
        DNode<T> *current = head;
        while (current != nullptr)
        {
            DNode<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    DoublyLinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    std::cout << "Initial List: ";
    list.printList();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.printList();

    std::cout << "Reverse List: ";
    list.printReverse();

    return 0;
}
/*
代码说明：
DNode类：表示双向链表的一个节点。它包含数据部分 (data)，指向下一个节点的指针 (next)，以及指向前一个节点的指针 (prev)。
DoublyLinkedList类：表示双向链表结构。它包含了链表的头节点 (head) 以及对链表的各种操作方法。
insertAtHead方法：在链表的头部插入一个新节点。
deleteNode方法：删除链表中包含指定值的节点。
printList方法：按正向顺序打印整个链表。
printReverse方法：按反向顺序打印整个链表。
析构函数：销毁链表并释放分配的内存。
*/