#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define size 10
#define type int

typedef struct Stack
{
    type data[size];
    int top;
} Stack;

typedef Stack* SStack;

SStack initiateStack(SStack s)
{
    s = (SStack)malloc(sizeof(Stack));
    if (s != NULL)
    {
        s->top = -1;
    }
    return s;
}

type getTop(SStack s)
{
    if (s == NULL || s->top == -1)
    {
        return -1;
    }
    return s->data[s->top];
}

bool pushData(SStack s, type data)
{
    if (s == NULL || s->top == size - 1)
    {
        return false;
    }
    s->data[++s->top] = data;
    return true;
}

type popData(SStack s)
{
    if (s == NULL || s->top == -1)
    {
        return -1;
    }
    return s->data[s->top--];
}

void destroyStack(SStack s)
{
    free(s);
}

int main()
{
    int i = 0;
    type data[size];
    SStack s = NULL;
    s = initiateStack(s);
    while (scanf("%d ", &data[i]) == 1)
    {
        pushData(s, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getTop(s));
        popData(s);
    }
    destroyStack(s);
    return 0;
}
