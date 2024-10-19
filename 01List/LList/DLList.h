#ifndef DLLIST_H
#define DLLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define type int

typedef struct Node
{
    type data;
    struct Node* prior;
    struct Node* next;
} Node, *DLList;

// 初始化双链表头结点
bool initiateDLList(DLList* list);
// 头插法建立非循环双链表
bool buildDLListByHead(type data[], int length, DLList* list);
// 尾插法建立非循环双链表
bool buildDLListByTail(type data[], int length, DLList* list);
// 头插法建立循环双链表
bool buildCycleDLListByHead(type data[], int length, DLList* list);
// 尾插法建立循环双链表
bool buildCycleDLListByTail(type data[], int length, DLList* list);
// 查找非循环双链表数据
DLList selectDLList(DLList list, type data);
// 插入非循环双链表数据
bool insertDLList(DLList list, int location, type data);
// 删除非循环双链表数据
bool deleteDLList(DLList list, int location);
// 打印非循环双链表
bool printDLList(DLList list);
// 获取非循环双链表长度
int getLengthDLList(DLList list);
// 销毁非循环双链表
void destroyDLList(DLList* list);

#endif
