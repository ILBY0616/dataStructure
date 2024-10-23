#ifndef LSTACK_H
#define LSTACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define size 10
#define type int

typedef struct Node
{
    type data;
    struct Node* next;
} Node, *LStack;

// 初始化链栈
bool initiateLStack(LStack* s);
// 读栈
type getLStack(LStack s);
// 入栈
bool pushLStack(LStack* s, type data);
// 出栈
bool popLStack(LStack* s,type* data);
// 销毁链栈
void destroyLStack(LStack* s);

#endif
