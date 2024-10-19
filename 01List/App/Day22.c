#include "DLList.h"

// 判断循环双链表是否对称
bool judgeSymmetry(DLList l)
{
    DLList p = l->next, q = l->prior;
    while (p != q)
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

int main()
{
    return 0;
}
