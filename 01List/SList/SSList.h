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

bool initiateSSList(SSList* list);
int selectSSList(SSList list, type data);
bool insertSSList(SSList list, int location, type data);
bool deleteSSList(SSList list, int location);
bool printSSList(SSList list);
void destroySSList(SSList* list);

#endif
