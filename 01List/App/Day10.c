#include "SLList.h"

// 头插法建立单链表
void buildList(List* l)
{
    List head = NULL;
    type data;
    while (scanf("%d", &data) == 1)
    {
        List node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data;
            node->next = head;
            head = node;
        }
    }
    *l = head;
}
