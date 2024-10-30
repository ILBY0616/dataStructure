#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define type char
#define size 100

typedef struct Node
{
    type data;
    struct Node *left, *right;
} Node, *LBTree;

void initiateLBTree(LBTree* tree);
void preOrderByRecursion(LBTree tree);
void preOrderByStack(LBTree tree);
void inOrderByRecursion(LBTree tree);
void inOrderByStack(LBTree tree);
void postOrderByRecursion(LBTree tree);
void postOrderByStack(LBTree tree);
void levelOrderByRecursion(LBTree tree);
void levelOrderByQueue(LBTree tree);
int getHeightByRecursion(LBTree tree);
int getHeightByQueue(LBTree tree);
void destroyLBTree(LBTree* tree);

int main()
{
    LBTree tree = NULL;
    initiateLBTree(&tree);
    printf("先序遍历(递归)：\n");
    preOrderByRecursion(tree);
    printf("\n");
    printf("先序遍历(非递归)：\n");
    preOrderByStack(tree);
    printf("\n");
    printf("中序遍历(递归)：\n");
    inOrderByRecursion(tree);
    printf("\n");
    printf("中序遍历(非递归)：\n");
    inOrderByStack(tree);
    printf("\n");
    printf("后序遍历(递归)：\n");
    postOrderByRecursion(tree);
    printf("\n");
    printf("后序遍历(非递归)：\n");
    postOrderByStack(tree);
    printf("\n");
    printf("层序遍历(递归)：\n");
    levelOrderByRecursion(tree);
    printf("\n");
    printf("层序遍历(非递归)：\n");
    levelOrderByQueue(tree);
    printf("\n");
    printf("树的高度(递归)：%d\n", getHeightByRecursion(tree));
    printf("树的高度(非递归)：%d\n", getHeightByQueue(tree));
    destroyLBTree(&tree);
    return 0;
}

void initiateLBTree(LBTree* tree)
{
    type data;
    scanf("%c", &data);
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
    LBTree stack[size];
    while (tree != NULL || top != -1)
    {
        // 一路向左，直到为空
        while (tree != NULL)
        {
            printf("%c", tree->data);
            stack[++top] = tree;
            tree = tree->left;
        }
        // 退一向右，重新开始
        if (top != -1)
        {
            tree = stack[top--];
            tree = tree->right;
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
    while (tree != NULL || top != -1)
    {
        // 一路向左，直到为空
        while (tree != NULL)
        {
            stack[++top] = tree;
            tree = tree->left;
        }
        // 退一向右，重新开始
        if (top != -1)
        {
            tree = stack[top--];
            printf("%c", tree->data);
            tree = tree->right;
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
    while (tree != NULL || top != -1)
    {
        while (tree != NULL)
        {
            nodeStack[++top] = tree;
            flagStack[top] = 0;
            tree = tree->left;
        }
        tree = nodeStack[top];
        if (flagStack[top--] == 0)
        {
            nodeStack[++top] = tree;
            flagStack[top] = 1;
            tree = tree->right;
        }
        else
        {
            printf("%c", tree->data);
            tree = NULL;
        }
    }
}

bool printLevel(LBTree tree, int level)
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

void levelOrderByRecursion(LBTree tree)
{
    int level = getHeightByRecursion(tree);
    for (int i = 1; i <= level; i++)
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
