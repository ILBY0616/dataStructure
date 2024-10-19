#include "SLList.h"

// 合并两条递增带头结点单链表为一条递减带头结点单链表
bool mergeList(SLList* a, SLList* b, SLList* c)
{
    if (*a == NULL || *b == NULL || *c == NULL)
    {
        return false;
    }
    SLList p = (*a)->next, q = (*b)->next, r = NULL;
    while (p != NULL || q != NULL)
    {
        if (p == NULL || (q != NULL && q->data < p->data))
        {
            r = q;
            q = q->next;
        }
        else
        {
            r = p;
            p = p->next;
        }
        r->next = (*c)->next;
        (*c)->next = r;
    }
    return true;
}

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    initiateSLList(&a);
    initiateSLList(&b);
    initiateSLList(&c);
    insertSLList(a, 0, 1);
    insertSLList(a, 1, 3);
    insertSLList(a, 2, 5);
    insertSLList(a, 3, 7);
    insertSLList(b, 0, 2);
    insertSLList(b, 1, 4);
    insertSLList(b, 2, 6);
    insertSLList(b, 3, 8);
    printSLList(a);
    printSLList(b);
    mergeList(&a, &b, &c);
    printSLList(c);
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);
    return 0;
}
