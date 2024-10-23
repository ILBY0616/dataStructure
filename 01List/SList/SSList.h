#ifndef SSLIST_H
#define SSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define type int
#define size 100

typedef struct Node
{
    type data[size];
    int length;
} Node, *SSList;

// 初始化静态顺序表
bool initiateSSList(SSList* list);
// 查找静态顺序表数据
int selectSSList(SSList list, type data);
// 插入静态顺序表数据
bool insertSSList(SSList list, int location, type data);
// 删除静态顺序表数据
bool deleteSSList(SSList list, int location);
// 打印静态顺序表
bool printSSList(SSList list);
// 销毁静态顺序表
void destroySSList(SSList* list);

#endif
