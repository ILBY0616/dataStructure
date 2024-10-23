#ifndef DSLIST_H
#define DSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define newSize 10
#define type int

typedef struct Node
{
    type* data;
    int size, length;
} Node, *DSList;

// 初始化动态顺序表
bool initiateDSList(DSList* list);
// 查找动态顺序表数据
int selectDSList(DSList list, type data);
// 插入动态顺序表数据
bool insertDSList(DSList list, int location, type data);
// 删除动态顺序表数据
bool deleteDSList(DSList list, int location);
// 打印动态顺序表
bool printDSList(DSList list);
// 销毁动态顺序表
void destroyDSList(DSList* list);

#endif
