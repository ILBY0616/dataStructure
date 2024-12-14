#ifndef DSLIST_H
#define DSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 动态顺序表
typedef struct DSList
{
    int* data;
    int size, length;
}* DSList;

// 初始动态顺序表
bool initiateDSList(DSList* list);
// 查找数据
int selectDSList(DSList list, int data);
// 插入数据
bool insertDSList(DSList list, int location, int data);
// 删除数据
bool deleteDSList(DSList list, int location);
// 打印动态顺序表
bool printDSList(DSList list);
// 销毁动态顺序表
void destroyDSList(DSList* list);

inline bool initiateDSList(DSList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (DSList)malloc(sizeof(struct DSList));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->data = (int*)malloc(100 * sizeof(int));
    if ((*list)->data == NULL)
    {
        return false;
    }
    (*list)->size = 100;
    (*list)->length = 0;
    return true;
}

inline int selectDSList(DSList list, int data)
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

inline bool insertDSList(DSList list, int location, int data)
{
    // 检查
    if (list == NULL || location < 0 || location > list->length)
    {
        return false;
    }
    if (list->length == list->size)
    {
        list->size += 100;
        int* listData = realloc(list->data, list->size * sizeof(int));
        if (listData == NULL)
        {
            return false;
        }
        list->data = listData;
    }
    // 后移
    for (int i = list->length; i > location; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    // 删除
    list->data[location] = data;
    list->length++;
    return true;
}

inline bool deleteDSList(DSList list, int location)
{
    // 检查
    if (list == NULL || list->length == 0 || location < 0 || location > list->length - 1)
    {
        return false;
    }
    // 后移
    for (int i = location; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    // 删除
    list->length--;
    return true;
}

inline bool printDSList(DSList list)
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

inline void destroyDSList(DSList* list)
{
    if (*list != NULL)
    {
        free((*list)->data);
        (*list)->data = NULL;
        free(*list);
        *list = NULL;
    }
}

#endif
