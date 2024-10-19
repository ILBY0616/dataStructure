#include "SLList.h"

// 判断a单链表是否包含b单链表
bool judgePattern(SLList a, SLList b)
{
    SLList p = a->next, q = a->next, s = b->next, t = b->next;
    while (q != NULL && t != NULL)
    {
        if (q->data == t->data)
        {
            q = q->next;
            t = t->next;
        }
        else
        {
            p = p->next;
            q = p;
            t = s;
        }
    }
    if (t == NULL)
    {
        return true;
    }
    return false;
}

int main()
{
    SLList a = NULL, b = NULL;
    initiateSLList(&a);
    initiateSLList(&b);
    insertSLList(a, 0, 1);
    insertSLList(a, 1, 2);
    insertSLList(a, 2, 3);
    insertSLList(a, 3, 4);
    insertSLList(a, 4, 5);
    insertSLList(b, 0, 3);
    insertSLList(b, 1, 4);
    printSLList(a);
    printSLList(b);
    if (judgePattern(a, b))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    destroySLList(&a);
    destroySLList(&b);

    return 0;
}
