#include "SLList.h"

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
