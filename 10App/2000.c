#include <LBTree.h>
#include <stdbool.h>
#include <stdio.h>

void preOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        printf("%c", tree->data);
        preOrderByRecursion(tree->left);
        preOrderByRecursion(tree->right);
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

void postOrderByRecursion(LBTree tree)
{
    if (tree != NULL)
    {
        postOrderByRecursion(tree->left);
        postOrderByRecursion(tree->right);
        printf("%c", tree->data);
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

int main()
{
    printf("Hello, World!\n");
    return 0;
}
