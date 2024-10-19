#include "SLList.h"

// 删除有序带头结点单链表重复元素
bool purgeList(SLList* l)
{
    if (l == NULL || (*l)->next == NULL)
    {
        return false;
    }
    SLList p = (*l)->next, q = (*l)->next->next;
    while (q != NULL)
    {
        if (q->data == p->data)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return true;
}

int main()
{
    SLList l = NULL;
    initiateSLList(&l);
    insertSLList(l, 0, 1);
    insertSLList(l, 1, 1);
    insertSLList(l, 2, 2);
    insertSLList(l, 3, 2);
    insertSLList(l, 4, 3);
    insertSLList(l, 5, 3);
    insertSLList(l, 6, 4);
    insertSLList(l, 7, 4);
    printSLList(l);
    purgeList(&l);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
