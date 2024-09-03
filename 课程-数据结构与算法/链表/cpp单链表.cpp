#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}

    // 插入新节点到链表头部
    void insertAtHead(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // 删除链表中的指定值
    void deleteNode(T value)
    {
        if (head == nullptr)
            return;

        if (head->data == value)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next == nullptr)
            return;

        Node<T> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // 打印链表
    void printList() const
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // 销毁链表，释放内存
    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    std::cout << "Initial List: ";
    list.printList();

    list.deleteNode(20);
    std::cout << "After deleting 20: ";
    list.printList();

    return 0;
}
/*
代码说明：
Node类：表示链表的一个节点。它包含数据部分 (data) 和指向下一个节点的指针 (next)。
LinkedList类：表示链表结构。它包含了链表的头节点 (head) 以及对链表的各种操作方法。
insertAtHead方法：在链表的头部插入一个新节点。
deleteNode方法：删除链表中包含指定值的节点。
printList方法：打印整个链表。
析构函数：销毁链表并释放分配的内存
*/