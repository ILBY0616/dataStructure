#ifndef TBTREE_H
#define TBTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode
{
    char data;
    bool lTag, rTag;
    struct TreeNode *lChild, *rChild;
} TreeNode, *TBTree;

// 创建线索二叉树
void createTBTree(TBTree tree);
// 先序遍历线索二叉树
bool preOrderTBTree(TBTree tree);
// 中序遍历线索二叉树
bool inOrderTBTree(TBTree tree);
// 后序遍历线索二叉树
bool postOrderTBTree(TBTree tree);
// 层序遍历线索二叉树
bool levelOrderTBTree(TBTree tree);
// 获取线索二叉树高度
int getHeightTBTree(TBTree tree);
// 销毁线索二叉树
void destroyTBTree(TBTree* tree);


inline bool inOrderTBTree(TBTree tree)
{
    if (tree == NULL)
    {
        return false;
    }
    TBTree pointer = tree->lChild;
    while (pointer != tree)
    {
        // 左指针为孩子就一路向左
        while (pointer->lTag == false)
        {
            pointer = pointer->lChild;
        }
        printf("%c ", pointer->data);
        // 右指针为线索就逐个输出
        while (pointer->rTag == true && pointer->rChild != tree)
        {
            pointer = pointer->rChild;
            printf("%c ", pointer->data);
        }
        pointer = pointer->rChild;
    }
    return true;
}

#endif
