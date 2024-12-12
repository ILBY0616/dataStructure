#ifndef LBTREE_H
#define LBTREE_H

#include <stdlib.h>
#include <stdio.h>

// 链式二叉树结点
typedef struct LBTreeNode
{
    char data;
    struct LBTreeNode *left, *right;
}* LBTree;

// 先序建造链式二叉树
void buildLBTree(LBTree* tree);
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

inline void buildLBTree(LBTree* tree)
{
    char data;
    scanf(" %c", &data);
    if (data == '^')
    {
        *tree = NULL;
    }
    else
    {
        LBTree node = malloc(sizeof(struct LBTreeNode));
        if (node != NULL)
        {
            *tree = node;
            (*tree)->data = data;
            buildLBTree(&(*tree)->left);
            buildLBTree(&(*tree)->right);
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
        // node非空，入栈向左
        if (node != NULL)
        {
            printf("%c", node->data);
            stack[++top] = node;
            node = node->left;
        }
        // node为空，出栈向右
        else
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
        // node非空，入栈向左
        if (node != NULL)
        {
            stack[++top] = node;
            node = node->left;
        }
        // node为空，出栈向右
        else
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
    LBTree stack[100];
    LBTree node = tree;
    LBTree visited = NULL;
    while (node != NULL || top != -1)
    {
        // node非空，入栈向左
        if (node != NULL)
        {
            stack[++top] = node;
            node = node->left;
        }
        // node为空，读栈看右
        else
        {
            node = stack[top];
            // 有右未访，便要访右
            if (node->right != NULL && node->right != visited)
            {
                node = node->right;
            }
            // 无右已访，出栈标记
            else
            {
                stack[top--];
                printf("%c", node->data);
                visited = node;
                node = NULL;
            }
        }
    }
}

inline void levelOrderLBTree(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[100];
        int front = -1, rear = -1;
        // 入队
        queue[++rear] = tree;
        while (front != rear)
        {
            // 出队
            LBTree node = queue[++front];
            printf("%c", node->data);
            if (node->left != NULL)
            {
                queue[++rear] = node->left;
            }
            if (node->right != NULL)
            {
                queue[++rear] = node->right;
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
