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
} DLListNode, *DLList;

// 初始带头结点双链表
bool initiateDLList(DLList* list);
// 头插法建造带头结点双链表
bool buildDLListByHead(int* data, int length, DLList* list);
// 尾插法建造带头结点双链表
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
    *list = (DLList)malloc(sizeof(DLListNode));
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
    if (initiateDLList(list) == false)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(DLListNode));
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
    if (initiateDLList(list) == false)
    {
        return false;
    }
    DLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        DLList node = malloc(sizeof(DLListNode));
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
        DLList current = list->next;
        while (current != NULL)
        {
            if (current->data == data)
            {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}

inline bool insertDLList(DLList list, int location, int data)
{
    if (list == NULL || location < 0 || location > getLengthDLList(list))
    {
        return false;
    }
    DLList prior = list;
    while (location > 0)
    {
        prior = prior->next;
        location--;
    }
    DLList node = malloc(sizeof(DLListNode));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = prior->next;
    node->prior = prior;
    if (prior->next != NULL)
    {
        prior->next->prior = node;
    }
    prior->next = node;
    return true;
}

inline bool deleteDLList(DLList list, int location)
{
    if (list == NULL || list->next == NULL || location < 0 || location > getLengthDLList(list) - 1)
    {
        return false;
    }
    DLList prior = list;
    while (location > 0)
    {
        prior = prior->next;
        location--;
    }
    DLList node = prior->next;
    prior->next = node->next;
    node->next->prior = prior;
    free(node);
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
    int length = 0;
    while (list->next != NULL)
    {
        list = list->next;
        length++;
    }
    return length;
}

inline void destroyDLList(DLList* list)
{
    while (*list != NULL)
    {
        DLList node = *list;
        *list = (*list)->next;
        free(node);
    }
    *list = NULL;
}

#endif
