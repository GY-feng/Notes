#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 创建一个新节点
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入新节点
void insertAtHead(Node **head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// 删除链表中指定值的节点
void deleteNode(Node **head, int value)
{
    if (*head == NULL)
        return;

    Node *temp = *head;
    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    Node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

// 打印链表
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    printf("Initial List: ");
    printList(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    freeList(head);

    return 0;
}
/*
单向链表：

Node 结构体：包含一个数据域 data 和一个指向下一个节点的指针 next。
createNode 函数：用于创建一个新节点。
insertAtHead 函数：在链表头部插入新节点。
deleteNode 函数：删除链表中指定值的节点。
printList 函数：打印链表。
freeList 函数：释放链表占用的内存
 */