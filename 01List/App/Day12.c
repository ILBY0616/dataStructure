#include "SLList.h"

// 头插法逆转单链表
bool reverseList01(SLList* l)
{
    if (*l == NULL)
    {
        return false;
    }
    SLList p = NULL, q = (*l)->next, r = NULL;
    while (q != NULL)
    {
        p = q;
        q = q->next;
        p->next = r;
        r = p;
    }
    (*l)->next = r;
    return true;
}

// 逆指针逆转单链表
bool reverseList02(SLList* l)
{
    if (*l == NULL || (*l)->next == NULL)
    {
        return false;
    }
    SLList p = NULL, q = (*l)->next, r = (*l)->next->next;
    while (r != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    (*l)->next = q;
    return true;
}

int main()
{
    SLList l = NULL;
    initiateSLList(&l);
    insertSLList(l, 0, 1);
    insertSLList(l, 1, 2);
    insertSLList(l, 2, 3);
    insertSLList(l, 3, 4);
    insertSLList(l, 4, 5);
    printSLList(l);
    reverseList01(&l);
    printSLList(l);
    reverseList02(&l);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
