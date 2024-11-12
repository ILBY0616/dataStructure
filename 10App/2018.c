#include <stdio.h>
#include "SLList.h"

// 合并带头结点有序单链表a和b到c，使c仍然有序
bool mergrSLList(SLList a, SLList b, SLList c)
{
    if (a == NULL || b == NULL)
    {
        return false;
    }
    SLList i = a->next, j = b->next, k = c;
    free(a);
    free(b);
    while (i != NULL && j != NULL)
    {
        if (i->data < j->data)
        {
            k->next = i;
            k = k->next;
            i = i->next;
        }
        else
        {
            k->next = j;
            k = k->next;
            j = j->next;
        }
    }
    if (i != NULL)
    {
        k->next = i;
    }
    if (j != NULL)
    {
        k->next = j;
    }
    return true;
}

int main()
{
    printf("Hello, World!\n");
    return 0;
}
