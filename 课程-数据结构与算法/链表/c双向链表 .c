#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// 创建一个新节点
DNode *createDNode(int value)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 在链表头部插入新节点
void insertAtHead(DNode **head, int value)
{
    DNode *newNode = createDNode(value);
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// 删除链表中指定值的节点
void deleteDNode(DNode **head, int value)
{
    if (*head == NULL)
        return;

    DNode *temp = *head;
    if (temp->data == value)
    {
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// 打印链表
void printDList(DNode *head)
{
    DNode *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 释放链表内存
void freeDList(DNode *head)
{
    DNode *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    DNode *head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);

    printf("Initial List: ");
    printDList(head);

    deleteDNode(&head, 20);
    printf("After deleting 20: ");
    printDList(head);

    freeDList(head);

    return 0;
}

/*
双向链表：

DNode 结构体：包含一个数据域 data，一个指向下一个节点的指针 next，以及一个指向前一个节点的指针 prev。
createDNode 函数：用于创建一个新节点。
insertAtHead 函数：在链表头部插入新节点。
deleteDNode 函数：删除链表中指定值的节点。
printDList 函数：打印链表。
freeDList 函数：释放链表占用的内存。
*/