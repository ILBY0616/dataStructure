#include "SLList.h"

// 去除m长度无序单链表绝对值相同且小于n的元素
void findBottomKth(SLList* l, int n)
{
    int data[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = 0;
    }
    SLList p = *l, q = (*l)->next;
    while (q != NULL)
    {
        int key = q->data > 0 ? q->data : -q->data;
        if (data[key] == 0)
        {
            data[key] = 1;
            p = p->next;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

int main()
{
    return 0;
}
