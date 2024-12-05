#ifndef SSLIST_H
#define SSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 静态顺序表
typedef struct SSList
{
    int data[100];
    int size, length;
}* SSList;

// 开辟静态顺序表
bool initiateSSList(SSList* list);
// 查找数据
int selectSSList(SSList list, int data);
// 插入数据
bool insertSSList(SSList list, int location, int data);
// 删除数据
bool deleteSSList(SSList list, int location);
// 打印静态顺序表
bool printSSList(SSList list);
// 销毁静态顺序表
bool destroySSList(SSList* list);

inline bool initiateSSList(SSList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (SSList)malloc(sizeof(struct SSList));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->size = 100;
    (*list)->length = 0;
    return true;
}

inline int selectSSList(SSList list, int data)
{
    if (list != NULL)
    {
        for (int i = 0; i < list->length; i++)
        {
            if (list->data[i] == data)
            {
                return i;
            }
        }
    }
    return -1;
}

inline bool insertSSList(SSList list, int location, int data)
{
    // 检查
    if (list == NULL || list->length == list->size || location < 0 || location > list->length)
    {
        return false;
    }
    // 后移
    for (int i = list->length; i > location; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    // 插入
    list->data[location] = data;
    list->length++;
    return true;
}

inline bool deleteSSList(SSList list, int location)
{
    // 检查
    if (list == NULL || list->length == 0 || location < 0 || location > list->length - 1)
    {
        return false;
    }
    // 前移
    for (int i = location; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    // 删除
    list->length--;
    return true;
}

inline bool printSSList(SSList list)
{
    if (list == NULL)
    {
        return false;
    }
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }
    printf("\n");
    return true;
}

inline bool destroySSList(SSList* list)
{
    if (*list == NULL)
    {
        return false;
    }
    free(*list);
    *list = NULL;
    return true;
}

#endif
