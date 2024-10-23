#include "SLList.h"

// 合并两个带头结点循环单链表
bool mergeCycleSLList(SLList* a, SLList* b)
{
    if (*a == NULL || *b == NULL)
    {
        return false;
    }
    SLList p = *a, q = *b;
    while (p->next != *a)
    {
        p = p->next;
    }
    while (q->next != *b)
    {
        q = q->next;
    }
    p->next = *b;
    q->next = *a;
    return true;
}

int main()
{
    return 0;
}
