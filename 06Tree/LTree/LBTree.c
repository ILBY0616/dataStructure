#include "LBTree.h"

void initiateLBTree(LBTree* tree)
{
    type data;
    scanf("%c ", &data);
    if (data == '^')
    {
        *tree = NULL;
    }
    else
    {
        *tree = (LBTree)malloc(sizeof(Node));
        if (*tree != NULL)
        {
            (*tree)->data = data;
            initiateLBTree(&(*tree)->left);
            initiateLBTree(&(*tree)->right);
        }
    }
}

void preOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);
        preOrderByRecursion(tree->left);
        preOrderByRecursion(tree->right);
    }
}

void preOrderByStack(LBTree tree)
{
    int top = -1;
    LBTree node = tree;
    LBTree stack[size];
    while (node != NULL || top != -1)
    {
        while (node != NULL)
        {
            printf("%c", node->data);
            stack[++top] = node;
            node = node->left;
        }
        if (top != -1)
        {
            node = stack[top--];
            node = node->right;
        }
    }
}

void inOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        inOrderByRecursion(tree->left);
        printf("%c", tree->data);
        inOrderByRecursion(tree->right);
    }
}

void inOrderByStack(LBTree tree)
{
    int top = -1;
    LBTree stack[size];
    LBTree node = tree;
    while (node != NULL || top != -1)
    {
        while (node != NULL)
        {
            stack[++top] = node;
            node = node->left;
        }
        if (top != -1)
        {
            node = stack[top--];
            printf("%c", node->data);
            node = node->right;
        }
    }
}

void postOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        postOrderByRecursion(tree->left);
        postOrderByRecursion(tree->right);
        printf("%c", tree->data);
    }
}

void postOrderByStack(LBTree tree)
{
    int top = -1;
    int flagStack[size];
    LBTree nodeStack[size];
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

void printLevel(LBTree tree, int level)
{
    if (tree == NULL)
        return;
    if (level == 1)
    {
        printf("%c", tree->data);
    }
    else if (level > 1)
    {
        printLevel(tree->left, level - 1);
        printLevel(tree->right, level - 1);
    }
}

void levelOrderByRecursion(LBTree tree)
{
    int height = getHeightByRecursion(tree);
    for (int i = 1; i <= height; i++)
    {
        printLevel(tree, i);
    }
}

void levelOrderByQueue(LBTree tree)
{
    if (tree != NULL)
    {
        LBTree queue[size];
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

int getHeightByRecursion(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    int leftHeight = getHeightByRecursion(tree->left);
    int rightHeight = getHeightByRecursion(tree->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int getHeightByQueue(LBTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    LBTree queue[size];
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

void destroyLBTree(LBTree* tree)
{
    if (*tree != NULL)
    {
        destroyLBTree(&(*tree)->left);
        destroyLBTree(&(*tree)->right);
        free(*tree);
        *tree = NULL;
    }
}
