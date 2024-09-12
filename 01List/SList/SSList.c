#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define size 10
#define type int

// 静态顺序表
typedef struct List
{
    type data[size];
    int length;
} List;

typedef List* SSList;

// 建立线性表
SSList initiateList(SSList l)
{
    l = (SSList)malloc(sizeof(List));
    if (l != NULL)
    {
        l->length = 0;
    }
    return l;
}

// 插入数据
bool insertData(SSList l, int location, type data)
{
    // 检查
    if (l == NULL || l->length == size || location < 0 || location > l->length)
    {
        return false;
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
bool deleteData(SSList l, int location)
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

// 查找数据
int selectData(SSList l, type data)
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
void destroyList(SSList l)
{
    free(l);
}

int main()
{
    int i = 0;
    type data[size];
    SSList l = NULL;
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
