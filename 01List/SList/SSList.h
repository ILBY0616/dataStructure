#ifndef SSLIST_H
#define SSLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define type int
#define size 10

typedef struct Node
{
    type data[size];
    int length;
} Node, *List;

bool initiateNode(List* list);
int selectData(List list, type data);
bool insertData(List list, int location, type data);
bool deleteData(List list, int location);
void destroyNode(List* list);

#endif
