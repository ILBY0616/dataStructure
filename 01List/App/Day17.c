#include "SLList.h"

// 删除单链表重复元素
void purgeList(List* l)
{
    List p = *l, q = (*l)->next;
    while (q != NULL)
    {
        if (p->data == q->data)
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
}
