#include "SLList.h"

// 根据两条递增单链表中的公共元素创建一条递增单链表
bool createList(SLList* a, SLList* b, SLList* c)
{
    if (*a == NULL || *b == NULL || *c == NULL)
    {
        return false;
    }
    SLList p = (*a)->next, q = (*b)->next, r = *c, s = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data == q->data)
        {
            s = malloc(sizeof(Node));
            if (s != NULL)
            {
                s->data = p->data;
                s->next = NULL;
                r->next = s;
                r = r->next;
            }
        }
        if (p->data <= q->data)
        {
            p = p->next;
        }
        if (p->data >= q->data)
        {
            q = q->next;
        }
    }
    return true;
}

int main()
{
    SLList a = NULL, b = NULL, c = NULL;
    initiateSLList(&a);
    initiateSLList(&b);
    initiateSLList(&c);
    insertSLList(a, 0, 1);
    insertSLList(a, 1, 3);
    insertSLList(a, 2, 5);
    insertSLList(a, 3, 7);
    insertSLList(b, 0, 1);
    insertSLList(b, 1, 2);
    insertSLList(b, 2, 3);
    insertSLList(b, 3, 4);
    printSLList(a);
    printSLList(b);
    createList(&a, &b, &c);
    printSLList(c);
    destroySLList(&a);
    destroySLList(&b);
    destroySLList(&c);
    return 0;
}
