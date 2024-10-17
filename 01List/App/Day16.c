#include "SLList.h"

// 分解单链表a成单链表b和c，b为奇序列，c为逆转偶序列
void splitList(List* a, List* b, List* c)
{
    List p = *a, r = NULL;
    for (int i = 0; p != NULL; i++)
    {
        List node = p;
        p = p->next;
        node->next = NULL;
        if (i % 2 == 0)
        {
            node->next = *b;
            *b = node;
        }
        else
        {
            if (*c == NULL || r == NULL)
            {
                *c = node;
                r = node;
            }
            else
            {
                r->next = node;
                r = node;
            }
        }
    }
}
