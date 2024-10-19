#include "SLList.h"

// 删除无序带头结点单链表指定范围元素
bool deleteAToB(SLList* l, int a, int b)
{
    if (*l == NULL || a > b)
    {
        return false;
    }
    SLList p = *l, q = (*l)->next;
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
    insertSLList(l, 0, 10);
    insertSLList(l, 1, 20);
    insertSLList(l, 2, 30);
    insertSLList(l, 3, 40);
    insertSLList(l, 4, 50);
    insertSLList(l, 5, 60);
    printSLList(l);
    deleteAToB(&l, 20, 50);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
