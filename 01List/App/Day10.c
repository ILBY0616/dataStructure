#include "SLList.h"

// 头插法建立带头结点单链表
bool buildList(SLList* l)
{
    if (*l == NULL)
    {
        return false;
    }
    SLList p = NULL, q = NULL;
    type data;
    while (scanf("%d", &data) == 1)
    {
        q = malloc(sizeof(Node));
        if (q != NULL)
        {
            q->data = data;
            q->next = p;
            p = q;
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
