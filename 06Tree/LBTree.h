#ifndef LBTREE_H
#define LBTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left, *right;
} TreeNode, *LBTree;

// 先序递归创建链式二叉树
void createLBTree(LBTree* tree);
// 先序递归遍历链式二叉树
void preOrderByRecursion(LBTree tree);
// 先序非递归遍历链式二叉树
void preOrderByStack(LBTree tree);
// 中序递归遍历链式二叉树
void inOrderByRecursion(LBTree tree);
// 中序非递归遍历链式二叉树
void inOrderByStack(LBTree tree);
// 后序递归遍历链式二叉树
void postOrderByRecursion(LBTree tree);
// 后序非递归遍历链式二叉树
void postOrderByStack(LBTree tree);
// 层序递归遍历链式二叉树
void levelOrderByRecursion(LBTree tree);
// 层序非递归遍历链式二叉树
void levelOrderByQueue(LBTree tree);
// 打印层序
bool printLevel(LBTree tree, int level);
// 递归获取链式二叉树高度
int getHeightByRecursion(LBTree tree);
// 非递归获取链式二叉树高度
int getHeightByQueue(LBTree tree);
// 后序递归销毁链式二叉树
void destroyLBTree(LBTree* tree);

inline void createLBTree(LBTree* tree)
{
    char data;
    scanf("%c", &data);
    if (data == '^')
    {
        *tree = NULL;
    }
    else
    {
        *tree = (LBTree)malloc(sizeof(TreeNode));
        if (*tree != NULL)
        {
            (*tree)->data = data;
            createLBTree(&(*tree)->left);
            createLBTree(&(*tree)->right);
        }
    }
}

inline void preOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);
        preOrderByRecursion(tree->left);
        preOrderByRecursion(tree->right);
    }
}

inline void preOrderByStack(LBTree tree)
{
    int top = -1;
    LBTree stack[100];
    LBTree node = tree;
    while (node != NULL || top != -1)
    {
        // 一路向左，直到为空
        while (node != NULL)
        {
            printf("%c", node->data);
            stack[++top] = node;
            node = node->left;
        }
        // 退一向右，重新开始
        if (top != -1)
        {
            node = stack[top--];
            node = node->right;
        }
    }
}

inline void inOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        inOrderByRecursion(tree->left);
        printf("%c", tree->data);
        inOrderByRecursion(tree->right);
    }
}

inline void inOrderByStack(LBTree tree)
{
    int top = -1;
    LBTree stack[100];
    LBTree node = tree;
    while (node != NULL || top != -1)
    {
        // 一路向左，直到为空
        while (node != NULL)
        {
            stack[++top] = node;
            node = node->left;
        }
        // 退一向右，重新开始
        if (top != -1)
        {
            node = stack[top--];
            printf("%c", node->data);
            node = node->right;
        }
    }
}

inline void postOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        postOrderByRecursion(tree->left);
        postOrderByRecursion(tree->right);
        printf("%c", tree->data);
    }
}

inline void postOrderByStack(LBTree tree)
{
    int top = -1;
    LBTree node = tree;
    int flagStack[100];
    LBTree nodeStack[100];
    while (node != NULL || top != -1)
    {
        while (node != NULL)
        {
            nodeStack[++top] = node;
            flagStack[top] = 0;
            node = node->left;
        }
        node = nodeStack[top];
        if (flagStack[top--] == 0)
        {
            nodeStack[++top] = node;
            flagStack[top] = 1;
            node = node->right;
        }
        else
        {
            printf("%c", node->data);
            node = NULL;
        }
    }
}

inline bool printLevel(LBTree tree, int level)
{
    if (tree == NULL || level < 1)
    {
        return false;
    }
    if (level == 1)
    {
        printf("%c", tree->data);
    }
    else
    {
        printLevel(tree->left, level - 1);
        printLevel(tree->right, level - 1);
    }
    return true;
}

inline void levelOrderByRecursion(LBTree tree)
{
    int level = getHeightByRecursion(tree);
    for (int i = 1; i <= level; i++)
    {
        printLevel(tree, i);
    }
}

inline void levelOrderByQueue(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[100];
        int front = 0, rear = 0;
        // 入根队
        queue[rear++] = tree;
        // 出子队
        while (front != rear)
        {
            LBTree node = queue[front++];
            if (node != NULL)
            {
                printf("%c", node->data);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
    }
}

inline int getHeightByRecursion(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int leftHeight = getHeightByRecursion(tree->left);
    int rightHeight = getHeightByRecursion(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

inline int getHeightByQueue(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    LBTree queue[100];
    int front = -1, rear = -1, last = 0, heigth = 0;
    queue[++rear] = tree;
    while (front != rear)
    {
        LBTree node = queue[++front];
        if (node->left != NULL)
        {
            queue[++rear] = node->left;
        }
        if (node->right != NULL)
        {
            queue[++rear] = node->right;
        }
        if (front == last)
        {
            heigth++;
            last = rear;
        }
    }
    return heigth;
}

inline void destroyLBTree(LBTree* tree)
{
    if (*tree != NULL)
    {
        destroyLBTree(&(*tree)->left);
        destroyLBTree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}

#endif
