#include "SLList.h"

// 找到两条递增单链表a、b中公共元素存放在a中
bool purgeList(SLList* a, SLList* b)
{
    if (*a == NULL || *b == NULL)
    {
        return false;
    }
    SLList p = *a, q = (*a)->next, r = (*b)->next;
    while (q != NULL && r != NULL)
    {
        if (q->data < r->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else if (q->data == r->data)
        {
            p = p->next;
            q = q->next;
            r = r->next;
        }
        else
        {
            r = r->next;
        }
    }
    while (q != NULL)
    {
        p->next = q->next;
        free(q);
        q = p->next;
    }
    return true;
}

int main()
{
    SLList a = NULL, b = NULL;
    initiateSLList(&a);
    initiateSLList(&b);
    insertSLList(a, 0, 1);
    insertSLList(a, 1, 3);
    insertSLList(a, 2, 5);
    insertSLList(a, 3, 7);
    insertSLList(b, 0, 1);
    insertSLList(b, 1, 2);
    insertSLList(b, 2, 3);
    insertSLList(b, 3, 4);
    printSLList(a);
    printSLList(b);
    purgeList(&a, &b);
    printSLList(a);
    printSLList(b);
    destroySLList(&a);
    destroySLList(&b);
    return 0;
}
