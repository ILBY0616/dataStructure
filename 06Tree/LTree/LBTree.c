#include <stdlib.h>
#include <stdio.h>

#define size 100
#define type char

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
    // 初始化树
    printf("请依次输入树节点数据(输入'^'表示该节点为空)：\n");
    initiateLBTree(&tree);
    // 先序遍历
    printf("先序遍历(递归)：\n");
    preOrderByRecursion(tree);
    printf("\n");
    printf("先序遍历(非递归)：\n");
    preOrderByStack(tree);
    printf("\n");
    // 中序遍历
    printf("中序遍历(递归)：\n");
    inOrderByRecursion(tree);
    printf("\n");
    printf("中序遍历(非递归)：\n");
    inOrderByStack(tree);
    printf("\n");
    // 后序遍历
    printf("后序遍历(递归)：\n");
    postOrderByRecursion(tree);
    printf("\n");
    printf("后序遍历(非递归)：\n");
    postOrderByStack(tree);
    printf("\n");
    // 层序遍历
    printf("层序遍历(递归)：\n");
    levelOrderByRecursion(tree);
    printf("\n");
    printf("层序遍历(队列)：\n");
    levelOrderByQueue(tree);
    printf("\n");
    // 获取树的高度
    printf("树的高度(递归)：%d\n", getHeightByRecursion(tree));
    printf("树的高度(队列)：%d\n", getHeightByQueue(tree));
    // 销毁树
    destroyLBTree(&tree);
    if (tree == NULL)
    {
        printf("树已成功销毁。\n");
    }
    return 0;
}

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
