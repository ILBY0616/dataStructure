#include "SLList.h"

// 判断a单链表是否包含b单链表
bool judgePattern(List a, List b)
{
    List p = a, q = a, s = b, t = b;
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
