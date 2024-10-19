#include "SLList.h"

// 分解单链表a成b和c，b为顺序奇序列，c为逆序偶序列
bool splitList(SLList* a, SLList* b, SLList* c)
{
    if (*a == NULL || *b == NULL || *c == NULL)
    {
        return false;
    }
    SLList p = NULL, q = (*a)->next, r = *b;
    while (q != NULL)
    {
        p = q;
        q = q->next;
        p->next = NULL;
        r->next = p;
        r = p;
        if (q != NULL)
        {
            p = q;
            q = q->next;
            p->next = (*c)->next;
            (*c)->next = p;
        }
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
    insertSLList(a, 1, 2);
    insertSLList(a, 2, 3);
    insertSLList(a, 3, 4);
    insertSLList(a, 4, 5);
    insertSLList(a, 5, 6);
    printSLList(a);
    splitList(&a, &b, &c);
    printSLList(b);
    printSLList(c);
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);
    return 0;
}
