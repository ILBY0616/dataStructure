#include "SLList.h"

// 尾插法建立单链表
void buildList(List* l)
{
    List head = NULL, tail = NULL;
    type data;
    while (scanf("%d", &data) == 1)
    {
        List node = malloc(sizeof(Node));
        if (node != NULL)
        {
            node->data = data;
            node->next = NULL;
            if (head == NULL || tail == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
    *l = head;
}
