#ifndef LSTACK_H
#define LSTACK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct StackNode
{
    int data;
    struct StackNode* next;
} StackNode, *LStack;

// 开辟链栈
bool initiateLStack(LStack* stack);
// 读栈
int getLStack(LStack stack);
// 入栈
bool pushLStack(LStack* stack, int data);
// 出栈
int popLStack(LStack* stack);
// 销毁链栈
bool destroyLStack(LStack* stack);

inline bool initiateLStack(LStack* stack)
{
    if (*stack != NULL)
    {
        return false;
    }
    *stack = NULL;
    return true;
}

inline int getLStack(LStack stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return stack->data;
}

inline bool pushLStack(LStack* stack, int data)
{
    LStack node = malloc(sizeof(StackNode));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = *stack;
    *stack = node;
    return true;;
}

inline int popLStack(LStack* stack)
{
    if (*stack == NULL)
    {
        return false;
    }
    LStack node = *stack;
    int data = node->data;
    *stack = (*stack)->next;
    free(node);
    return data;
}

inline bool destroyLStack(LStack* stack)
{
    if (*stack == NULL)
    {
        return false;
    }
    LStack node = *stack;
    while (node != NULL)
    {
        *stack = (*stack)->next;
        free(node);
        node = *stack;
    }
    *stack = NULL;
    return true;
}

#endif
