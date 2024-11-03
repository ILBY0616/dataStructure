#ifndef DSLIST_H
#define DSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct List
{
    int* data;
    int size, length;
} List, *DSList;

// 开辟动态顺序表
bool initiateDSList(DSList* list);
// 查询数据
int selectDSList(DSList list, int data);
// 插入数据
bool insertDSList(DSList list, int location, int data);
// 删除数据
bool deleteDSList(DSList list, int location);
// 打印动态顺序表
bool printDSList(DSList list);
// 销毁静态顺序表
bool destroyDSList(DSList* list);

inline bool initiateDSList(DSList* list)
{
    *list = (DSList)malloc(sizeof(List));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->data = (int*)malloc(10 * sizeof(int));
    if ((*list)->data == NULL)
    {
        return false;
    }
    (*list)->size = 10;
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
    if (list == NULL || location < 0 || location > list->length)
    {
        return false;
    }
    if (list->length == list->size)
    {
        list->size += 10;
        list->data = (int*)realloc(list->data, list->size * sizeof(int));
        if (list->data == NULL)
        {
            return false;
        }
    }
    for (int i = list->length; i > location; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[location] = data;
    list->length++;
    return true;
}

inline bool deleteDSList(DSList list, int location)
{
    if (list == NULL || list->length == 0 || location < 0 || location > list->length - 1)
    {
        return false;
    }
    for (int i = location; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
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

inline bool destroyDSList(DSList* list)
{
    if (*list == NULL)
    {
        return false;
    }
    free((*list)->data);
    free(*list);
    *list = NULL;
    return true;
}

#endif //DSLIST_H
