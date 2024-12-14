#ifndef SLLIST_H
#define SLLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 带头结点单链表
typedef struct SLListNode
{
    int data;
    struct SLListNode* next;
} SLListNode, *SLList;

// 初始带头结点单链表
bool initiateSLList(SLList* list);
// 头插法建造带头结点单链表
bool buildSLListByHead(int* data, int length, SLList* list);
// 尾插法建造带头结点单链表
bool buildSLListByTail(int* data, int length, SLList* list);
// 查找数据
SLList selectSLList(SLList list, int data);
// 插入数据
bool insertSLList(SLList list, int location, int data);
// 删除数据
bool deleteSLList(SLList list, int location);
// 打印带头结点单链表
bool printSLList(SLList list);
// 获取长度
int getLengthSLList(SLList list);
// 销毁带头结点单链表
void destroySLList(SLList* list);

inline bool initiateSLList(SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (SLList)malloc(sizeof(SLListNode));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->next = NULL;
    return true;
}

inline bool buildSLListByHead(int* data, int length, SLList* list)
{
    if (initiateSLList(list) == false)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(SLListNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = (*list)->next;
            (*list)->next = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

inline bool buildSLListByTail(int* data, int length, SLList* list)
{
    if (initiateSLList(list) == false)
    {
        return false;
    }
    SLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(SLListNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
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

inline SLList selectSLList(SLList list, int data)
{
    if (list != NULL)
    {
        SLList current = list->next;
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

inline bool insertSLList(SLList list, int location, int data)
{
    if (list == NULL || location < 0 || location > getLengthSLList(list))
    {
        return false;
    }
    SLList prior = list;
    while (location > 0)
    {
        prior = prior->next;
        location--;
    }
    SLList node = malloc(sizeof(SLListNode));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = prior->next;
    prior->next = node;
    return true;
}

inline bool deleteSLList(SLList list, int location)
{
    if (list == NULL || list->next == NULL || location < 0 || location > getLengthSLList(list) - 1)
    {
        return false;
    }
    SLList prior = list;
    while (location > 0)
    {
        prior = prior->next;
        location--;
    }
    SLList node = prior->next;
    prior->next = node->next;
    free(node);
    return true;
}

inline bool printSLList(SLList list)
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

inline int getLengthSLList(SLList list)
{
    if (list == NULL || list->next == NULL)
    {
        return 0;
    }
    int length = 0;
    SLList slow = list->next, fast = list->next;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        length++;
    }
    return fast != NULL ? length * 2 + 1 : length * 2;
}

inline void destroySLList(SLList* list)
{
    while (*list != NULL)
    {
        SLList node = *list;
        *list = (*list)->next;
        free(node);
    }
    *list = NULL;
}

#endif
