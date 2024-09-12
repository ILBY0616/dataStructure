#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int

// 带头节点单链表
typedef struct Node
{
    type data;
    struct Node* next;
} Node;

typedef Node* SLList;

// 建立线性表
SLList initiateList(SLList l)
{
    l = (SLList)malloc(sizeof(Node));
    if (l != NULL)
    {
        l->data = 0;
        l->next = NULL;
    }
    return l;
}

// 插入数据
bool insertData(SLList l, int location, type data)
{
    // 检查
    if (l == NULL || location < 0 || location > l->data)
    {
        return false;
    }
    // 查找
    SLList temp = l;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 插入
    SLList node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->next = temp->next;
        temp->next = node;
        l->data++;
    }
    return true;
}

// 删除数据
bool deleteData(SLList l, int location)
{
    // 检查
    if (l == NULL || l->next == NULL || location < 0 || location > l->data - 1)
    {
        return false;
    }
    // 查找
    SLList temp = l;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 删除
    SLList node = temp->next;
    temp->next = node->next;
    free(node);
    l->data--;
    return true;
}

// 查找数据
SLList selectData(SLList l, type data)
{
    if (l != NULL)
    {
        SLList temp = l->next;
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

// 销毁线性表
void destroyList(SLList l)
{
    SLList temp = l;
    while (temp != NULL)
    {
        l = l->next;
        free(temp);
        temp = l;
    }
}

int main()
{
    int i = 0;
    type data[10];
    SLList l = NULL;
    l = initiateList(l);
    while (scanf("%d", &data[i]) == 1)
    {
        insertData(l, i, data[i]);
        i++;
    }
    deleteData(l, --i);
    for (int j = 0; j < i; j++)
    {
        printf("%d ", selectData(l, data[j])->data);
    }
    destroyList(l);
    return 0;
}






