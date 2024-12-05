#ifndef LSTACK_H
#define LSTACK_H

#include <stdbool.h>
#include <stdlib.h>

// 链栈
typedef struct LStackNode
{
    int data;
    struct LStackNode* next;
}* LStack;

// 开辟链栈
bool initiateLStack(LStack* stack);
// 读栈
bool getLStack(LStack stack, int* data);
// 入栈
bool pushLStack(LStack* stack, int data);
// 出栈
bool popLStack(LStack* stack, int* data);
// 销毁链栈
void destroyLStack(LStack* stack);

inline bool initiateLStack(LStack* stack)
{
    if (*stack != NULL)
    {
        return false;
    }
    *stack = NULL;
    return true;
}

inline bool getLStack(LStack stack, int* data)
{
    if (stack == NULL)
    {
        return false;
    }
    *data = stack->data;
    return true;
}

inline bool pushLStack(LStack* stack, int data)
{
    LStack node = malloc(sizeof(struct LStackNode));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = *stack;
    *stack = node;
    return true;;
}

inline bool popLStack(LStack* stack, int* data)
{
    if (*stack == NULL)
    {
        return false;
    }
    LStack node = *stack;
    *data = node->data;
    *stack = (*stack)->next;
    free(node);
    return true;
}

inline void destroyLStack(LStack* stack)
{
    while (*stack != NULL)
    {
        LStack node = *stack;
        *stack = (*stack)->next;
        free(node);
    }
}

#endif
