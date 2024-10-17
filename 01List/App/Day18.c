#include "SLList.h"

// 合并两条递增单链表为一条递减单链表
void purgeList(List* a, List* b, List* c)
{
    while (*a != NULL && *b != NULL)
    {
        List node = NULL;
        if ((*a)->data < (*b)->data)
        {
            node = *a;
            *a = (*a)->next;
            node->next = *c;
            *c = node;
        }
        else
        {
            node = *b;
            *b = (*b)->next;
            node->next = *c;
            *c = node;
        }
    }
}
