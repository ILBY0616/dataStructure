#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define type char
#define size 100

typedef struct Node
{
    type value;
    bool sign;
} Node;

typedef struct Tree
{
    Node data[size];
    int length;
} Tree, *SBTree;

bool initiateSBTree(SBTree* tree);
bool preOrder(SBTree tree);
bool inOrder(SBTree tree);
bool postOrder(SBTree tree);
bool levelOrder(SBTree tree);
int getHeight(SBTree tree);
bool destroySBTree(SBTree* tree);

int main()
{
    SBTree tree = NULL;
    initiateSBTree(&tree);
    preOrder(tree);
    inOrder(tree);
    postOrder(tree);
    levelOrder(tree);
    printf("%d\n", getHeight(tree));
    destroySBTree(&tree);
    return 0;
}

bool initiateSBTree(SBTree* tree)
{
    if (*tree != NULL)
    {
        return false;
    }
    *tree = malloc(sizeof(Tree));
    (*tree)->length = 0;
    for (int i = 0; i < size; i++)
    {
        (*tree)->data[i].sign = false;
    }
    for (int i = 1; i < size; i++)
    {
        type value;
        scanf("%d", &value);
        if (value == -1)
        {
            return true;
        }
        (*tree)->data[i].value = value;
        (*tree)->data[i].sign = true;
        (*tree)->length++;
    }
    return true;
}

bool preOrder(SBTree tree)
{
    if (tree == NULL)
    {
        return false;
    }
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
    return true;
}

bool inOrder(SBTree tree)
{
    if (tree == NULL)
    {
        return false;
    }
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
    return true;
}

bool postOrder(SBTree tree)
{
    if (tree == NULL)
    {
        return false;
    }
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
    return true;
}

bool levelOrder(SBTree tree)
{
    if (tree == NULL)
    {
        return false;
    }
    for (int i = 0; i < tree->length; i++)
    {
        if (tree->data[i].sign)
        {
            printf("%d ", tree->data[i].value);
        }
    }
    printf("\n");
    return true;
}

int getHeight(SBTree tree)
{
    int height = 0;
    int i = tree->length - 1;
    while (i >= 0 && !tree->data[i].sign)
    {
        i--;
    }
    while (i >= (1 << height) - 1)
    {
        height++;
    }
    return height;
}

bool destroySBTree(SBTree* tree)
{
    if (*tree == NULL)
    {
        return false;
    }
    free(*tree);
    *tree = NULL;
    return true;
}
