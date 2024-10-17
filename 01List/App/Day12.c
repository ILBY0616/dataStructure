#include "SLList.h"

// 逆转单链表
void buildList01(List* l)
{
    List head = NULL, node = *l;
    while (node != NULL)
    {
        List temp = node;
        node = node->next;
        temp->next = head;
        head = temp;
    }
    *l = head;
}


// 逆转单链表
void buildList02(List* l)
{
    List p, q, r;
    p = *l, q = (*l)->next, r = (*l)->next->next;
    while (r != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    (*l)->next = NULL;
    *l = q;
}
