#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define newSize 100
#define type int

// 动态顺序表
typedef struct List
{
    type* data;
    int size, length;
} List;

typedef List* DSList;

// 建立线性表
DSList initiateList(DSList l)
{
    l = (DSList)malloc(sizeof(List));
    if (l != NULL)
    {
        l->data = (type*)malloc(newSize * sizeof(type));
        l->size = newSize;
        l->length = 0;
    }
    return l;
}

// 插入数据
bool insertData(DSList l, int location, type data)
{
    // 检查位置
    if (l == NULL || location < 0 || location > l->length)
    {
        return false;
    }
    // 检查内存
    if (l->length == l->size)
    {
        l->size += newSize;
        l->data = (type*)realloc(l->data, newSize * sizeof(type));
    }
    // 后移
    for (int i = l->length; i > location; i--)
    {
        l->data[i] = l->data[i - 1];
    }
    // 插入
    l->data[location] = data;
    l->length++;
    return true;
}

// 删除数据
bool deleteData(DSList l, int location)
{
    // 检查
    if (l == NULL || l->length == 0 || location < 0 || location > l->length - 1)
    {
        return false;
    }
    // 前移
    for (int i = location; i < l->length; i++)
    {
        l->data[i] = l->data[i + 1];
    }
    // 删除
    l->length--;
    return true;
}

// 查找元素
int selectData(DSList l, type data)
{
    if (l != NULL)
    {
        for (int i = 0; i < l->length; i++)
        {
            if (l->data[i] == data)
            {
                return i;
            }
        }
    }
    return -1;
}

// 销毁线性表
void destroyList(DSList l)
{
    free(l);
}

int main()
{
    int i = 0;
    type data[newSize];
    DSList l = NULL;
    l = initiateList(l);
    while (scanf("%d", &data[i]) == 1)
    {
        insertData(l, i, data[i]);
        i++;
    }
    deleteData(l, --i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", selectData(l, data[j]));
    }
    destroyList(l);
    return 0;
}
