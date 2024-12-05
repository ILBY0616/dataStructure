#ifndef SSTACK_H
#define SSTACK_H

#include <stdbool.h>
#include <stdlib.h>

// 顺序栈
typedef struct SStack
{
    int data[100];
    int top, size;
}* SStack;

// 开辟顺序栈
bool initiateSStack(SStack* stack);
// 读栈
bool getSStack(SStack stack, int* data);
// 入栈
bool pushSStack(SStack stack, int data);
// 出栈
bool popSStack(SStack stack, int* data);
// 销毁顺序栈
void destroySStack(SStack* stack);

inline bool initiateSStack(SStack* stack)
{
    if (*stack != NULL)
    {
        return false;
    }
    *stack = (SStack)malloc(sizeof(struct SStack));
    if (*stack == NULL)
    {
        return false;
    }
    (*stack)->top = -1;
    (*stack)->size = 100;
    return true;;
}

inline bool getSStack(SStack stack, int* data)
{
    if (stack == NULL || stack->top == -1)
    {
        return false;
    }
    *data = stack->data[stack->top];
    return true;
}

inline bool pushSStack(SStack stack, int data)
{
    if (stack == NULL || stack->top == stack->size - 1)
    {
        return false;
    }
    stack->data[++stack->top] = data;
    return true;
}

inline bool popSStack(SStack stack, int* data)
{
    if (stack == NULL || stack->top == -1)
    {
        return false;
    }
    *data = stack->data[stack->top--];
    return true;
}

inline void destroySStack(SStack* stack)
{
    free(*stack);
    *stack = NULL;
}

#endif
