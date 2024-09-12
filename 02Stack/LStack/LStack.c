#include <stdlib.h>
#include <stdio.h>

#define size 10
#define type int

typedef struct Node
{
    type data;
    struct Node* next;;
} Node;

typedef Node* LStack;

LStack initiateStack(LStack s)
{
    if (s != NULL)
    {
        free(s);
        s = NULL;
    }
    return s;
}

type getTop(LStack s)
{
    if (s == NULL)
    {
        return -1;
    }
    return s->data;
}

LStack pushData(LStack s, type data)
{
    LStack temp = malloc(sizeof(Node));
    if (temp != NULL)
    {
        temp->data = data;
        temp->next = s;
        s = temp;
    }
    return s;
}

LStack popData(LStack s, type* data)
{
    if (s != NULL)
    {
        LStack temp = s;
        *data = s->data;
        s = s->next;
        free(temp);
    }
    return s;
}

void destroyStack(LStack s)
{
    LStack temp = s;
    while (temp != NULL)
    {
        s = s->next;
        free(temp);
        temp = s;
    }
}

int main()
{
    int i = 0;
    type data[size];
    LStack s = NULL;
    s = initiateStack(s);
    while (scanf("%d ", &data[i]) == 1)
    {
        s = pushData(s, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getTop(s));
        s = popData(s, &data[i]);
    }
    destroyStack(s);
    return 0;
}
