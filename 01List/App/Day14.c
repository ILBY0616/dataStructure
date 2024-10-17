#include "SLList.h"

// 查找Y形两个单链表的公共起始结点
List findCommon01(List* a, List* b)
{
    List p = *a, q = *b;
    while (p != NULL)
    {
        while (q != NULL)
        {
            if (q == p)
            {
                return q;
            }
            q = q->next;
        }
        p = p->next;
    }
    return NULL;
}

// 查找Y形两个单链表的公共起始结点
List findCommon02(List* a, List* b)
{
    List p = *a, q = *b;
    for (int i = 0; i < (getLength(*a) - getLength(*b)); i++)
    {
        if (getLength(*a) > getLength(*b))
        {
            p = p->next;
        }
        else
        {
            q = q->next;
        }
    }
    while (p != NULL)
    {
        if (p == q)
        {
            return p;
        }
        p = p->next;
        q = q->next;
    }
    return NULL;
}
