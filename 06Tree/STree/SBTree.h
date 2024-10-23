#ifndef SBTREE_H
#define SBTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define type int
#define size 100

typedef struct Node
{
    type value;
    bool sign;
} Node;

typedef struct Tree
{
    Node data[size];
    int length;
} SBTree;

#endif
