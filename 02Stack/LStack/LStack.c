#include "LStack.h"

bool initiateLStack(LStack* s)
{
    if (*s != NULL)
    {
        return false;
    }
    *s = NULL;
    return true;
}

type getLStack(LStack s)
{
    if (s == NULL)
    {
        return -1;
    }
    return s->data;
}

bool pushLStack(LStack* s, type data)
{
    LStack node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = *s;
    *s = node;
    return true;;
}

bool popLStack(LStack* s, type* data)
{
    if (*s == NULL)
    {
        return false;
    }
    LStack node = *s;
    *data = node->data;
    *s = (*s)->next;
    free(node);
    return true;;
}

void destroyLStack(LStack* s)
{
    LStack node = *s;
    while (node != NULL)
    {
        *s = (*s)->next;
        free(node);
        node = *s;
    }
    *s = NULL;
}

// int main()
// {
//     int i = 0;
//     type data[size];
//     LStack s = NULL;
//     initiateLStack(&s);
//     while (scanf("%d ", &data[i]) == 1)
//     {
//         pushLStack(&s, data[i]);
//         i++;
//     }
//     for (int j = 0; j < i; j++)
//     {
//         printf("%d ", getLStack(s));
//         popLStack(&s, &data[i]);
//     }
//     destroyLStack(&s);
//     return 0;
// }
