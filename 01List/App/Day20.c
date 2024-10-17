#include "SLList.h"

// 找到两条递增单链表a、b中公共元素存放在a中
void purgeList(List* a, List* b)
{
    List p = (*a)->next, q = (*b)->next, r = *a;
    while (p != NULL && q != NULL)
    {
        if (p->data == q->data)
        {
            r = r->next;
            p = p->next;
            q = q->next;
        }
        else
        {
            if (p->data < q->data)
            {
                r->next = p->next;
                free(p);
                p = r->next;
            }
            else
            {
                q = q->next;
            }
        }
    }
}
