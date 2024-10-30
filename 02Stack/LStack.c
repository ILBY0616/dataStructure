#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type int
#define size 10

typedef struct Node
{
    type data;
    struct Node* next;
} Node, *LStack;

bool initiateLStack(LStack* stack);
type getLStack(LStack stack);
bool pushLStack(LStack* stack, type data);
type popLStack(LStack* stack);
bool destroyLStack(LStack* stack);

int main()
{
    int i = 0;
    type data[size];
    LStack stack = NULL;
    initiateLStack(&stack);
    while (scanf("%d ", &data[i]) == 1)
    {
        pushLStack(&stack, data[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ", getLStack(stack));
        data[i] = popLStack(&stack);
    }
    destroyLStack(&stack);
    return 0;
}

bool initiateLStack(LStack* stack)
{
    if (*stack != NULL)
    {
        return false;
    }
    *stack = NULL;
    return true;
}

type getLStack(LStack stack)
{
    if (stack == NULL)
    {
        return -1;
    }
    return stack->data;
}

bool pushLStack(LStack* stack, type data)
{
    LStack node = malloc(sizeof(Node));
    if (node == NULL)
    {
        return false;
    }
    node->data = data;
    node->next = *stack;
    *stack = node;
    return true;;
}

type popLStack(LStack* stack)
{
    if (*stack == NULL)
    {
        return false;
    }
    LStack node = *stack;
    type data = node->data;
    *stack = (*stack)->next;
    free(node);
    return data;
}

bool destroyLStack(LStack* stack)
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
