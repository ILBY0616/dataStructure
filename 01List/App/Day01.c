#include "SLList.h"

// 删除带头结点单链表中所有值为x的元素
bool deleteX(SLList* l,type x)
{
    if (l == NULL)
    {
        return false;
    }
    SLList f = *l, r = (*l)->next;
    while (r != NULL)
    {
        if (r->data == x)
        {
            f->next = r->next;
            free(r);
            r = f->next;
        }
        else
        {
            f = f->next;
            r = r->next;
        }
    }
    return true;
}

int main()
{
    SLList l;
    initiateSLList(&l);
    insertSLList(l, 0, 10);
    insertSLList(l, 1, 20);
    insertSLList(l, 2, 10);
    insertSLList(l, 3, 30);
    insertSLList(l, 4, 10);
    insertSLList(l, 5, 40);
    printSLList(l);
    deleteX(&l, 10);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
