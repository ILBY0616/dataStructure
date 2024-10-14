#include "SLList.h"

// 删除链表中所有值为x的元素
void deleteX(List* l,type x)
{
    List front = *l, rear = (*l)->next;
    while (rear != NULL)
    {
        if (rear->data == x)
        {
            front->next = rear->next;
            free(rear);
            rear = front->next;
        }
        else
        {
            front = rear;
            rear = rear->next;
        }
    }
}
