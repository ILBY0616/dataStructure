#include <stdio.h>
#include <stdlib.h>

#define size 100
#define type char

typedef struct Node
{
    type data;
    struct Node *left, *right;
} Node;

typedef Node* BTree;

// 先序建立树
BTree initiateTree(BTree t)
{
    type data;
    scanf("%c", &data);
    if (data == '^')
    {
        t = NULL;
    }
    else
    {
        t = (BTree)malloc(sizeof(Node));
        if (t != NULL)
        {
            t->data = data;
            t->left = NULL;
            t->right = NULL;
            t->left = initiateTree(t->left);
            t->right = initiateTree(t->right);
        }
    }
    return t;
}

// 先序遍历树
void preOrder(BTree t)
{
    if (t != NULL)
    {
        printf("%c", t->data);
        preOrder(t->left);
        preOrder(t->right);
    }
}

// 中序遍历树
void inOrder(BTree t)
{
    if (t != NULL)
    {
        inOrder(t->left);
        printf("%c", t->data);
        inOrder(t->right);
    }
}

// 后序遍历树
void postOrder(BTree t)
{
    if (t != NULL)
    {
        postOrder(t->left);
        postOrder(t->right);
        printf("%c", t->data);
    }
}

// 层序遍历树
void levelOrder(BTree t)
{
    if (t != NULL)
    {
        BTree queue[size];
        int front = 0, rear = 0;
        // 入根队
        queue[rear++] = t;
        // 出子队
        while (front != rear)
        {
            BTree node = queue[front++];
            if (node != NULL)
            {
                printf("%c", node->data);
                queue[rear++] = node->left;
                queue[rear++] = node->right;
            }
        }
    }
}

// 后序销毁树
void destroyTree(BTree t)
{
    if (t != NULL)
    {
        if (t->left)
        {
            destroyTree(t->left);
        }
        if (t->right)
        {
            destroyTree(t->right);
        }
        free(t);
        t = NULL;
    }
}

// ab^^c^^
int main()
{
    BTree t = NULL;
    t = initiateTree(t);
    levelOrder(t);
    printf("\n");
    preOrder(t);
    printf("\n");
    inOrder(t);
    printf("\n");
    postOrder(t);
    destroyTree(t);
    return 0;
}
