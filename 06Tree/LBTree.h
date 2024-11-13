#ifndef LBTREE_H
#define LBTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *left, *right;
} TreeNode, *LBTree;

// 先序创建链式二叉树
void createLBTree(LBTree* tree);
// 先序遍历链式二叉树
void preOrderLBTree(LBTree tree);
// 中序遍历链式二叉树
void inOrderLBTree(LBTree tree);
// 后序遍历链式二叉树
void postOrderLBTree(LBTree tree);
// 层序遍历链式二叉树
void levelOrderLBTree(LBTree tree);
// 获取链式二叉树高度
int getHeightLBTree(LBTree tree);
// 获取链式二叉树宽度
int getWidthLBTree(LBTree tree);
// 后序销毁链式二叉树
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
        LBTree node = NULL;
        while (node == NULL)
        {
            node = (LBTree)malloc(sizeof(TreeNode));
            if (node != NULL)
            {
                *tree = node;
                (*tree)->data = data;
                createLBTree(&(*tree)->left);
                createLBTree(&(*tree)->right);
            }
        }
    }
}

inline void preOrderLBTree(LBTree tree)
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

inline void inOrderLBTree(LBTree tree)
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

inline void postOrderLBTree(LBTree tree)
{
    int top = -1;
    int flagStack[100];
    LBTree nodeStack[100];
    LBTree node = tree;
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

inline void levelOrderLBTree(LBTree tree)
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

inline int getHeightLBTree(LBTree tree)
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

inline int getWidthLBTree(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    LBTree queue[100];
    int front = -1, rear = -1, last = 0, width = 0;
    queue[++rear] = tree;
    while (front != rear)
    {
        if (rear == last)
        {
            width = rear - front > width ? rear - front : width;
        }
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
            last = rear;
        }
    }
    return width;
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
