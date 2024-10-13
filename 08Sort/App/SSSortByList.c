#define type int
#include <stdlib.h>

typedef struct Node
{
    type data;
    struct Node* next;
} Node, *List;

void sortData(List* l, int length)
{
    List head = NULL, tail = NULL;
    for (int i = 0; i < length; i++)
    {
        List min = *l;
        while (min != NULL && min->next != NULL)
        {
            if (min->data < min->next->data)
            {
                min = min->next;
            }
        }
        if (min == *l)
        {
            head = min;
            tail = min;
            *l = (*l)->next;
        }else
        {

        }
    }
}

int main()
{

}
