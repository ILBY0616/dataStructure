#include "SLList.h"

// 找带头节点单链表倒数第k个位置的数据
int findBottomKth(SLList l, int k)
{
    SLList p = NULL, q = l;
    while (q != NULL && k != 0)
    {
        q = q->next;
        k--;
    }
    if (q == NULL || k != 0)
    {
        return 0;
    }
    p = l->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    printf("%d", p->data);
    return 1;
}

int main()
{
    return 0;
}
