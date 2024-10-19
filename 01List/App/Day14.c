#include "SLList.h"

// 循环暴力查找Y形两个单链表的公共起始结点
SLList findCommon01(SLList a, SLList b)
{
    SLList p = a;
    while (p != NULL)
    {
        SLList q = b;
        while (q != NULL)
        {
            if (q == p)
            {
                return q;
            }
            q = q->next;
        }
        p = p->next;
    }
    return NULL;
}

// 先走几步查找Y形两个单链表的公共起始结点
SLList findCommon02(SLList a, SLList b)
{
    SLList p = a->next, q = b->next;
    int i = 0, j = abs(getLengthSLList(a) - getLengthSLList(b));
    while (i < j)
    {
        if (a->data > b->data)
        {
            p = p->next;
        }
        else
        {
            q = q->next;
        }
        i++;
    }
    while (p != NULL && q != NULL)
    {
        if (p == q)
        {
            return p;
        }
        p = p->next;
        q = q->next;
    }
    return NULL;
}

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    initiateSLList(&a);
    initiateSLList(&b);
    insertSLList(a, 0, 1);
    insertSLList(a, 1, 2);
    insertSLList(a, 2, 3);
    insertSLList(a, 3, 4);
    insertSLList(a, 4, 5);
    insertSLList(b, 0, 1);
    b->next->next = a->next->next;
    printSLList(a);
    printSLList(b);
    c = findCommon01(a, b);
    printf("%d\n", c != NULL ? c->data : -1);
    c = findCommon02(a, b);
    printf("%d\n", c != NULL ? c->data : -1);
    destroySLList(&a);
    destroySLList(&b);
    return 0;
}
