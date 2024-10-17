#include "SLList.h"

// 删除无序单链表指定范围元素
void deleteAToB(List* l, int a, int b)
{
    List p, q;
    p = *l, q = (*l)->next;
    while (q != NULL)
    {
        if (a <= q->data && q->data <= b)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
    if (a <= (*l)->data && (*l)->data <= b)
    {
        q = (*l);
        *l = (*l)->next;
        free(q);
    }
}
