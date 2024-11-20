#ifndef SLLIST_H
#define SLLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 带头结点单链表
typedef struct ListNode
{
    int data;
    struct ListNode* next;
} ListNode, *SLList;

// 开辟带头结点单链表
bool initiateSLList(SLList* list);
// 头插法创建带头结点单链表
bool buildSLListByHead(int data[], int length, SLList* list);
// 尾插法创建带头结点单链表
bool buildSLListByTail(int data[], int length, SLList* list);
// 查找数据
SLList selectSLList(SLList list, int data);
// 插入数据
bool insertSLList(SLList list, int location, int data);
// 删除数据
bool deleteSLList(SLList list, int location);
// 开辟带头结点单链表
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
    *list = (SLList)malloc(sizeof(ListNode));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->next = NULL;
    return true;
}

inline bool buildSLListByHead(int data[], int length, SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateSLList(list);
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(ListNode));
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

inline bool buildSLListByTail(int data[], int length, SLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateSLList(list);
    SLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        SLList node = malloc(sizeof(ListNode));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = NULL;
            tail->next = node;
            tail = tail->next;
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
        SLList temp = list->next;
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

inline bool insertSLList(SLList list, int location, int data)
{
    if (list == NULL || location < 0 || location > getLengthSLList(list))
    {
        return false;
    }
    SLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    SLList node = malloc(sizeof(ListNode));
    if (node != NULL)
    {
        node->data = data;
        node->next = temp->next;
        temp->next = node;
    }
    return true;
}

inline bool deleteSLList(SLList list, int location)
{
    if (list == NULL || list->next == NULL || location < 0 || location > getLengthSLList(list) - 1)
    {
        return false;
    }
    SLList temp = list;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    SLList node = temp->next;
    temp->next = node->next;
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
    SLList slow = list->next;
    SLList fast = list->next;
    int length = 1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        length++;
    }
    if (fast != NULL)
    {
        length = length * 2 - 1;
    }
    else
    {
        length = length * 2;
    }
    return length;
}

inline void destroySLList(SLList* list)
{
    SLList node = *list;
    while (node != NULL)
    {
        *list = (*list)->next;
        free(node);
        node = *list;
    }
    *list = NULL;
}

#endif
