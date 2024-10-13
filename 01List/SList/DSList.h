#ifndef DSLIST_H
#define DSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define newSize 100
#define type int

typedef struct Node
{
    type* data;
    int size, length;
} Node, *List;

bool initiateNode(List* list);
int selectData(List list, type data);
bool insertData(List list, int location, type data);
bool deleteData(List list, int location);
void destroyNode(List* list);

#endif
