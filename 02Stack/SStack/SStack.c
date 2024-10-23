#include "SStack.h"

bool initiateSStack(SStack* s)
{
    if (*s != NULL)
    {
        return false;
    }
    *s = (SStack)malloc(sizeof(Node));
    if (*s != NULL)
    {
        (*s)->top = -1;
    }
    return true;;
}

type getSStack(SStack s)
{
    if (s == NULL || s->top == -1)
    {
        return -1;
    }
    return s->data[s->top];
}

bool pushSStack(SStack s, type data)
{
    if (s == NULL || s->top == size - 1)
    {
        return false;
    }
    s->data[++s->top] = data;
    return true;
}

bool popSStack(SStack s,type* data)
{
    if (s == NULL || s->top == -1)
    {
        *data = -1;
        return false;
    }
    *data = s->data[s->top--];
    return true;
}

void destroySStack(SStack* s)
{
    free(*s);
    *s = NULL;
}

// int main()
// {
//     int i = 0;
//     type data[size];
//     SStack s = NULL;
//     initiateSStack(&s);
//     while (scanf("%d ", &data[i]) == 1)
//     {
//         pushSStack(s, data[i]);
//         i++;
//     }
//     for (int j = 0; j < i; j++)
//     {
//         printf("%d ", getSStack(s));
//         popSStack(s, &data[i]);
//     }
//     destroySStack(&s);
//     return 0;
// }
