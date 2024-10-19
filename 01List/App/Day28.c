#include "SLList.h"

void changeList(SLList* l)
{
    SLList p = *l, q = *l, r = NULL, s = NULL;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    q = p->next;
    while (q != NULL)
    {
        r = q;
        q = q->next;
        r->next = s;
        s = r;
    }
    p->next = NULL;
    p = (*l)->next;
    q = s;
    r = *l;
    while (p != NULL && q != NULL)
    {
        r->next = p;
        p = p->next;
        r = r->next;

        r->next = q;
        q = q->next;
        r = r->next;
    }
    if (p != NULL)
    {
        r->next = p;
    }
}

int main()
{
    return 0;
}
