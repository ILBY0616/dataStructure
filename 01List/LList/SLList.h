#ifndef SLLIST_H
#define SLLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define type int

typedef struct Node
{
    type data;
    struct Node* next;
} Node, *SLList;

// 初始化单链表头结点
bool initiateSLList(SLList* list);
// 头插法建立非循环单链表
bool buildSLListByHead(type data[], int length, SLList* list);
// 尾插法建立非循环单链表
bool buildSLListByTail(type data[], int length, SLList* list);
// 查找非循环单链表数据
SLList selectSLList(SLList list, type data);
// 插入非循环单链表数据
bool insertSLList(SLList list, int location, type data);
// 删除非循环单链表数据
bool deleteSLList(SLList list, int location);
// 打印非循环单链表
bool printSLList(SLList list);
// 获取非循环单链表长度
int getLengthSLList(SLList list);
// 销毁非循环单链表
void destroySLList(SLList* list);

#endif
