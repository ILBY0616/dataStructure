#include "DSList.h"

// 建立顺序表
bool initiateDSList(DSList* list)
{
    *list = (DSList)malloc(sizeof(Node));
    if (*list == NULL)
    {
        return false;
    }
    (*list)->data = (type*)malloc(newSize * sizeof(type));
    if ((*list)->data == NULL)
    {
        return false;
    }
    (*list)->size = newSize;
    (*list)->length = 0;
    return true;
}

// 查找数据
int selectDSList(DSList list, type data)
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

// 插入数据
bool insertDSList(DSList list, int location, type data)
{
    // 检查位置
    if (list == NULL || location < 0 || location > list->length)
    {
        return false;
    }
    // 检查内存
    if (list->length == list->size)
    {
        list->size += newSize;
        list->data = (type*)realloc(list->data, list->size * sizeof(type));
        if (list->data == NULL)
        {
            return false;
        }
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

// 删除数据
bool deleteDSList(DSList list, int location)
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

// 打印顺序表
bool printDSList(DSList list)
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

// 销毁顺序表
void destroyDSList(DSList* list)
{
    if (*list != NULL)
    {
        free((*list)->data);
        free(*list);
        *list = NULL;
    }
}
