#ifndef SBTREE_H
#define SBTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode
{
    char value;
    bool sign;
} TreeNode;

typedef struct Tree
{
    TreeNode data[100];
    int size, length;
} Tree, *SBTree;

// 创建顺序二叉树
bool createSBTree(char* data, SBTree* tree);
// 销毁顺序二叉树
void destroySBTree(SBTree* tree);

inline bool createSBTree(char* data, SBTree* tree)
{
    if (*tree != NULL)
    {
        return false;
    }
    *tree = malloc(sizeof(Tree));
    if (*tree != NULL)
    {
        (*tree)->size = 100;
        (*tree)->length = 0;
        for (int i = 0; i < (*tree)->size; i++)
        {
            (*tree)->data[i].sign = false;
        }
        for (int i = 0; i < strlen(data); i++)
        {
            (*tree)->data[i].value = data[i];
            (*tree)->data[i].sign = true;
            (*tree)->length++;
        }
    }
    return true;
}

inline void destroySBTree(SBTree* tree)
{
    free(*tree);
    *tree = NULL;
}

#endif
