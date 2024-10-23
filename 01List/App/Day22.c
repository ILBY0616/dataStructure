#include "DLList.h"

// 初始化循环双链表
bool initiateCycleDLList(DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    *list = (DLList)malloc(sizeof(Node));
    if (*list != NULL)
    {
        (*list)->next = *list;
        (*list)->prior = *list;
        return true;
    }
    return false;
}

// 尾插法建立循环双链表
bool buildCycleDLListByTail(type data[], int length, DLList* list)
{
    if (*list != NULL)
    {
        return false;
    }
    initiateCycleDLList(list);
    DLList tail = *list;
    for (int i = 0; i < length; i++)
    {
        DLList node = (DLList)malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data[i];
            node->next = *list;
            node->prior = tail;
            tail->next = node;
            (*list)->prior = node;
            tail = node;
        }
        else
        {
            i--;
        }
    }
    return true;
}

// 判断循环双链表是否对称
bool judgeSymmetry(DLList l)
{
    DLList p = l->next, q = l->prior;
    while (p != q && p->prior != q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    DLList l = NULL;
    type data[] = {1, 2, 3, 2, 1};
    int length = sizeof(data) / sizeof(data[0]);
    buildCycleDLListByTail(data, length, &l);
    if (judgeSymmetry(l))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
