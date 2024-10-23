#ifndef SSTACK_H
#define SSTACK_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define size 10
#define type int

typedef struct Node
{
    type data[size];
    int top;
} Node, *SStack;

// 初始化顺序栈
bool initiateSStack(SStack* s);
// 读栈
type getSStack(SStack s);
// 入栈
bool pushSStack(SStack s, type data);
// 出栈
bool popSStack(SStack s,type* data);
// 销毁顺序栈
void destroySStack(SStack* s);

#endif
