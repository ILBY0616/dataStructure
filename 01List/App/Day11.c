#include "SLList.h"

// 尾插法建立带头结点单链表
bool buildList(SLList* l)
{
    if (*l == NULL)
    {
        return false;
    }
    SLList p = NULL, q = NULL, r = NULL;
    type data;
    while (scanf("%d", &data) == 1)
    {
        q = malloc(sizeof(Node));
        if (q != NULL)
        {
            q->data = data;
            q->next = NULL;
            if (p == NULL || r == NULL)
            {
                p = q;
                r = q;
            }
            else
            {
                r->next = q;
                r = r->next;
            }
        }
    }
    (*l)->next = p;
    return true;
}

int main()
{
    SLList l = NULL;
    initiateSLList(&l);
    buildList(&l);
    printSLList(l);
    destroySLList(&l);
    return 0;
}
