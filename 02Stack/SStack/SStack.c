#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define size 10
#define type int

typedef struct Stack
{
    type data[size];
    int top;
} Stack, *SStack;

bool initiateSStack(SStack* stack);
type getSStack(SStack stack);
bool pushSStack(SStack stack, type data);
type popSStack(SStack stack);
bool destroySStack(SStack* stack);

int main()
{
    int i = 0;
    type data[size];
    SStack stack = NULL;
    initiateSStack(&stack);
    while (scanf("%d ", &data[i]) == 1)
    {
        pushSStack(stack, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getSStack(stack));
        data[i] = popSStack(stack);
    }
    destroySStack(&stack);
    return 0;
}

bool initiateSStack(SStack* stack)
{
    if (*stack != NULL)
    {
        return false;
    }
    *stack = (SStack)malloc(sizeof(Stack));
    if (*stack != NULL)
    {
        (*stack)->top = -1;
    }
    return true;;
}

type getSStack(SStack stack)
{
    if (stack == NULL || stack->top == -1)
    {
        return -1;
    }
    return stack->data[stack->top];
}

bool pushSStack(SStack stack, type data)
{
    if (stack == NULL || stack->top == size - 1)
    {
        return false;
    }
    stack->data[++stack->top] = data;
    return true;
}

type popSStack(SStack stack)
{
    if (stack == NULL || stack->top == -1)
    {
        return -1;
    }
    type data = stack->data[stack->top--];
    return data;
}

bool destroySStack(SStack* stack)
{
    if (*stack == NULL)
    {
        return false;
    }
    free(*stack);
    *stack = NULL;
    return true;
}
