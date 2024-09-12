#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int

// 带头节点双链表
typedef struct Node
{
    type data;
    struct Node *prior, *next;
} Node;

typedef Node* DLList;

// 建立线性表
DLList initiateList(DLList l)
{
    l = (DLList)malloc(sizeof(Node));
    if (l != NULL)
    {
        l->data = 0;
        l->prior = NULL;
        l->next = NULL;
    }
    return l;
}

// 插入数据
bool insertData(DLList l, int location, type data)
{
    // 检查
    if (l == NULL || location < 0 || location > l->data)
    {
        return false;
    }
    // 查找
    DLList temp = l;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 插入
    DLList node = malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->prior = temp;
        node->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prior = node;
        }
        temp->next = node;
        l->data++;
    }
    return true;
}

// 删除数据
bool deleteData(DLList l, int location)
{
    // 检查
    if (l == NULL || l->next == NULL || location < 0 || location > l->data - 1)
    {
        return false;
    }
    // 查找
    DLList temp = l;
    while (location > 0)
    {
        temp = temp->next;
        location--;
    }
    // 删除
    DLList node = temp->next;
    temp->next = node->next;
    if (node->next != NULL)
    {
        node->next->prior = temp;
    }
    free(node);
    l->data--;
    return true;
}

// 查找数据
DLList selectData(DLList l, type data)
{
    if (l != NULL)
    {
        DLList temp = l->next;
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
void destroyList(DLList l)
{
    DLList temp = l;
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
    DLList l = NULL;
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