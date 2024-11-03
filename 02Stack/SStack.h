#ifndef SSTACK_H
#define SSTACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack
{
    int data[100];
    int top;
} Stack, *SStack;

// 开辟顺序栈
bool initiateSStack(SStack* stack);
// 读栈
int getSStack(SStack stack);
// 入栈
bool pushSStack(SStack stack, int data);
// 出栈
int popSStack(SStack stack);
// 销毁顺序栈
bool destroySStack(SStack* stack);

inline bool initiateSStack(SStack* stack)
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

inline int getSStack(SStack stack)
{
    if (stack == NULL || stack->top == -1)
    {
        return -1;
    }
    return stack->data[stack->top];
}

inline bool pushSStack(SStack stack, int data)
{
    if (stack == NULL || stack->top == 100 - 1)
    {
        return false;
    }
    stack->data[++stack->top] = data;
    return true;
}

inline int popSStack(SStack stack)
{
    if (stack == NULL || stack->top == -1)
    {
        return -1;
    }
    int data = stack->data[stack->top--];
    return data;
}

inline bool destroySStack(SStack* stack)
{
    if (*stack == NULL)
    {
        return false;
    }
    free(*stack);
    *stack = NULL;
    return true;
}

#endif
