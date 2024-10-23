#ifndef LBTREE_H
#define LBTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define size 100
#define type char

typedef struct Node
{
    type data;
    struct Node *left, *right;
} Node, *LBTree;

// 递归先序建立树
void initiateLBTree(LBTree* tree);
// 递归先序遍历树
void preOrderByRecursion(LBTree tree);
// 非递归先序遍历树
void preOrderByStack(LBTree tree);
// 递归中序遍历树
void inOrderByRecursion(LBTree tree);
// 非递归中序遍历树
void inOrderByStack(LBTree tree);
// 递归后序遍历树
void postOrderByRecursion(LBTree tree);
// 非递归后序遍历树
void postOrderByStack(LBTree tree);
// 递归层序遍历树
void levelOrderByRecursion(LBTree tree);
// 非递归层序遍历树
void levelOrderByQueue(LBTree tree);
// 递归获取高度
int getHeightByRecursion(LBTree tree);
// 非递归获取高度
int getHeightByQueue(LBTree tree);
// 递归后序销毁树
void destroyLBTree(LBTree* tree);

#endif
