#include "SLList.h"

// 逐个输出并删除循环单链表最小值
void findMin(SLList* l)
{
    while ((*l)->next != NULL)
    {
        SLList p = *l, q = (*l)->next, s = (*l)->next, t = (*l)->next->next;
        while (t != *l)
        {
            if (t->data < q->data)
            {
                p = s;
                q = t;
            }
            s = s->next;
            t = t->next;
        }
        printf("%d", q->data);
        p->next = q->next;
        free(q);
    }
    free(*l);
}

int main()
{
    return 0;
}
