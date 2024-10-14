#include "SLList.h"

// 删除链表中最小值
void deleteMin(List* l)
{
    List p, q, r, s;
    p = *l, q = (*l)->next, r = (*l)->next, s = (*l)->next->next;
    while (s != NULL)
    {
        if (s->data < q->data)
        {
            p = r;
            q = s;
        }
        r = s;
        s = s->next;
    }
    p->next = q->next;
    free(q);
}
