#include "DLList.h"

// 判断循环链表是否对称
bool judgeSymmetry(List l)
{
    List p = l->next, q = l->prior;
    while (p != q && p->next != q)
    {
        if (p->data == q->data)
        {
            p = p->next;
            q = q->prior;
        }
        else
        {
            return false;
        }
    }
    return true;
}
