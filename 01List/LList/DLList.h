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
    struct Node *prior, *next;
} Node, *List;

bool initiateList(List* list);
List selectData(List list, type data);
bool insertData(List list, int location, type data);
bool deleteData(List list, int location);
int getLength(List list);
void destroyList(List* list);

#endif
