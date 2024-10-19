#include "SLList.h"

// 删除无序带头结点单链表中最小值
bool deleteMin(SLList* l)
{
    if (*l == NULL || (*l)->next == NULL)
    {
        return false;
    }
    SLList p, q, r, s;
    p = *l, q = (*l)->next, r = *l, s = (*l)->next;
    while (s != NULL)
    {
        if (s->data < q->data)
        {
            p = r;
            q = s;
        }
        r = r->next;
        s = s->next;
    }
    p->next = q->next;
    free(q);
    return true;
}

int main()
{
    SLList l;
    initiateSLList(&l);
    insertSLList(l, 0, 3);
    insertSLList(l, 1, 1);
    insertSLList(l, 2, 4);
    insertSLList(l, 3, 2);
    insertSLList(l, 4, 5);
    printSLList(l);
    deleteMin(&l);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
