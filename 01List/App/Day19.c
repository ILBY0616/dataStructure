#include "SLList.h"

// 找到两条递增单链表中公共元素为一条递增单链表
void purgeList(List* a, List* b, List* c)
{
    List p = *a, q = *b, r = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data == q->data)
        {
            List node = malloc(sizeof(Node));
            if (node != NULL)
            {
                node->data = p->data;
                node->next = NULL;
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
        else
        {
            if (p->data < q->data)
            {
                p = p->next;
            }
            else
            {
                q = q->next;
            }
        }
    }
}
