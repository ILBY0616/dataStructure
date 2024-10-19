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

bool initiateDSList(DSList* list);
int selectDSList(DSList list, type data);
bool insertDSList(DSList list, int location, type data);
bool deleteDSList(DSList list, int location);
bool printDSList(DSList list);
void destroyDSList(DSList* list);

#endif
