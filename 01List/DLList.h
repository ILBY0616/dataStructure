#ifndef DLLIST_H
#define DLLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 带头结点双链表
typedef struct DLListNode
{
    int data;
    struct DLListNode *prior, *next;
}* DLList;

// 开辟带头结点双链表
bool initiateDLList(DLList* list);
// 头插法创建带头结点双链表
bool buildDLListByHead(int* data, int length, DLList* list);
// 尾插法创建带头结点双链表
bool buildDLListByTail(int* data, int length, DLList* list);
// 查找数据
DLList selectDLList(DLList list, int data);
// 插入数据
bool insertDLList(DLList list, int location, int data);
// 删除数据
bool deleteDLList(DLList list, int location);
// 打印带头结点双链表
bool printDLList(DLList list);
// 获取长度
int getLengthDLList(DLList list);
// 销毁带头结点双链表
void destroyDLList(DLList* list);

inline bool initiateDLList(DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (DLList)malloc(sizeof(struct DLListNode));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->prior = NULL;
    (*list)->next = NULL;
    return true;
}

inline bool buildDLListByHead(int* data, int length, DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateDLList(list);
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(struct DLListNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = (*list)->next;
            node->prior = *list;
            if ((*list)->next != NULL)
            {
                (*list)->next->prior = node;
            }
            (*list)->next = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

inline bool buildDLListByTail(int* data, int length, DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateDLList(list);
    DLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(struct DLListNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
            node->prior = tail;
            tail->next = node;
            tail = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

inline DLList selectDLList(DLList list, int data)
{
    if (list != NULL)
    {
        DLList temp = list->next;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
}

inline bool insertDLList(DLList list, int location, int data)
{
    if (list == NULL || location < 0)
    {
        return false;
    }
    DLList temp = list;
    while (location > 0 && temp->next != NULL)
    {
        temp = temp->next;
        location--;
    }
    DLList node = malloc(sizeof(struct DLListNode));
    if (node != NULL)
    {
        node->data = data;
        node->prior = temp;
        node->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prior = node;
        }
        temp->next = node;
    }
    return true;
}

inline bool deleteDLList(DLList list, int location)
{
    if (list == NULL || list->next == NULL || location < 0)
    {
        return false;
    }
    DLList temp = list->next;
    while (location > 0 && temp->next != NULL)
    {
        temp = temp->next;
        location--;
    }
    if (temp == NULL)
    {
        return false;
    }
    if (temp->prior != NULL)
    {
        temp->prior->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prior = temp->prior;
    }
    free(temp);
    return true;
}

inline bool printDLList(DLList list)
{
    if (list == NULL)
    {
        return false;
    }
    list = list->next;
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
    return true;
}

inline int getLengthDLList(DLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return 0;
    }
    DLList temp = list->next;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

inline void destroyDLList(DLList* list)
{
    DLList temp = *list;
    while (temp != NULL)
    {
        *list = (*list)->next;
        free(temp);
        temp = *list;
    }
    *list = NULL;
}

#endif
